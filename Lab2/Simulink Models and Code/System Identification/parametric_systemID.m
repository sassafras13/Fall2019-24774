% 24-774 
% Lab 2
% Team 4
% Parametric system identification
% Code drawn from Prof. Bedillion's examples

clear all ; close all ; clc ; 

%%

% import system model from mfg
Pendulum_Model
G = system_dynamics ; % G = [alpha, theta, alphadot, thetadot]

% differentiator and low pass filter for obtaining velocities (thanks
% Pranav)
s = tf('s');
Diff_LPF = s/(s/50 +1); %Differentiation and LPF


% LQR Controller from Mfg
Klqr = [35, -2, 3, -1.5 ] ; % [pendulum, arm ; dot pendulum, dot arm] 

% system ID procedure
Fs = 1000;            % Sampling frequency

% load data
% data structure: 
% 1 = time
% 2 = Gnom(1,1) (or Gnom(2,1) for theta)
% 3 = Gnom(1,2) (or Gnom(2,2) for theta)
% 4 = plant output
% 5 = reference signal 

alphadata = load('sysID_parametric_alpha_mag10.mat') ; 
thetadata = load('sysID_parametric_theta_mag10.mat') ; 

L_alpha = length(alphadata.ans(1,:)) ; % Length of signal
L_theta = length(thetadata.ans(1,:)) ;

% Take FFT of data
Ualpha = fft(alphadata.ans(1,:));
Yalpha = fft(alphadata.ans(4,:));

Utheta = fft(thetadata.ans(1,:)) ; 
Ytheta = fft(thetadata.ans(4,:)) ; 

% singled sided FFT
P2alpha = Yalpha./Ualpha;
P1alpha = P2alpha(1:L_alpha/2+1);
P1alpha(2:end-1) = P1alpha(2:end-1);

P2theta = Ytheta./Utheta ; 
P1theta = P2theta(1:L_theta/2+1) ; 
P1theta(2:end-1) = P1theta(2:end-1) ; 

% generate frequency array and use fitfrd to get the model 
falpha = Fs*(0:(L_alpha/2))/L_alpha;
Galpha = frd(P1alpha,falpha*2*pi);

ftheta = Fs*(0:(L_theta/2))/L_theta ; 
Gtheta = frd(P1theta,ftheta*2*pi) ; 

% compare Bode plots for G and Gnom
% bode(G,tf(1,[1 1 5]),{0.1,50082*pi}) ; legend('Measured Plant','Predicted Plant') ; 
% figure(1) ; 
% subplot(1,2,1) ; 
% bode(Galpha, G(1,1), {0.1,50082*pi}) ; legend('Sys ID Raw Data','Plant Model') ;
% title('Alpha - Pendulum Angle') ; 
% 
% figure(1) ; 
% subplot(1,2,2) ; 
% bode(Gtheta, G(2,1), {0.1,50082*pi}); legend('Sys ID Raw Data','Plant Model') ; 
% title('Theta - Rotary Arm Angle') ; 
% 
% figure(1)
% sgtitle('Raw Data vs Plant Model Obtained Via Chirp Input') ; 

%% parametric model based on data
% set a weight that weights the low frequency data more heavily because it
% is cleaner
wt = makeweight(2,50,0.01);

Gmodalpha_sys = fitfrd(Galpha,2,2,wt);
Gmodtheta_sys = fitfrd(Gtheta,2,2,wt) ; 

% compare parametric model to system ID data
figure(2) ; 
subplot(1,2,1) ; 
% bode(Gmodalpha_sys,G(1,1),{0.1,50082*pi}) ; legend('Sys ID Parametric Model','Plant Model') ; 
bode(Gmodalpha_sys,{0.1,50082*pi}) ;
title('Alpha - Pendulum Angle') ; 

figure(2)
subplot(1,2,2) ; 
% bode(Gmodtheta_sys,G(2,1),{0.1,50082*pi}) ; legend('Sys ID Parametric Model','Plant Model') ; 
bode(Gmodtheta_sys,{0.1,50082*pi}) ;
title('Theta - Rotary Arm Angle') ;

figure(2)
sgtitle('Sys ID Parametric Model Gain = 10') ; 

tf(Gmodalpha_sys)
tf(Gmodtheta_sys) 

tf(G(1,1))
tf(G(2,1))


