import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as pl

data = np.loadtxt("results.dat")

pl.figure(figsize=(10, 8.5))
pl.plot(data[:,0], data[:,1], label='Theta (t)')
pl.plot(data[:,0], data[:,2], label='Omega (t)')
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.xlabel('T [s]', size='xx-large')
pl.ylabel('Theta (t), Omega(t) [s^-1]', size='xx-large')
pl.title('Non-linear Pendulum with 2-order RK method - Solution', size='xx-large')
pl.legend(fontsize='large')
pl.grid()
pl.show()

pl.figure(figsize=(10, 8.5))
pl.plot(data[:,0], data[:,3], label='Kinetic Energy')
pl.plot(data[:,0], data[:,4], label='Potential Energy')
pl.plot(data[:,0], data[:,5], label='Total Energy')
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.xlabel('T [s]', size='xx-large')
pl.ylabel('Energy per unit mass [m^2/s^2]', size='xx-large')
pl.title('Non-linear Pendulum with 2-order RK method - Energies', size='xx-large')
pl.legend(fontsize='large')
pl.grid()
pl.show()

delta_E = [data[i,5] - data[0,5] for i in range(len(data[:,5]))]

pl.figure(figsize=(10, 8.5))
pl.plot(data[:,0], delta_E)
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.xlabel('T [s]', size='xx-large')
pl.ylabel('E(T) - E(T = 0)', size='xx-large')
pl.title('Non-linear Pendulum with 2-order RK method - Energy conservation', size='xx-large')
pl.yscale('log')
pl.grid()
pl.show()