import numpy as np
import matplotlib.pylab  as plt
from matplotlib import mlab


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

#Trannsformada discreta de Fourier de signal.dat
N=(len(signal))
def fourier(signal):
    
    y=signal[:,1]
    x=signal[:,0]
    N = len(y)
        
    val_transfreal=np.zeros(0)
    val_transimg=np.zeros(0)
    n = np.linspace(0, N-1, N)
   # for i in range(0,N):
#        transformada=0
    for k in range(N):
        val_trans[k]=np.sum(y[k]*np.exp(-2*1j*np.pi*k*n/N))
                                 
    frecuencias = np.zeros(N)
    dtiempo =x[1]-x[0]
                                    
         
    for i in range(int(N/2)):
        frecuencias[i] = (i+1)*dtiempo
    for i in range(-1,-int(N/2)-1, -1):
        frecuencias[i] = (i)*dtiempo
    return frecuencias, val_transfreal, val_transimg
    #return(N)                       
    

#print(len(val_transf))
#plt.plot(fourier(signal))
#plt.savefig("Fourierpropia_trans.png")

transformada=np.fft.fft(signal_y,N,norm=None)
transformada2=np.fft.fft(suma_y,N,norm=None)
dtiempo=signal_x[1]-signal_x[0]
dtiempo2=suma_x[1]-suma_x[0]
frecuencias=np.fft.fftfreq(N, d=dtiempo)
frecuencias2=np.fft.fftfreq(N, d=dtiempo2)
print(frecuencias)

plt.figure(figsize=(10,5))
plt.subplot(2,2,1)
plt.plot(frecuencias,transformada)
plt.xlabel("frecuencias")
plt.ylabel("transformada")
plt.title("transformada signal con fft")
plt.subplot(2,2,2)
plt.plot(frecuencias2,transformada2)
plt.xlabel("frecuencias")
plt.ylabel("transformada")
plt.title("transformada signalsuma con fft")
plt.savefig("Fourier_trans.png")

plt.figure(figsize=(10,5))
plt.subplot(2,2,1)
plt.specgram(signal_y, NFFT=256, Fs=1/dtiempo) #ojojojojojojojo esto es 1/dt
plt.xlabel("tiempo")
plt.ylabel("frecuencias")
plt.title("espectograma de la señal signal")
plt.subplot(2,2,2)
plt.specgram(suma_y, NFFT=256, Fs=1/dtiempo2)
plt.title("espectograma de la señal signalsuma")
plt.xlabel("tiempo")
plt.ylabel("frecuencias")
plt.savefig("espectograma2señales.png")


temblor=np.genfromtxt("temblor.txt", skip_header=4)
plt.figure()
plt.plot(temblor)
plt.xlabel("tiempo")
plt.ylabel("señal sismica")
plt.title("señal sismica vs tiempo")
plt.savefig("temblor.png")

transformada_temblor=np.fft.fft(temblor,N,norm=None)
transformada=np.fft.fft(temblor,N,norm=None)
dtiempo_temblor=temblor[1]-temblor[0]
frecuencias_temblor=np.fft.fftfreq(N, d=dtiempo_temblor)

plt.figure()
plt.plot(frecuencias_temblor,transformada_temblor)
plt.xlabel("frecuencia ")
plt.ylabel("transformada ")
plt.title("tranformada de fourier del temblor")
plt.savefig("transfouriertemblor.png")


plt.figure()
plt.specgram(temblor, NFFT=256, Fs=512)
plt.title("espectograma de la señal sismica")
plt.xlabel("tiempo")
plt.ylabel("frecuencias")
plt.savefig("espectogramatemblor.png")