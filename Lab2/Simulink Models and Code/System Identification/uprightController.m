% 24-774 
% Lab 2
% Team 4
% Upright pendulum system identification using [CHOOSE A METHOD]
% Model drawn from QUBE hardware documentation

%% Linearized Model of System

% parameters
g = 9.8 ; % m/s^2

mp = 0.024 ; % kg
Lp = 0.129 ; % m
Dp = 0.0005 ; % N*m*s/rad
Jp = (1/3)*mp*Lp^2 ; % kg*m^2 (for moment of intertia about the end of a rod)

mr = 0.095 ; % kg
Lr = 0.085 ; % m
Dr = 0.0015 ; % N*m*s/rad
Jr = (1/3)*mr*Lr^2 ; % kg*m^2 (for moment of intertia about the end of a rod)

Jt = Jp*mp*Lr^2 + Jr*Jp + 0.25*Jr*mp*Lp^2 ; 

% linearized equations of motion

A = [0, 0, 1, 0 ; 
     0, 0, 0, 1 ; 
     0, ((1/Jt)*(0.25*mp^2*Lp^2*Lr*g)), ((1/Jt)*(-(Jp + 0.25*mp*Lp^2)*Dr)), ((1/Jt)*(0.5*mp*Lp*Lr*Dp)) ; 
     0, ((1/Jt)*(-0.5*mp*Lp*g*(Jr+mp*Lr^2))), ((1/Jt)*(0.5*mp*Lp*Lr*Dr)), ((1/Jt)*(-Jr+mp*Lr^2)*Dp) ] ; 
 
B = [0 ;
     0 ; 
     ((1/Jt)*(Jp+0.25*mp*Lp^2)) ; 
     ((1/Jt)*(-0.5*mp*Lp*Lr)) ] ; 

% should I use all 4 states assuming that I will use differentiator +
% filter? 
% C = [1, 0, 0, 0 ; 
%      0, 1, 0, 0 ] ; 
%  
% D = [0 ; 
%      0 ] ; 

C = [1, 0, 0, 0 ; 
     0, 1, 0, 0 ; 
     0, 0, 1, 0 ; 
     0, 0, 0, 1 ] ; 
 
D = [0 ; 
     0 ; 
     0 ; 
     0 ] ; 
 
% build SS model 
Gnom = ss(A,B,C,D) ; 
Gnom = 0.01*Gnom ; 

% CHECK THE PERFORMANCE OF THE ACTUAL SYSTEM AGAINST MY MODEL AND SEE IF
% I'M CLOSE OR I NEED TO ADJUST IT

%% Alternate Plant Model

% This is taken from the hardware documentation
Aalt = [0, 0, 1, 0 ; 
        0, 0, 0, 1 ; 
        0, 149.2751, -0.0104, 0 ; 
        0, 261.6091, -0.0103, 0 ] ; 
    
Balt = [0 ; 
        0 ; 
        49.7275 ; 
        49.1493 ] ; 
    
Calt = [1, 0, 0, 0 ; 
        0, 1, 0, 0 ; 
        0, 0, 0, 0 ; 
        0, 0, 0, 0 ] ; 
Galt = ss(Aalt, Balt, Calt, D) ; 

% NOTE: It makes sense that Galt is wildly unstable because it is
% linearized about the inverted position which is inherently unstable
    
%% LQR Controller

Pendulum_Model
G = system_dynamics ; 
% bode(G) ; 

% differentiator and low pass filter for obtaining velocities (thanks
% Pranav)
s = tf('s');
Diff_LPF = s/(s/50 +1); %Differentiation and LPF

Q = diag([10, 1, 10, 10]) ; 
R = 1 ; 

Klqr = lqr(G,Q,R) ; 
Klqr = Klqr' ; 

%% LQR Controller from Mfg

% Klqr = [35, -2, 3, -1.5 ] ; % [pendulum, arm ; dot pendulum, dot arm] 