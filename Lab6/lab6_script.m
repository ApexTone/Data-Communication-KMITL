% part 1: basic matrix
clear all;
close all;
a = [1:10]
b = [1:100]/10
c = [1:0.1:10]
d = [0.1:0.1:10]

% part 2: basic plot
clear all;
close all;
x = [0:10]
m = -2
c = 3
y1 = m*x+c
y2 = c.^x
figure(1)
plot(x,y1)
figure(2)
plot(x,y1)
figure(3)
subplot(2,1,1), plot(x,y1)
subplot(2,1,2), plot(x,y2)
figure(4)
subplot(1,2,1), plot(x,y1)
subplot(1,2,2), plot(x,y2)

% part 3: sin wave
clear all;
close all;
f=1; %frequency [Hz]
t=(0:1/(f*100):20);
a=5;    %amplitude [V]
phi=0;  %phase
y=a*sin(2*pi*f*t+phi);
figure(5)
plot(t,y)
xlabel('time(s)')
ylabel('amplitude(V)')

% part 4: edited sin wave
clear all;
close all;
f=1; %frequency [Hz]
t=(0:1/(f*100):20);
a=3;    %amplitude [V]
phi=0;  %phase
y=a*sin(2*pi*f*t+phi);
figure(6)
plot(t,y)
xlabel('time(s)')
ylabel('amplitude(V)')
