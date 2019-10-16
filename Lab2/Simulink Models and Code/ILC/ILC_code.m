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


% design basic PID controller for down configuration
Kp = 0.2 ; 
Ki = 0.7 ; 
Kd = 2.0 ; 
K = (Kp + Ki*(1/s) + Kd*s) / (s + 100) ; 

alpha = 2 ; 

% set number of iterations 
N = 10 ; 

u_ilc = [[0:T:1]' zeros(11,1)];  %Reset the ILC

% error for each iteration 
e = [];

% iterate on ILC learner
for ii = 1:N
    qc_build_model('ILC_2018') ; 
    qc_start_model('ILC_2018') ; 
    pause ; 
    load('response.mat') ; 
    Response = ans(:,:)' ; % row 1 = time; row 2 = input signal ; row 3 = pendulum output ; row 4 = motor arm output
    e = [e;std(Response(1:end-1,2)-Response(1:end-1,4))]  %Record error value
    for ii = 1:10
        u_ilc(ii,2) = u_ilc(ii,2)+alpha*(Response(ii+1,2)-Response(ii+1,4));
    end
end

load('response.mat') ; 
Response = ans(:,:)' ; % row 1 = time; row 2 = input signal ; row 3 = pendulum output ; row 4 = motor arm output
    
% plot the data
figure(1)
plot(Response(1:end-1,1)',Response(1:end-1,2)-Response(1:end-1,4))
title('Time Domain Response of Last Test') ; 
xlabel('Time (s)') ; ylabel('Response') ; 

figure(2)
plot(e)
title('Error on Each Iteration') ; 
xlabel('Iteration') ; ylabel('Error') ; 