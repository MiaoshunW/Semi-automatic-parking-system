theta = 70;
%A = [cos(theta) sin(theta) 0;-sin(theta) cos(theta) 0;0 0 1];
A =[1 1 0;0 1 1;0 0 1]
%B = [1;0;0];
C = [1 0 0;0 0 1];
D = 0;
sys = ss(A,B,C,D);
eig(A)