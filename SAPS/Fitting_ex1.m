clc
clear all
close all
y = [10 10 7 7 8 8 9 10 10 13 36 37 36 67 39 66];
x = [12.96 16.2 19.44 22.68 25.92 29.16 32.4 35.64 38.88 42.12 45.36 48.6 51.84 55.08 58.32 61.56];
plot(x,y,'o')
title('Plot of x Versus y')
p = polyfit(x,y,10)
f = polyval(p,x)
hold on
plot(x,f)