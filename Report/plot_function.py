import numpy as np
import matplotlib.pyplot as plt


fontsize = 16

alpha = 2
x = np.linspace(-10, 10, 1000)
plt.plot(x, np.exp(-alpha*np.abs(x)))
plt.xlabel('$x$', fontsize = fontsize)
plt.ylabel('$f(x) = e^{-\\alpha |x|}$', fontsize = fontsize)

plt.savefig('FYS3150-project-3-plot-taska-limits.pdf')