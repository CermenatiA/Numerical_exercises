import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as pl

data = np. loadtxt("results.dat")
real = [4.4 for e in range(20)]

pl.figure(figsize=(10,8.5))
pl.plot(data[:,0], data[:,1], label = 'Simpson integral')
pl.plot(data[:,0], real, label = 'True Value')
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.title('Simpson integral with 2^N steps', size='xx-large')
pl.xlabel('N', size='xx-large')
pl.ylabel('I(N)', size='xx-large')
pl.grid()
pl.legend()
pl.show()

rms = [(data[e,1] - 4.4)**2 for e in range(20)]

pl.figure(figsize=(10,8.5))
pl.plot(data[:,0], rms)
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.title('Simpson integral, Residuals', size='xx-large')
pl.xlabel('N', size='xx-large')
pl.ylabel('(I(N) - I)^2', size='xx-large')
pl.yscale('log')
pl.grid()
pl.show()