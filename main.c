#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <numerov_method.h>

// Constantes físicas
#define HBAR 1.0
#define MASS 1.0
#define OMEGA 1.0

// Parámetros numéricos
#define X_MIN -5.0
#define X_MAX 5.0
#define N_POINTS 1000
#define DX ((X_MAX - X_MIN) / (N_POINTS - 1))
#define MAX_STATES 5

// Función que define el potencial del oscilador armónico
double calcular_potencial(double x) {
    return 0.5 * MASS * OMEGA * OMEGA * x * x;
}

// Método de Numerov para resolver la ecuación de Schrödinger
void metodo_numerov(double *onda, double energia) {
    double x, k_anterior, k_actual, k_siguiente, f_anterior, f_actual, f_siguiente;

    onda[0] = 1.0e-5;
    onda[1] = onda[0] + DX * DX;

    for (int i = 1; i < N_POINTS - 1; i++) {
        x = X_MIN + i * DX;
        k_anterior = 2.0 * MASS / (HBAR * HBAR) * (calcular_potencial(x - DX) - energia);
        k_actual = 2.0 * MASS / (HBAR * HBAR) * (calcular_potencial(x) - energia);
        k_siguiente = 2.0 * MASS / (HBAR * HBAR) * (calcular_potencial(x + DX) - energia);

        f_anterior = 1.0 + DX * DX / 12.0 * k_anterior;
        f_actual = 1.0 + DX * DX / 12.0 * k_actual;
        f_siguiente = 1.0 + DX * DX / 12.0 * k_siguiente;

        onda[i + 1] = ((2.0 * (1.0 - 5.0 * DX * DX / 12.0 * k_actual) * onda[i]) -
                       (f_anterior * onda[i - 1])) / f_siguiente;
    }
}

// Funcion para normalizar
void normalizar_onda(double *onda) {
    double norma = 0.0;
    for (int i = 0; i < N_POINTS; i++) {
        norma += onda[i] * onda[i] * DX;
    }
    norma = sqrt(norma);
    for (int i = 0; i < N_POINTS; i++) {
        onda[i] /= norma;
    }
}

int main() {
    double onda[N_POINTS];
    double x;
    FILE *archivo = fopen("solution.txt", "w");

    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Calcular y guardar 
    for (int n = 0; n <= MAX_STATES; n++) {
        double energia = (n + 0.5) * HBAR * OMEGA;
        metodo_numerov(onda, energia);
        normalizar_onda(onda);

        fprintf(archivo, "# Estado cuántico n = %d\n", n);
        for (int i = 0; i < N_POINTS; i++) {
            x = X_MIN + i * DX;
            fprintf(archivo, "%f\t%f\t%f\n", x, onda[i], onda[i] * onda[i]); // x, ψ_n(x), |ψ_n(x)|²
        }
        fprintf(archivo, "\n\n");
    }

    fclose(archivo);
    printf("Funciones propias calculadas y guardadas en 'solution.txt'.\n");
    return 0;
}
