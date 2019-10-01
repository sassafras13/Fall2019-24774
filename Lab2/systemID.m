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
sim('Quanser_Qube_SystemIdentification') ; 
Fs = 1000;            % Sampling frequency
L = length(ans.simout(:,1)); % Length of signal

% Take FFT of data
U = fft(ans.simout(:,1));
Y = fft(ans.simout(:,2));

% singled sided FFT
P2 = Y./U;
P1 = P2(1:L/2+1);
P1(2:end-1) = P1(2:end-1);

% generate frequency array and use fitfrd to get the model 
f = Fs*(0:(L/2))/L;
G = frd(P1,f*2*pi);

% compare Bode plots for G and Gnom
% bode(G,tf(1,[1 1 5]),{0.1,50082*pi}) ; legend('Measured Plant','Predicted Plant') ; 
figure(1) ; 
subplot(1,2,1) ; 
bode(G, Gnom(1,1), {0.1,50082*pi}) ; legend('Sys ID Plant','Nominal Plant') ; 

%% parametric model based on data
% set a weight that weights the low frequency data more heavily because it
% is cleaner
wt = makeweight(2,30,0.01);

% How does Prof. Bedillion know that the system is stable, minimum phase,
% and has relative degree 2?
Gmod = fitfrd(G,2,2,wt);

% compare parametric model to system ID data
% bode(Gmod,tf(1,[1 1 5]))
figure(1) ; 
subplot(1,2,2) ; 
bode(Gmod,Gnom(1,1)) ; legend('Sys ID Plant MODIFIED','Nominal Plant') ; 
tf(Gmod)




