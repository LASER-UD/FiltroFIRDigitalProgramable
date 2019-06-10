fm=250;
fn=fm/2
f1=6;
f2=14;
f1n=f1/fn
f2n=f2/fn
b = fir1(50,[f1n f2n]);
w = linspace(-pi,pi,1000);
freqz(b,1,w);
%%
G=tf(b,1,1/fm)
filt(b,1)
figure;
h=bodeplot(G)
setoptions(h,'FreqUnits','Hz','PhaseVisible','off');
