% 24-774 
% Lab 2
% Team 4
% Iterative learning controller
% Code drawn from Prof. Bedillion's examples

clear all ; close all ; clc ; 

%%

% load key variables
s = tf('s') ;
T = 0.1 ; % sampling rate 
z = tf('z',T);

Pendulum_Model % load pendulum model
G = tf(system_dynamics) ; % plant model
Gtheta = G(2,1) ; % tf for motor angle, theta
GthetaD = c2d(Gtheta,T) ; % convert to discrete time

% design basic PID controller for down configuration
Kp = 10 ; 
Ki = 10 ; 
Kd = 10 ; 
K = (Kp + Ki*(1/s) + Kd*s) / (s + 100) ; 
KD = c2d(K,T) ; 

Plant = GthetaD*(1-feedback(GthetaD*KD,1));

G_inf = [1 1;-z*Plant 0];

% design L with hinfsyn
[L,CL,gam] = hinfsyn(G_inf,1,1);

% convert to DSP
L = tf(L);  %Convert to TF
[num,den] = tfdata(L,'v');  %Extract polynomials
L_DSP = filt(num,den,T);  %Convert to polynomials in z^{-1}
[b,a] = tfdata(L_DSP,'v');  %Rip out the new polynomials for the filt command.

% set number of iterations 
N = 50 ; 

u_ilc = [[0:T:10]' zeros(101,1)];  %Reset the ILC

% error for each iteration 
e = [];

% iterate on ILC learner
for ii = 1:N
    sim('ILC');  %Get the data
    e = [e;std(Response.signals(1).values(1:end-1)-Response.signals(2).values(1:end-1))];  %Record error value
    Le = filter(b,a,Response.signals(1).values(:)-Response.signals(2).values(:));  %This performs the filtering - implements L
    for ii = 1:100
        u_ilc(ii,2) = u_ilc(ii,2)+Le(ii+1);  %Implement ILC
    end
end

% plot the data
plot(Response.signals(1).values(1:end-1),Response.signals(1).values(1:end-1)-Response.signals(2).values(1:end-1))
plot(e)