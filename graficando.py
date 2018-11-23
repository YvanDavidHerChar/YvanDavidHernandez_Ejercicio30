import numpy as np
import matplotlib.pyplot as plt
import sys

#Sacamos los datos creados en C
datosSeriales = np.genfromtxt("datosSeriales.txt")
datosParalelos = np.genfromtxt("datosParalelos.txt")

fig = plt.figure(figsize=(10,10))
plt.hist(datosSeriales, bins = 50, density=True, color='g' , alpha = 0.3)
plt.hist(datosParalelos, bins = 50, density=True , color='r', alpha = 0.3)
plt.title("caminatas en Serie y Paralela")
plt.savefig("caminatas.png")



