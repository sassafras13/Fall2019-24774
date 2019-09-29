clear;
clc;
quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);

measured_hardware = load('measured_angles_hardware');

size(measured_hardware.angles);
N = length(measured_hardware.angles);
t = measured_hardware.angles(1,:);
dt = measured_hardware.angles(1,2)-measured_hardware.angles(1,1);

y_pitch_hardware = measured_hardware.angles(2,:);
y_yaw_hardware = measured_hardware.angles(3,:);

Y_hardware = [y_pitch_hardware' y_yaw_hardware'];

% Rw = diag([1 1]); %Process noise covarience
% Rv = diag([1 1]); %Sensor noise covarience
% P0 = diag([1 1 1 1]);

Rw = diag([50 50]); %Process noise covarience
Rv = diag([10^-2 10^-2]); %Sensor noise covarience
P0 = diag([50 50 10 10]);

x0 = [0;
      0;
      0;
      0;];
X_array=[];
Y_array=[];
Xk_prev = x0;
P_posterior = P0;


for i=1:N
    Y_array=[Y_array Y_hardware(i,:)'];
    
    % Kalman Prediction
    %x_prior = A*Xk_prev+B*u;
    P_prior = A*P_posterior*A' + B*Rw*B';
    
    % Kalman update
    K = P_prior*C'*inv(C*P_prior*C' + Rv);
    Xk = Xk_prev + K*(Y_hardware(i,:)'-C*Xk_prev);
    
    P_posterior = P_prior - K*C*P_prior;
    
    X_array = [X_array Xk];

    % For the next iteration
    Xk_prev = Xk;
    
end

figure;
plot(t,Y_array(1,:));
hold on 
plot(t,Y_array(2,:));
title('Measured Angles');
legend('Pitch','Yaw');

figure;
plot(t,X_array(1,:));
hold on 
plot(t,X_array(2,:));

figure;
plot(t, X_array(3,:)');
hold on 
plot(t,X_array(4,:));