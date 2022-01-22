import numpy as np
import pylab as pl

data_in = np.loadtxt("build/in.txt")
data_out = np.loadtxt("build/out.txt")

pl.figure(1)
pl.title("data_in Original data")
pl.plot(data_in)

pl.figure(2)
pl.title("data_our DFT data")
pl.plot(data_out)
pl.show()
