
% Sample code to test LegoMindStorm Module.
clc
clear all
close all
myev3 = legoev3('wifi','172.18.48.23','001653486316');
%beep(myev3,1) % module makes a beep sound
mymotor = motor(myev3,'A');
mymotor.Speed = -50; % motor rotates negative direction
start(mymotor)
mymotor.Speestd = 70; % motor rotates positive direction
stop(mymotor); % stop motor function is not working have to check again

