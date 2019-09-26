clear;
clc;
quanser_aero_parameters;
quanser_aero_state_space;
aero_sys=ss(A,B,C,D);


s = tf('s');
Diff_LPF = s/(s/50 +1); %Differentiation and LPF

%Kalman Filter variables
Rw = diag([50 50 50 50]); %Process noise covarience
Rv = diag([10^-2 10^-2]); %Sensor noise covarience
P0 = diag([1 1 1 1]); %Initial state estimation covarience

x0 = [0;
      0;
      0;
      0;]; %Initial states
  
%LQR implementation

a = 6500;
b = 150;
Q = [a 0 0 0;
    0 b 0 0;
    0 0 0 0;
    0 0 0 0;];
R = 0.03*eye(2);
[K_lqr] = lqr(A,B,Q,R);
K_lqr;
s = tf('s');

K_LQR = [(1711*s+4910)/(s+50) (-1557*s-5153)/(s+50);
        (2432*s+7817)/(s+50) (921.5*s+3308)/(s+50)];