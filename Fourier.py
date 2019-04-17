import numpy as np
import matplotlib.pylab  as plt

signal= np.genfromtxt("signal.dat")
signalsuma=np.genfromtxt("signalSuma.dat")

signal_x=np.genfromtxt("signal.dat")[:,0]
#print(signal_x)
signal_y=np.genfromtxt("signal.dat")[:,1]
#print(signal_y)
suma_x=np.genfromtxt("signalSuma.dat")[:,0]
suma_y=np.genfromtxt("signalSuma.dat")[:,1]

plt.figure(figsize=(10,5))
plt.subplot(2,2,1)
plt.plot(signal_x,signal_y)
plt.title("signal")
plt.subplot(2,2,2)
plt.plot(suma_x,suma_y)
plt.title("signalSuma")

plt.savefig("Señales.png")
plt.show()

