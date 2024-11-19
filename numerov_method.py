import numpy as np
import matplotlib.pyplot as plt

# Leer el archivo solution.txt generado por el programa en C
data = np.loadtxt('solution.txt')

x = data[:, 0]
psi = data[:, 1]

# Graficar
plt.figure(figsize=(12, 8))
plt.plot(x, psi, label='Función de onda $\psi(x)$', color='b', linestyle='-', linewidth=2)
plt.xlabel('Posición (x)', fontsize=14)
plt.ylabel('$\psi(x)$', fontsize=14)
plt.title('Función de onda del oscilador armónico cuántico', fontsize=16)
plt.legend(fontsize=12)
plt.grid(True)
plt.show()
