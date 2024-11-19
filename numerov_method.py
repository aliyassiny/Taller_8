import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('solution.dat')

# Extraer x y las funciones de onda y densidades de probabilidad
x = data[:, 0]
psi_0 = data[:, 1]
psi_1 = data[:, 2]
psi_2 = data[:, 3]
psi_3 = data[:, 4]
psi_0_sq = data[:, 5]
psi_1_sq = data[:, 6]
psi_2_sq = data[:, 7]
psi_3_sq = data[:, 8]

# Graficar las funciones de onda
plt.figure(figsize=(14, 8))

plt.subplot(2, 1, 1)
plt.plot(x, psi_0, label='$\psi_0(x)$')
plt.plot(x, psi_1, label='$\psi_1(x)$')
plt.plot(x, psi_2, label='$\psi_2(x)$')
plt.plot(x, psi_3, label='$\psi_3(x)$')
plt.xlabel('Posición (x)')
plt.ylabel('Función de onda $\psi(x)$')
plt.title('Funciones de onda del oscilador armónico cuántico')
plt.legend()
plt.grid(True)

# Graficar las densidades de probabilidad
plt.subplot(2, 1, 2)
plt.plot(x, psi_0_sq, label='$\psi_0(x)^2$')
plt.plot(x, psi_1_sq, label='$\psi_1(x)^2$')
plt.plot(x, psi_2_sq, label='$\psi_2(x)^2$')
plt.plot(x, psi_3_sq, label='$\psi_3(x)^2$')
plt.xlabel('Posición (x)')
plt.ylabel('Densidad de probabilidad $\psi(x)^2$')
plt.title('Densidades de probabilidad del oscilador armónico cuántico')
plt.legend()
plt.grid(True)

# Mostrar las gráficas de forma interactiva
plt.tight_layout()
plt.show()

print("Las gráficas se han mostrado correctamente.")
