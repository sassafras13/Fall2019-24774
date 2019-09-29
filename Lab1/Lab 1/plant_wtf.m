function [x,y] = plant_wtf(u,x_prev,A,B,C)
    %plant_wtf calculates the output of the plant
    
    x = A * x_prev + B * u ; 
    y = C * x ; 
end
