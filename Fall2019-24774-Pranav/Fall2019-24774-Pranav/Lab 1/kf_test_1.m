clear;
clc;
quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);

%Rw = diag([50 50]); %Process noise covarience
%Rv = diag([10^-2 10^-2]); %Sensor noise covarience
%P0 = diag([50 50 10 10]);


% [kalmf,L,P,M] = kalman(aero_sys,Rw,Rv);

measured_hardware = load('measured_angles_hardware');
input_hardware = load('measured_voltage_hardware');

size(measured_hardware.angles);
size(input_hardware.volts);

y_pitch_hardware = measured_hardware.angles(2,:);
y_yaw_hardware = measured_hardware.angles(3,:);

u_pitch_hardware = input_hardware.volts(2,:);
u_yaw_hardware = input_hardware.volts(3,:);

Y_hardware = [y_pitch_hardware' y_yaw_hardware'];
u_hardware = [u_pitch_hardware' u_yaw_hardware'];

N = length(Y_hardware);
Y_hardware(2000,:);

Rw=diag([0.00001 0.00001]);
Rv=0;
P0=diag([1 1 1 1]);

x0 = [0;
      0;
      0;
      0;];
X_array=[];
Y_array=[];
Xk_prev = x0;
P_posterior = P0;

for i=1:length(Y_hardware)
    
    Y_array=[Y_array Y_hardware(i,:)'];
    
    % Kalman Prediction
    %x_prior = A*Xk_prev+B*u_hardware(i,:)';
    P_prior = A*P_posterior*A' + B*Rw*B';
    
    % Kalman update
    K = P_prior*C'*inv(C*P_prior*C' + Rv);
    P_posterior = P_prior - K*C*P_prior;
    
    Xk = Xk_prev + K*(Y_hardware(i,:)'-C*Xk_prev);
    X_array = [X_array Xk];

    % For the next iteration
    Xk_prev = Xk;
end
K;
size(X_array)
size(Y_array)
%t = linspace(0,60,length(Y_hardware));
t = measured_hardware.angles(1,:);
dt = t(1,2)-t(1,1);
% figure;
% plot(t,Y_array(2,:));
% figure;
% plot(t,X_array(2,:));

Y_array = Y_array';


Velocity_pitch_1 = Y_array(2:N,1);
Velocity_pitch_2 = Y_array(1:N-1,1);
Velocity_pitch = (Velocity_pitch_1 - Velocity_pitch_2)/dt;

Velocity_yaw_1 = Y_array(2:N,2);
Velocity_yaw_2 = Y_array(1:N-1,2);
Velocity_yaw = (Velocity_yaw_1 - Velocity_yaw_2)/dt;

Inst_Velocity = [Velocity_pitch Velocity_yaw];

Inst_Velocity_LPF = lowpass(Inst_Velocity,16,500);
size(Velocity_pitch);

t1 = linspace(0,60,length(Y_hardware)-1);
figure;
% plot(Inst_Velocity_LPF(:,1),Inst_Velocity_LPF(:,2));
plot(t1,Inst_Velocity_LPF(:,1));
% hold on
% plot(t, X_array(3,:)');
% 
% figure;
% plot(t1,Inst_Velocity_LPF(:,2));
% hold on 
% plot(t,X_array(4,:));

% x1 = x([3,1:end-1]); x2 = x([2:end,end-2]);
% y1 = y([3,1:end-1]); y2 = y([2:end,end-2]);
% dydx = ((y2-y).*(x-x1).^2+(y-y1).*(x2-x).^2)./((x2-x).*(x-x1).*(x2-x1));

Y_array = Y_array';

pitch = Y_array(1,:);
yaw = Y_array(2,:);

t1 = t([3,1:end-1]); t2 = t([2:end,end-2]);
y1 = pitch([3,1:end-1]); y2 = pitch([2:end,end-2]);
dydx = ((y2-pitch).*(t-t1).^2+(pitch-y1).*(t2-t).^2)./((t2-t).*(t-t1).*(t2-t1));

dydx_LPF = lowpass(dydx,16,500);
figure;
plot(t,dydx_LPF)
