clear; clc; close all;
pendulum_ss
P = tf(sys);
T = 0.1;
Pd = c2d(P,T);
K = 10; % just an arbitrary gain controller this isn't the focus of this part
u_ilc = [[0:T:10]' zeros(101,1)];
sim('ILC_keitaro');

f1 = figure()
plot(Response(:,1),Response(:,2)-Response(:,3))

z = tf('z',T);
alpha = 5.0;

% for a sample time of 0.1 an alpha of 5 works really well but when we
% redue the sample time to the actual 0.001 it breaks it and the closes we
% can get is 0.021607...we can't actually. Also after 15 iterations it
% starts to diverge....so we're only doing 15 iterations!

Plant = Pd(1)*(1-feedback(Pd(1)*K,1));
u_ilc = [[0:T:10]' zeros(101,1)];
N = 10;  %Number of iterations of ILC
e = [];
for ii = 1:N
    sim('ILC_keitaro');  %Get the data
    e = [e;std(Response(1:end,2)-Response(1:end,3))];  %Record error value
    for ii = 1:100
        u_ilc(ii,2) = u_ilc(ii,2)+alpha*(Response(ii+1,2)-Response(ii+1,3));  %Implement ILC
    end
end

f3 = figure()
plot(Response(1:end,1),Response(1:end,2)-Response(1:end,3))

f4 = figure()
plot(e)

f5 = figure()
plot(Response(1:end,1),Response(1:end,2),Response(1:end,1),Response(1:end,3))