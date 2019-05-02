import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("dat_ec3.dat")
grid = np.reshape(data, (101, 31))


plt.figure()
plt.imshow(grid)
plt.xlabel("indice X")
plt.ylabel("indice Y")
plt.colorbar(label="Temperatura")
plt.savefig("graf_ec3(1).png")
