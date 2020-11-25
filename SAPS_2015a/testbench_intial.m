%mylego=legoev3('wifi','192.168.0.101','001653486316');
writeLCD(mylego,'Semi Autonomous Parking System');
%start = readButton(mylego,'right');
%writeStatusLight(mylego,'orange','pulsing');
mysonicsensor = sonicSensor(mylego);
distance = readDistance(mysonicsensor);
dis_cm=distance*100;