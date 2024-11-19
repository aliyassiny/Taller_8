#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numerov_method.h"

int main() {
    int N = 1000;  // Número de puntos
    double x_min = -10.0;
    double x_max = 10.0;
    double dx = (x_max - x_min) / (N - 1);

    double *x = (double *)malloc(N * sizeof(double));
    double *V = (double *)malloc(N * sizeof(double));
    double **psi = (double **)malloc(4 * sizeof(double *));
    double **psi_sq = (double **)malloc(4 * sizeof(double *));
    for (int i = 0; i < 4; i++) {
        psi[i] = (double *)malloc(N * sizeof(double));
        psi_sq[i] = (double *)malloc(N * sizeof(double));
    }

    if (x == NULL || V == NULL || psi == NULL || psi_sq == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        x[i] = x_min + i * dx;
        V[i] = 0.5 * x[i] * x[i];  // Potencial V(x) = 0.5 * x^2 (osc. armónico)
    }

    double energies[] = {0.5, 1.5, 2.5, 3.5};  // Niveles de energía para n = 0, 1, 2, 3
    double m = 1.0;  // Masa (ajustable)
    double hbar = 1.0;  // Constante de Planck reducida (ajustable)

    for (int j = 0; j < 4; j++) {
        double E = energies[j];

        numerov_method(x, V, E, m, hbar, psi[j], N);

        double norm = 0.0;
        for (int i = 0; i < N; i++) {
            norm += psi[j][i] * psi[j][i] * dx;
        }
        norm = sqrt(norm);
        for (int i = 0; i < N; i++) {
            psi[j][i] /= norm;  // Normalizar la función de onda
            psi_sq[j][i] = psi[j][i] * psi[j][i];  // Calcular la densidad de probabilidad
        }
    }

    // Guardar todas las soluciones en un único archivo
    FILE *file = fopen("solution.dat", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return 1;
    }

    // Escribir encabezados
    fprintf(file, "# x psi_0 psi_1 psi_2 psi_3 psi_0^2 psi_1^2 psi_2^2 psi_3^2\n");

    for (int i = 0; i < N; i++) {
        fprintf(file, "%f %f %f %f %f %f %f %f %f\n", x[i], psi[0][i], psi[1][i], psi[2][i], psi[3][i], psi_sq[0][i], psi_sq[1][i], psi_sq[2][i], psi_sq[3][i]);
    }

    fclose(file);

    // Liberar memoria
    free(x);
    free(V);
    for (int i = 0; i < 4; i++) {
        free(psi[i]);
        free(psi_sq[i]);
    }
    free(psi);
    free(psi_sq);

    printf("Solución guardada en 'solution.dat'\n");

    return 0;
}
