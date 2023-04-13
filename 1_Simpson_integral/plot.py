import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as pl
import scipy.optimize as opt

data = np. loadtxt("results.dat")
real = [4.4 for e in range(16)]

def analitic_error(N):
    return (24./180.)*(2**5)/(N**4)

err = np.log10(analitic_error(10**data[:,0])**2)

pl.figure(figsize=(10,8.5))
pl.plot(data[:,0], data[:,1], label = 'Simpson integral')
pl.plot(data[:,0], real, label = 'True Value')
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.title('Simpson integral with 2^N steps', size='xx-large')
pl.xlabel('log10(N)', size='xx-large')
pl.ylabel('I(N)', size='xx-large')
pl.ylim(4.39, 4.7)
pl.yscale('log')
pl.grid()
pl.legend()
pl.show()

pl.figure(figsize=(10,8.5))
pl.plot(data[:,0], data[:,2], label = 'Simpson integral error')
pl.plot(data[:,0], err, label='analytic error upper bound')
pl.xticks(size='xx-large')
pl.yticks(size='xx-large')
pl.title('Simpson integral, Residuals', size='xx-large')
pl.xlabel('log10(N)', size='xx-large')
pl.ylabel('log10 [ ((I(N) - I)/I)^2 ]', size='xx-large')
pl.legend(fontsize='large')
pl.grid()
pl.show()
