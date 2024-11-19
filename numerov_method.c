#include <stdlib.h>
#include <math.h>
#include "numerov_method.h"

void numerov_method(double *x, double *V, double E, double m, double hbar, double *y, int N) {
    double dx = x[1] - x[0]; 

    double *g = (double *)malloc(N * sizeof(double));
    double *f = (double *)malloc(N * sizeof(double));

    if (g == NULL || f == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }

    for (int n = 0; n < N; n++) {
        g[n] = (2 * m / (hbar * hbar)) * (E - V[n]);
        f[n] = 1 + g[n] * dx * dx / 12.0;
    }

    y[0] = 1e-5; 
    y[1] = 1e-5 + 1e-10;  

    // Aplicación del método de Numerov
    for (int n = 1; n < N - 1; n++) {
        y[n + 1] = (2 * (1 - 5 * f[n] / 6.0) * y[n] - (1 + f[n - 1] / 12.0) * y[n - 1]) / (1 + f[n + 1] / 12.0);
    }

    free(g);
    free(f);
}
