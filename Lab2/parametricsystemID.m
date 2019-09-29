% 24-774 
% Lab 2
% Team 4
% Parametric system identification
% Code drawn from Prof. Bedillion's examples

% run the sys id in Simulink
sim('System_Identification_Parametric')
ydata = parametric_data(:,2);
udata = parametric_data(:,1);

% build the ARMA model
n = 2;  %Number of states
L = length(ydata);
X = [];
Y = [];
for ii = n+1:L
    y = [];
    u = [];
    for jj = 1:n
        y = [y -ydata(ii-jj)];
        u = [u udata(ii-jj)];
    end
    X = [X;[y,u]];
    Y = [Y;ydata(ii)];
end

% pseudo-inverse solution 
theta = pinv(X)*Y

% build the model
Gmod = tf(theta(3:end)',[1 theta(1:2)'],1/1000)

% test the fit
ymod = lsim(Gmod,udata,[0:.001:0.001*(length(udata)-1)]);
plot([ydata,ymod])

% compare with other model in CT 
Gmod_CT = d2c(Gmod)
