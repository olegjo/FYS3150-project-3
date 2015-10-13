import numpy as np
import matplotlib.pyplot as plt



alpha = 2
x = np.linspace(0, 10, 100)
plt.plot(x, np.exp(-alpha*x))

for xi in x:
	if np.exp(-alpha*xi) < 1e-8:
		print xi
		break
plt.show()