x1 = a.time(1:10).';
y1 = a.signals.values(1:10).';
plot(x1,y1,'o')
title('Plot of x Versus y')
p = polyfit(x1,y1,1)


