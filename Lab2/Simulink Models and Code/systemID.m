% 24-774 
% Lab 2
% Team 4
% System identification
% Code drawn from Prof. Bedillion's examples

clear all ; close all ; clc ; 

%%

% run code to generate plant model 
uprightController
% Gnom = Galt ; % comment out if you want to test Gnom

% system ID procedure
% sim('Quanser_Qube_SystemIdentification_2018') ; 
Fs = 1000;            % Sampling frequency

% load data
% data structure: 
% 1 = time
% 2 = Gnom(1,1) (or Gnom(2,1) for theta)
% 3 = Gnom(1,2) (or Gnom(2,2) for theta)
% 4 = plant output
% 5 = reference signal 

alphadata = load('sysID_alpha.mat') ; 
thetadata = load('sysID_theta.mat') ; 

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
figure(1) ; 
subplot(1,2,1) ; 
bode(Galpha, Gnom(1,1), {0.1,50082*pi}) ; legend('Sys ID Plant','Nominal Plant') ; 

figure(2) ; 
subplot(1,2,1) ; 
bode(Gtheta, Gnom(4,1), {0.1,50082*pi}); legend('Sys ID Plant','Nominal Plant') ; 

%% parametric model based on data
% set a weight that weights the low frequency data more heavily because it
% is cleaner
wt = makeweight(2,30,0.01);

% How does Prof. Bedillion know that the system is stable, minimum phase,
% and has relative degree 2?
Gmodalpha = fitfrd(Galpha,2,2,wt);
Gmodtheta = fitfrd(Gtheta,2,2,wt) ; 

% compare parametric model to system ID data
% bode(Gmod,tf(1,[1 1 5]))
figure(1) ; 
subplot(1,2,2) ; 
bode(Gmodalpha,Gnom(1,1)) ; legend('Sys ID Plant MODIFIED','Nominal Plant') ; 
hold on
sgtitle('Pendulum Arm (alpha)') ; 
tf(Gmodalpha)


figure(2)
subplot(1,2,2) ; 
bode(Gmodtheta,Gnom(4,1)) ; legend('Sys ID Plant MODIFIED','Nominal Plant') ; 
hold on
sgtitle('Rotary (motor) arm (theta)') ; 
tf(Gmodtheta) 



