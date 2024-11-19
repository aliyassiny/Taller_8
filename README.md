# Taller_8

# Antes de empezar, debe instalar todo lo necesario para que el proyecto funcione correctamente.

1. instale gcc para todos los codigos en c.
2. instale tambien todas las librerias que vea en este texto.


# Informe del Desarrollo del Código del Oscilador Armónico Cuántico
Este proyecto implementa la solución del problema del oscilador armónico cuántico utilizando diferentes metodologías y lenguajes de programación. 

## Se han desarrollado dos enfoques principales:

1. **Implementación en C** utilizando el método de Numerov.
2. **Visualización en Python** para graficar las funciones propias y sus densidades de probabilidad.

# Estructura del Proyecto
## El proyecto está organizado de la siguiente manera:

/taller 8 
    CMakeList.txt
    Makefile
    main.c
    numerov_method.c
    numerov_method.h
    numerov_method.py                               
    build

## CMakeLists.txt:
Archivo de configuración para la construcción del proyecto usando CMake.

cmake_minimum_required(VERSION 3.10)
project(NumerovMethod)

set(CMAKE_C_STANDARD 99)

add_executable(numerov_program main.c numerov_method.c)
target_link_libraries(numerov_program m)

Esto Compilara los codigos en c del programa, y tambien creara automaticamento todo lo requerido.

## Makefile:
Archivo de configuración.

## main.c:
El siguiente código proporciona una herramienta numérica para resolver la ecuación de Schrödinger unidimensional en potencial armónico. Los pasos principales se describen brevemente a continuación;

1. Inicialización de variables: se definen el número de puntos (N), la distribución de x (x_min y x_max) y el grado de dx. La memoria se asigna en matrices x, v e y.

2. Definición de potencial; 
𝑉(𝑥) = 0,5 * x**2

3. Parámetros físicos: la energía E, la masa m y la constante reducida de Planck hbar son fijas.

4. Función numerov_method llamada: La función numerov_method (que se completará en el archivo numerov_method.h) se llama para resolver la ecuación de Schrödinger y obtener la función de onda y.

5. Normalización de la función de la onda: Se calcula y normaliza la norma de la función de la onda.

6. Guarda la solución: la solución (valores xey) se guarda en el archivo "solution.dat".

Este código le permite calcular y guardar la solución de la ecuación de Schrödinger para un oscilador armónico utilizando el método de Numerov.

## numerov_method.c:

1. Inicialización y asignación de memoria: la memoria se asigna en la matriz x, V, y.

2. Definición de potencial; 
𝑉(𝑥) = 0,5 * x**2

3. Llamada a numerov_method: La ecuación de Schrödinger se resuelve mediante el método de Numerov.

4. Normalización: la función de onda y está normalizada.

5. Guardar soluciones: La solución se guarda en el archivo "solution.dat".

6. Liberación de memoria: la memoria asignada ha sido liberada.

Esta función calcula la solución de la ecuación de Schrödinger utilizando el método de Numerov y la almacena en la coordenada y. La función numerov_method acepta como parámetro:

1. Matrices x y V que contienen el espacio de coordenadas y los valores de potencia respectivamente.

2. Los valores de energía E, masa m y la constante de Planck reducida hbar.

3. Organice y para almacenar la solución (función de onda).

4. Número de puntos N.

## numerov_method.h:
Incluye la implementación del método de Numerov, su uso en el programa principal y los archivos de capital necesarios para la definición de la función.

## numerov_method.py:
### Inicialización de parámetros:

1. m, omega, hbar: Masa, frecuencia angular y constante de Planck reducida.

2. x_min, x_max: toma el espacio local.

3. N: el número de puntos en el espacio establecido.

4. dx: la distancia de paso entre los puntos de posición.

### Definición de espacio del sitio:

1. x: una barra que contiene posiciones discretas.

2. V: El potencial armónico del oscilador en función de la posición.

### Construcción de la matriz hamiltoniana:

1. H: describe la matriz hamiltoniana de ese sistema.

### Cálculo de valores propios y vectores propios:

1. Valores propios, vectores propios: Valores propios y vectores propios de la matriz hamiltoniana.

2. Orden de valores propios y sus correspondientes vectores propios.

## Vizualización:
Se trazan formas de onda y densidades de probabilidad para los cuatro estados de primera cantidad.

## build:
Directorio vacío lleno de archivos de compilación generados por CMake.

# conclusión
Este proyecto demuestra cómo abordar un problema de oscilador armónico, implementando el método de Numerov en C para resolver la ecuación de Schrödinger e implementando los resultados usando Python. La implementación en C proporciona una base sólida para soluciones numéricas eficientes, mientras que el uso de Python permite una visualización clara y completa de las funciones de onda y sus densidades de probabilidad. Esta combinación de herramientas y metodologías enfatiza la importancia de integrar diferentes lenguajes de programación y técnicas numéricas para abordar problemas complejos en física cuántica.
