#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definimos el tamaño de la matriz en un macro, para facilitar su modificación.
#define SIZE 3

// Función para determinar si una matriz cuadrada es un cuadrado mágico.
int determinarCuadradoMagico(int matrix[][SIZE]) {

    // Determinamos el valor tentativo de la suma mágica para una matriz cuadrada de tamaño dado, usando la primera fila.
    int sumaMagica = 0; // Declaramos e inicializamos una variable para la suma mágica.
    for (int j = 0; j < SIZE; j++) {
        sumaMagica += matrix[0][j];
    }

    // Verificamos la suma de cada fila 'i' y la comparamos con la suma mágica.
    for (int i = 0; i < SIZE; i++) {
        int sumaFila = 0; // Declaramos e inicializamos una variable para la suma de la fila actual.

        // Recorremos cada elemento (columna 'j') de la fila 'i' y sumamos sus valores.
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matrix[i][j];
        }
        // Comparamos la suma de la fila actual con la suma mágica.
        if (sumaFila != sumaMagica) {
            return 0; // No es un cuadrado mágico
        }
    }

    // Verificamos la suma de cada columna 'j' y la comparamos con la suma mágica.
    for (int j = 0; j < SIZE; j++) {
        int sumaColumna = 0; // Declaramos e inicializamos una variable para la suma de la columna actual.

        // Recorremos cada elemento (fila 'i') de la columna 'j' y sumamos sus valores.
        for (int i = 0; i < SIZE; i++) {
            sumaColumna += matrix[i][j];
        }
        // Comparamos la suma de la columna actual con la suma mágica.
        if (sumaColumna != sumaMagica) {
            return 0; // No es un cuadrado mágico
        }
    }

    // Verificamos la suma de la diagonal principal y la comparamos con la suma mágica.
    int sumaDiagonalPrincipal = 0; // Declaramos e inicializamos una variable para la suma de la diagonal principal.
    for (int i = 0; i < SIZE; i++) {
        sumaDiagonalPrincipal += matrix[i][i];
    }
    // Comparamos la suma de la diagonal principal con la suma mágica.
    if (sumaDiagonalPrincipal != sumaMagica) {
        return 0; // No es un cuadrado mágico
    }

    // Verificamos la suma de la diagonal secundaria y la comparamos con la suma mágica.
    int sumaDiagonalSecundaria = 0; // Declaramos e inicializamos una variable para la suma de la diagonal secundaria.
    for (int i = 0; i < SIZE; i++) {
        sumaDiagonalSecundaria += matrix[i][SIZE - 1 - i];
    }
    // Comparamos la suma de la diagonal secundaria con la suma mágica.
    if (sumaDiagonalSecundaria != sumaMagica) {
        return 0; // No es un cuadrado mágico
    }
    // Si todas las sumas coinciden, la matriz es un cuadrado mágico, y devolvemos 1.
    return 1;
}

// Función para mostrar matrices.
void mostrarMatriz(int matrix[][SIZE]) {
    // Recorremos cada fila 'i' de la matriz.
    for (int i = 0; i < SIZE; i++) {
        // Recorremos cada elemento (columna 'j') de la fila 'i' y lo mostramos en pantalla.
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Función para llenar una matriz con números aleatorios entre -10 y 10.
void llenarMatriz(int matrix[][SIZE]) {
    // Usamos la función 'srand' para definir la semilla usada al generar números aleatorios con la función 'rand'.
    // NOTA: time(NULL) devuelve el tiempo actual en segundos desde el 1 de enero de 1970 ("epoch time"), lo que garantiza que la semilla sea diferente cada vez que se ejecuta el programa.
    srand(time(NULL));
    // Recorremos cada fila 'i' de la matriz.
    for (int i = 0; i < SIZE; i++) {
        // Recorremos cada elemento (columna 'j') de la fila 'i' y le asignamos un número aleatorio entre -10 y 10, usando la función 'rand'.
        // NOTA: La función 'rand' genera números entre 0 y RAND_MAX, por lo que usamos el operador módulo (%) para limitar el rango.
        for (int j = 0; j < SIZE; j++) {
            // Generamos un número aleatorio entre -10 y 10 y lo asignamos a la posición correspondiente de la matriz.
            matrix[i][j] = (rand() % 21) - 10; // Números entre -10 y 10
        }
    }
}

// Función principal para probar la función determinarCuadradoMagico.
int main() {
    // Definimos una matriz de ejemplo para probar la función.
    int matrizEjemplo[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    // Mostramos la matriz utilizada como ejemplo.
    printf("\nLa matriz utilizada corresponde a:\n");
    mostrarMatriz(matrizEjemplo);
    printf("\n");

    // Llamamos a la función para determinar si la matriz es un cuadrado mágico.
    // NOTA: La función determinarCuadradoMagico devuelve 1 si es un cuadrado mágico y 0 en caso contrario.
    if (determinarCuadradoMagico(matrizEjemplo) == 1) {
        printf("La matriz es un cuadrado mágico.\n\n");
    } else {
        printf("La matriz no es un cuadrado mágico.\n\n");
    }

    // Definimos una segunda matriz vacía y la llenamos usando la función matrizAleatoria.
    // NOTA: Usamos valores entre -10 y 10 para aumentar la probabilidad de que la matriz sea un cuadrado mágico (en comparación con un rango más amplio).
    int matrizPrueba[SIZE][SIZE];
    llenarMatriz(matrizPrueba);

    // Mostramos la matriz generada aleatoriamente.
    printf("\nLa matriz utilizada corresponde a:\n");
    mostrarMatriz(matrizPrueba);
    printf("\n");

    // Llamamos a la función para determinar si la matriz es un cuadrado mágico.
    // NOTA: La función determinarCuadradoMagico devuelve 1 si es un cuadrado mágico y 0 en caso contrario.
    if (determinarCuadradoMagico(matrizPrueba) == 1) {
        printf("La matriz es un cuadrado mágico.\n\n");
    } else {
        printf("La matriz no es un cuadrado mágico.\n\n");
    }

    return 0;
}
