quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);

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

size(Y_hardware);
size(u_hardware);

Rw = diag([50 50]); %Process noise covarience
Rv = diag([10^-5 10^-5]); %Sensor noise covarience
P0 = diag([10 10 10 10]);

x0 = [0;
      0;
      0;
      0;];
X_array=[];
Y_array=[];
Xk_prev = x0;
P_posterior = P0;

for i=1:length(Y)
    Y_array=[Y_array Y_hardware(i,:)'];
    
    % Kalman Prediction
    x_prior = A*Xk_prev+B*u_hardware(i,:)';
    P_prior = A*P_posterior*A' + B*Rw*B';
    
    % Kalman update
    K = P_prior*C'*inv(C*P_prior*C' + Rv);
    P_posterior = P_prior - K*C*P_prior;

    Xk = x_prior + K*(Y_hardware(i,:)'-C*x_prior);
    X_array = [X_array Xk];

    % For the next iteration
    Xk_prev = Xk;
    
    %fprintf("Expected value and error covariance at step = %d",i)
    %Expected value at each step
    Xk;
    %Error Covariance at each step
    P_posterior;
    K
end


t = linspace(0,60,length(Y));
figure;
plot(t,Y_array(2,:));
figure;
plot(t,X_array(2,:));