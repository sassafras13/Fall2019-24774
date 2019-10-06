% 24-774 
% Lab 2
% Team 4
% Least squares system identification
% Code drawn from Prof. Bedillion's examples

%%
close all ; clear all ; clc ; 

%% NOTES
% input 1 = 0.1
% input 2 = 1.0 
% input 3 = 0.01 
% input 4 = 0.5

%%

% run code to get nominal plant model
uprightController 

% run the parametric system identification script
parametric_systemID

% run the sys id in Simulink
% sim('System_Identification_Parametric')
% sim('Quanser_Qube_ParametricSystemID') 

% load data
% data structure: 
% 1 = time
% 2 = Gnom(1,1) (or Gnom(2,1) for theta)
% 3 = Gnom(1,2) (or Gnom(2,2) for theta)
% 4 = plant output
% 5 = reference signal 
alphadata = load('sysID_parametric_alpha_input3.mat') ; 
thetadata = load('sysID_parametric_theta_input3.mat') ; 

ydataalpha = alphadata.ans(4,:);
udataalpha = alphadata.ans(1,:);

ydatatheta = thetadata.ans(4,:) ;
udatatheta = thetadata.ans(1,:) ; 

% build the ARMA model - ALPHA
n = 2;  %Number of states
L = length(ydataalpha);
X = [];
Y = [];
for ii = n+1:L
    y = [];
    u = [];
    for jj = 1:n
        y = [y -ydataalpha(ii-jj)];
        u = [u udataalpha(ii-jj)];
    end
    X = [X;[y,u]];
    Y = [Y;ydataalpha(ii)];
end

% build the ARMA model - THETA
nt = 2;  %Number of states
Lt = length(ydatatheta);
Xt = [];
Yt = [];
for ii = nt+1:Lt
    yt = [];
    ut = [];
    for jj = 1:nt
        yt = [yt -ydatatheta(ii-jj)];
        ut = [ut udatatheta(ii-jj)];
    end
    Xt = [Xt;[yt,ut]];
    Yt = [Yt;ydatatheta(ii)];
end

% pseudo-inverse solution 
thetaA = pinv(X)*Y
thetaT = pinv(Xt)*Yt

% build the model
Gmodalpha = tf(thetaA(3:end)',[1 thetaA(1:2)'],1/1000)
Gmodtheta = tf(thetaT(3:end)',[1 thetaT(1:2)'],1/1000)

% test the fit
ymodalpha = lsim(Gmodalpha,udataalpha,[0:.001:0.001*(length(udataalpha)-1)]);
ymodtheta = lsim(Gmodtheta,udatatheta,[0:.001:0.001*(length(udatatheta)-1)]);

% plot data
figure(1)
subplot(1,2,1)
plot([ydataalpha',ymodalpha]) ; legend('Y data','Y mod') ; title('Alpha') ; 
subplot(1,2,2)
plot([ydatatheta',ymodtheta]) ; legend('Y data','Y mod') ; title('Theta') ; 
sgtitle('Input Magnitude = 0.5') ; 

% compare with other model in CT 
Gmodalpha_CT = d2c(Gmodalpha)
Gmodtheta_CT = d2c(Gmodtheta)

figure(2)
subplot(1,2,1)
bode(Gmodalpha_CT, Gmodalpha_sys) ; legend('Least Squares','Parametric Fit') ; 
subplot(1,2,2)
bode(Gmodtheta_CT, Gmodtheta_sys) ; legend('Least Squares','Parametric Fit') ; 
sgtitle('Alpha (left) ; Theta (right)') ; 
