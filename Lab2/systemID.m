% 24-774 
% Lab 2
% Team 4
% System identification
% Code drawn from Prof. Bedillion's examples

sim('System_Identification')
Fs = 1000;            % Sampling frequency
L = length(simout(:,1)); % Length of signal

% Take FFT of data
U = fft(simout(:,1));
Y = fft(simout(:,2));

% singled sided FFT
P2 = Y./U;
P1 = P2(1:L/2+1);
P1(2:end-1) = P1(2:end-1);

% generate frequency array and use fitfrd to get the model 
f = Fs*(0:(L/2))/L;
G = frd(P1,f*2*pi);
bode(G,tf(1,[1 1 5]),{0.1,50082*pi})

%% parametric model based on data
% set a weight that weights the low frequency data more heavily because it
% is cleaner
wt = makeweight(2,30,0.01);

% How does Prof. Bedillion know that the system is stable, minimum phase,
% and has relative degree 2?
Gmod = fitfrd(G,2,2,wt);

% compare parametric model to system ID data
bode(Gmod,tf(1,[1 1 5]))
tf(Gmod)




