% 24-774 Fall 2019
% Team 4
% Keitaro Nishimura
% Pranav Narahari
% Emma Benjaminson
% Lab 1

%% 
clc; clear all ; close all ; 

%% Setup

% load parameters
quanser_aero_parameters
quanser_aero_state_space

s = tf('s') ; 

% nominal plant model 
Gnom = ss(A, B, C, D) ;

% diagonals of plant model
Gd = [Gnom(1,1), 0 ; 0 , Gnom(2,2)]; % diagonal portion of plant model

% proper, stable inverse of plant model
K = 1E2 ; % position of high frequency poles for making inverse a proper tf
Gm_inv = tf(inv(Gnom))*(1/((s/K)+1))^2 ; % writing the extra poles this way ensures they don't affect the DC gain

%bodemag(inv(Gnom),Gm_inv) ; legend('original inverse', 'proper stable inverse') ; 

% minreals of diagonal and inverted plants to reduce model order
Gd = minreal(Gd) ; 
Gm_inv = minreal(Gm_inv) ; 
Gs = tf(Gm_inv)*tf(Gd) ; 
Gs = minreal(Gs,1e-3) ; 

%% Decoupled Controller (CT to DT)

% PID for yaw
Kp_y = 700; 
Ki_y = 20; 
Kd_y = 600; 
% Kp_y = 150; 
% Ki_y = 0; 
% Kd_y = 80; 
N_y = 1000; 
Kyaw = Kp_y + Ki_y*(1/s) + Kd_y*(N_y / (1 + N_y*(1/s))) ; 

% PID for pitch
Kp_p = 700; 
Ki_p = 10; 
Kd_p = 400; 
% Kp_p = 200; 
% Ki_p = 60; 
% Kd_p = 80; 
N_p = 1000; 
Kpitch = Kp_p + Ki_p*(1/s) + Kd_p*(N_y / (1 + N_y*(1/s))) ; 



% sampling time
Ts = 1/500 ; % assuming 500Hz sampling rate

% PID controller DT
Kpid = [Kpitch, 0 ; 0, Kyaw] ; 
Kpid = minreal(Kpid) ; 
step(Kpid)
kDT_PID = c2d(Kpid,Ts,'zoh') 

% check PID controller CL stability
step(feedback(Kpid*Gnom, eye(2))) 

% decoupled controller DT
Kdecoupling = Gs*Kpid ; 
Kdecoupling = minreal(Kdecoupling);
kDT_decouple = c2d(Kdecoupling,Ts,'zoh')  

%% Our LQR controller

a = 1250 ; 
b = 50 ; 
c = 0.005 ; 
d = 0.009 ; 

Q = [a, 0, 0, 0 ; 
     0, b, 0, 0 ; 
     0, 0, 0, 0 ; 
     0, 0, 0, 0 ] ; 
 
R = [c, 0 ; 
     0, d ] ; 
 
Klqr = lqr(Gnom,Q,R) 

%% Bedillion's LQR controller

% Controller
K_lqr = [(1711*s + 4910)/(s+50), (-1557*s - 5153)/(s+50) ; 
     (2432*s + 7817)/(s+50), (921.5*s + 3308)/(s+50) ] ; 
 
% controller in DT
kDT_lqr = c2d(K_lqr,Ts,'zoh')  

%% Results

% Pranav's PID
% kDT_PID =
%  
%   From input 1 to output...
%        400700 z^2 - 8.008e05 z + 4.001e05
%    1:  ----------------------------------
%              z^2 - 1.135 z + 0.1353
%  
%    2:  0
%  
%   From input 2 to output...
%    1:  0
%  
%        600700 z^2 - 1.201e06 z + 6.001e05
%    2:  ----------------------------------
%              z^2 - 1.135 z + 0.1353
%  
% Sample time: 0.002 seconds
% Discrete-time transfer function.

% Keitaro's PID
% kDT_PID =
%  
%   From input 1 to output...
%        8200 z^2 - 1.636e04 z + 8164
%    1:  ----------------------------
%           z^2 - 1.819 z + 0.8187
%  
%    2:  0
%  
%   From input 2 to output...
%    1:  0
%  
%        8150 z - 8123
%    2:  -------------
%         z - 0.8187
%  
% Sample time: 0.002 seconds
% Discrete-time transfer function.
% 
% 
% kDT_decouple =
%  
%   From input 1 to output...
%           40.23 z^3 - 47.28 z^2 - 25.79 z + 32.83
%    1:  ---------------------------------------------
%        z^4 - 3.456 z^3 + 4.467 z^2 - 2.56 z + 0.5488
%  
%           49.38 z^3 - 58.02 z^2 - 31.65 z + 40.3
%    2:  ---------------------------------------------
%        z^4 - 3.456 z^3 + 4.467 z^2 - 2.56 z + 0.5488
%  
%   From input 2 to output...
%           -76.31 z^2 + 13.48 z + 62.32
%    1:  ----------------------------------
%        z^3 - 2.456 z^2 + 2.011 z - 0.5488
%  
%           39.97 z^2 - 7.059 z - 32.65
%    2:  ----------------------------------
%        z^3 - 2.456 z^2 + 2.011 z - 0.5488
%  
% Sample time: 0.002 seconds
% Discrete-time transfer function.
% 
% 
% kDT_lqr =
%  
%   From input 1 to output...
%        1711 z - 1702
%    1:  -------------
%         z - 0.9048
%  
%        2432 z - 2417
%    2:  -------------
%         z - 0.9048
%  
%   From input 2 to output...
%        -1557 z + 1547
%    1:  --------------
%          z - 0.9048
%  
%        921.5 z - 915.2
%    2:  ---------------
%          z - 0.9048
%  
% Sample time: 0.002 seconds
% Discrete-time transfer function.

% Klqr =
% 
%   271.3409  -82.6713   55.6928  -25.4978
%   295.8319   41.9355   63.0417   13.1688
