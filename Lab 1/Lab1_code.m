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
% Kp_y = 700; 
% Ki_y = 20; 
% Kd_y = 600; 
Kp_y = 150; 
Ki_y = 0; 
Kd_y = 80; 
N_y = 100; 
Kyaw = Kp_y + Ki_y*(1/s) + Kd_y*(N_y / (1 + N_y*(1/s))) ; 

% PID for pitch
% Kp_p = 700; 
% Ki_p = 10; 
% Kd_p = 400; 
Kp_p = 200; 
Ki_p = 60; 
Kd_p = 80; 
N_p = 100; 
Kpitch = Kp_p + Ki_p*(1/s) + Kd_p*(N_y / (1 + N_y*(1/s))) ; 

% sampling time
Ts = 1/500 ; % assuming 500Hz sampling rate

% PID controller DT
Kpid = [Kpitch, 0 ; 0, Kyaw] ; 
Kpid = minreal(Kpid) ; 
step(Kpid)
kDT_PID = c2d(Kpid,Ts,'zoh') 

% decoupled controller DT
Kdecoupling = Gs*Kpid ; 
Kdecoupling = minreal(Kdecoupling);
kDT_decouple = c2d(Kdecoupling,Ts,'zoh')  

%% Bedillion's LQR controller

% Controller
K_lqr = [(1711*s + 4910)/(s+50), (-1557*s - 5153)/(s+50) ; 
     (2432*s + 7817)/(s+50), (921.5*s + 3308)/(s+50) ] ; 
 
% controller in DT
kDT_lqr = c2d(K_lqr,Ts,'zoh')  
