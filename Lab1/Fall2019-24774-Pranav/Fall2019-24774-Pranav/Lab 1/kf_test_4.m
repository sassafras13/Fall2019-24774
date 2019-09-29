clear;
clc;
quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);

s = tf('s');
Diff_LPF = s/(s/50 +1); %Differentiation and LPF

%Loading the hardware measured angle values
%measured_hardware = load('measured_angles_hardware');
measured_hardware = load('measured');

size(measured_hardware.angles);
N = length(measured_hardware.angles);
t = measured_hardware.angles(1,:);
dt = measured_hardware.angles(1,2)-measured_hardware.angles(1,1);

y_pitch_hardware = measured_hardware.angles(2,:);
y_yaw_hardware = measured_hardware.angles(3,:);

Y_hardware = [y_pitch_hardware' y_yaw_hardware'];
size(Y_hardware);

%Loading the hardware input values
%input_hardware = load('measured_voltage_hardware');
input_hardware = load('input');

size(input_hardware.volts);

u_pitch_hardware = input_hardware.volts(2,:);
u_yaw_hardware = input_hardware.volts(3,:);

u_hardware = [u_pitch_hardware' u_yaw_hardware'];
size(u_hardware);


%Kalman Filter variables
Rw = diag([700 700 700 700]); %Process noise covarience
Rv = diag([10^-5 10^-5]); %Sensor noise covarience
P0 = diag([1 1 1 1]); %Initial state estimation covarience

x0 = [0;
      0;
      0;
      0;]; %Initial states
X_array=[];
Y_array=[];
Xk_prev = x0;
P_posterior = P0;
%%
for i=1:N
    
    Y_array=[Y_array Y_hardware(i,:)'];
    
    % Kalman Prediction
    x_prior = A*Xk_prev+B*u_hardware(i,:)';
    P_prior = A*P_posterior*A' + Rw;
    
    % Kalman update
    Kf = P_prior*C'*inv(C*P_prior*C' + Rv);
    P_posterior = P_prior - Kf*C*P_prior;
    
    Xk = x_prior + Kf*(Y_hardware(i,:)'-C*x_prior);
    X_array = [X_array Xk];

    % For the next iteration
    Xk_prev = Xk;
end

size(X_array);
size(Y_array);
%%
%Position analysis
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
title('Estimated Angles');
legend('Pitch','Yaw');
%%
%Velocity analysis
Y_array = Y_array';
Velocity_pitch_1 = Y_array(2:N,1);
Velocity_pitch_2 = Y_array(1:N-1,1);
Velocity_pitch = (Velocity_pitch_1 - Velocity_pitch_2)/dt;

Velocity_yaw_1 = Y_array(2:N,2);
Velocity_yaw_2 = Y_array(1:N-1,2);
Velocity_yaw = (Velocity_yaw_1 - Velocity_yaw_2)/dt;

Inst_Velocity = [Velocity_pitch Velocity_yaw];

Inst_Velocity_LPF = lowpass(Inst_Velocity,8,500);
size(Inst_Velocity_LPF);

t1 = linspace(0,60,length(Y_hardware)-1);
figure;
plot(t1,Inst_Velocity_LPF(:,1));
hold on
plot(t1,Inst_Velocity_LPF(:,2));
title('Differentiated Velocity');
legend('Pitch','Yaw');

figure;
plot(t, X_array(3,:));
hold on 
plot(t,X_array(4,:));
title('Estimated Velocity');
legend('Pitch','Yaw');
hold off
%%
%LQR implementation
clc
p = 120;
Q = p*C'*C
R = 1*eye(2)
[K_lqr] = lqr(A,B,Q,R);
K_lqr

sys_cl = ss(A-B*K_lqr, B, C, D);
figure;
step(sys_cl)
ylabel('Step Response');
title('Closed-Loop Step Response: LQR');