function [xhat,yhat,P] = kalman_wtf(u,y,xhat_prev,P_prev,A,B,C,Q_kf,R_kf)
    %kalman_wtf calculates the state estimate using the Kalman filter algorithm
    
    % prediction step
    xhat_est = A * xhat_prev + B * u ; 
    P_est = A * P_prev * A' + Q_kf ; 
    
    % update step
    K = (P_est * C') / (C * P_est * C' + R_kf) ; 
    n = size(K,1) ; % hoping that K is square
    xhat = xhat_est + K * (y - C * xhat_est) ; 
    P = (eye(n) - K * C) * P_est ; 
    yhat = C * xhat ; 
end

