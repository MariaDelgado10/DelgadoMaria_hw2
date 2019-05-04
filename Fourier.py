import numpy as np
import matplotlib.pylab  as plt
from matplotlib import mlab


signal= np.genfromtxt("signal.dat")
signalsuma=np.genfromtxt("signalSuma.dat")

signal_x=np.genfromtxt("signal.dat", delimiter=",")[:,0]
#print(signal_x)
signal_y=np.genfromtxt("signal.dat", delimiter=",")[:,1]
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
N=len(signal)
#def fourier(signal):
#    val_transf=[]
 #   for i in range(0,N):
#        transformada=0
#        for k in range(0,N):
#            transformada+=(signal[k]*np.exp((-(1j)*2*np.pi*k*i)/N))
#        val_transf.append(transformada)
#    return((val_transf))
#print((fourier(signal)))

#print(len(val_transf))
#plt.plot(fourier(signal))
#plt.savefig("Fourier_trans.png")

transformada=np.fft.fft(signal_y,N,norm=None)
transformada2=np.fft.fft(suma_y,N,norm=None)
dtiempo=signal_x[1]-signal_x[0]
dtiempo2=suma_x[1]-suma_x[0]
frecuencias=np.fft.fftfreq(N, d=dtiempo)
frecuencias2=np.fft.fftfreq(N, d=dtiempo2)
print(frecuencias)

plt.figure()
plt.plot(frecuencias,transformada)
plt.plot(frecuencias2,transformada2)
plt.xlabel("frecuencias")
plt.ylabel("transformada")
plt.legend()
plt.title("frecuencias con fft")
plt.savefig("Fourier_trans.png")

#@_autogen_docstring(Axes.specgram)
#def specgram(
#        frecuencias, NFFT=None, Fs=None, Fc=None, detrend=None, window=None,
#        noverlap=None, cmap=None, xextent=None, pad_to=None,
#        sides=None, scale_by_freq=None, mode=None, scale=None,
#        vmin=None, vmax=None, *, data=None, **kwargs):
#    __ret = gca().specgram( frecuencias, NFFT=NFFT, Fs=Fs, Fc=Fc, detrend=detrend, window=window,
#        noverlap=noverlap, cmap=cmap, xextent=xextent, pad_to=pad_to,
#        sides=sides, scale_by_freq=scale_by_freq, mode=mode,
#        scale=scale, vmin=vmin, vmax=vmax, **({"data": data} if data
#        is not None else {}), **kwargs)
#    sci(__ret[-1])
#    return __ret

