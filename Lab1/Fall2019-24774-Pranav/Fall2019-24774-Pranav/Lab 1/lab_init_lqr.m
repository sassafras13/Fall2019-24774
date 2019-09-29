quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);

measured = load('measured');
input = load('input');

size(measured.angles);
size(input.volt);

y_pitch = measured.angles(2,:);
y_yaw = measured.angles(3,:);

u_pitch = input.volt(2,:);
u_yaw = input.volt(3,:);

Y = [y_pitch' y_yaw'];
u = [u_pitch' u_yaw'];

size(Y);
size(u);

%u(1,:)'

%x = A*[-0.523;-0.785;0;0] + B*u(1,:)';
y = C*[0;0;0;0];
Y(1,:);

Rw = diag([50 50]); %Process noise covarience
Rv = diag([10^-5 10^-5]); %Sensor noise covarience
P0 = diag([50 50 10 10]);

x0 = [0;
      0;
      0;
      0;];
X_array=[];
Y_array=[];
Xk_prev = x0;
P_posterior = P0;

for i=1:length(Y)
    Y_array=[Y_array Y(i,:)'];
    
    % Kalman Prediction
    x_prior = A*Xk_prev+B*u(i,:)';
    P_prior = A*P_posterior*A' + B*Rw*B';
    
    % Kalman update
    K = P_prior*C'*inv(C*P_prior*C' + Rv);
    P_posterior = P_prior - K*C*P_prior;

    Xk = x_prior + K*(Y(i,:)'-C*x_prior);
    X_array = [X_array Xk];

    % For the next iteration
    Xk_prev = Xk;
    
    %fprintf("Expected value and error covariance at step = %d",i)
    %Expected value at each step
    Xk;
    %Error Covariance at each step
    P_posterior;
end

Y_array(1,:) - X_array(1,:);

t = linspace(0,60,length(Y));
figure;
plot(t,Y_array(1,:));
figure;
plot(t,X_array(1,:));
%plot(t,Y_array(2,:));
% hold on
%plot(X_array(2,:)',t');
% title('Position estimation results');
% xlabel('X');
% ylabel('Y');
% zlabel('Z');
% legend('Noisy Measurements','Kalman estimated displacement');

