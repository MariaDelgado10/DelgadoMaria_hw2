import numpy as np
import matplotlib.pylab as plt

#w=np.genfromtxt("w.dat")
#u=np.genfromtxt("edificio.dat")
w=np.linspace( 0.2*np.sqrt(2), 3.0*np.sqrt(2),100)
caso1=np.genfromtxt("caso1.dat")
caso2=np.genfromtxt("caso2.dat")
caso3=np.genfromtxt("caso3.dat")
caso4=np.genfromtxt("caso4.dat")


#print(len(u))
#print(len(w))
#plt.plot(w, u[:,0])
#plt.show()

plt.figure()
plt.title("omega1 0.707")
plt.xlabel("t")
plt.ylabel("u")
plt.plot(caso1[:,3],caso1[:,0])
plt.savefig("omega1.png")

plt.figure()
plt.title("omega2 1.41")
plt.xlabel("t")
plt.ylabel("u")
plt.plot(caso2[:,3],caso2[:,0])
plt.savefig("omega2.png")

plt.figure()
plt.title("omega3 2.12")
plt.xlabel("t")
plt.ylabel("u")
plt.plot(caso3[:,3],caso3[:,0], label ="u3")
plt.savefig("omega3.png")

plt.figure()
plt.title("omega4 3.5")
plt.plot(caso4[:,3],caso4[:,0])
plt.xlabel("t")
plt.ylabel("u")
plt.savefig("omega3.png")


#plt.figure()
#plt.title("u_max vs frecuencias")
#plt.plot(])
#plt.xlabel("w")
#plt.ylabel("u_max")
#plt.savefig("omega3.png")



