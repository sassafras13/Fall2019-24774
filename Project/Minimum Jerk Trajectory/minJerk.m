% 24-774 Fall 2019
% Team 4 
% Minimum Jerk Trajectory Generation 

% References:
% [1] https://mika-s.github.io/python/control-theory/trajectory-generation/2017/12/06/trajectory-generation-with-a-minimum-jerk-trajectory.html
% [2] http://archive.www6.in.tum.de/www6/Main/Publications/FliMcISma2012.pdf

%% 

clc ; clear all ; close all ; 

%% Plant Model for Crazyflie


%% Controller for Crazyflie

% PID controller
Kp = 1 ; 
Ki = 1 ; 
Kd = 1 ; 

%% Minimum Jerk Trajectory 1D

% max acceleration of crazyflie
thrust = 0.060 * 9.81 ; % [N] 
mass = 0.027 ; % [kg]
maxaccln = thrust / mass ; % [m/s2]

% max distance crazyflie will travel during landing routine
maxdist = 10 ; % [m]

% time to get to landing target
tmax = sqrt(2*maxdist / maxaccln) ; % [s] 

% double estimate for safety
tsafe = 2*tmax ; 

% minimum jerk trajectory algorithm (thanks to Prof Bedillion for code)
t = [0:0.00001:tsafe] ;
x = 10*(t/tsafe).^3-15*(t/tsafe).^4+6*(t/tsafe).^5 ;
minjerk= [t' x'] ;

figure(1)
plot(t, x) 
xlabel('Time (s)') ; ylabel('Position (m)') ; title('Minimum Jerk Trajectory for Crazyflie') ; 

%% Minimum Jerk Trajectory 3D

% References: 
% http://archive.www6.in.tum.de/www6/Main/Publications/FliMcISma2012.pdf
% http://courses.shadmehrlab.org/Shortcourse/minimumjerk.pdf

% duration
d = tsafe ; 

%%%%%
% X %
%%%%%

% initial state 
x0 = 1 ; 
xdot0 = 0.1 ; 
xddot0 = 0 ; 

% final state 
xf = 2 ; 
xdotf = 0.01 ; 
xddotf = 0 ; 

% coefficients
[a0, a1, a2, a3, a4, a5] = coefficients(x0, xdot0, xddot0, xf, xdotf, xddotf, d) ; 

% trajectory 
x = trajectory(a0, a1, a2, a3, a4, a5, t) ; 

%%%%%
% Y %
%%%%%

% initial state 
y0 = 2 ; 
ydot0 = 0.1 ; 
yddot0 = 0 ; 

% final state 
yf = 5 ; 
ydotf = 0.01 ; 
yddotf = 0 ; 

% coefficients
[b0, b1, b2, b3, b4, b5] = coefficients(y0, ydot0, yddot0, yf, ydotf, yddotf, d) ; 

% trajectory 
y = trajectory(b0, b1, b2, b3, b4, b5, t) ; 

%%%%%
% Z %
%%%%%

% initial state 
z0 = 3 ; 
zdot0 = 0.1 ; 
zddot0 = 0 ; 

% final state 
zf = 0 ; 
zdotf = 0 ; 
zddotf = 0 ; 

% coefficients
[c0, c1, c2, c3, c4, c5] = coefficients(z0, zdot0, zddot0, zf, zdotf, zddotf, d) ; 

% trajectory 
z = trajectory(c0, c1, c2, c3, c4, c5, t) ; 

% plot results
figure(2)
plot3(x,y,z,'-b') 
grid on
xlabel('X') ; ylabel('Y') ; zlabel('Z') ; 

%% Functions 

function [a0, a1, a2, a3, a4, a5] = coefficients(x0, xdot0, xddot0, xf, xdotf, xddotf, d)
    a0 = x0 ; 
    a1 = xdot0 ; 
    a2 = 0.5*xddot0 ; 
    a3 = (-10/(d^3))*x0 - (6/(d^2))*xdot0 - (3/(2*d))*xddot0 + (10/(d^3))*xf - (4/(d^2))*xdotf + (1/(2*d))*xddotf ; 
    a4 = (15/(d^4))*x0 + (8/(d^3))*xdot0 + (3/(2*d^2))*xddot0 - (15/(d^4))*xf + (7/(d^3))*xdotf - (1/(d^2))*xddotf ; 
    a5 = (-6/(d^5))*x0 - (3/(d^4))*xdot0 - (1/(2*(d^3)))*xddot0 + (6/(d^5))*xf - (3/(d^4))*xdotf + (1/(2*(d^3)))*xddotf ; 
end

function x = trajectory(a0, a1, a2, a3, a4, a5, t)
    x = a0 + a1*t + a2*(t.^2) + a3*(t.^3) + a4*(t.^4) + a5*(t.^5) ; 
end
