#include <stdio.h>

#define SIZE 3

int determinarCuadradoMagico(int matrix[][SIZE]) {
    // Determinamos el valor esperado de la suma mágica para una matriz cuadrada de tamaño dado.
    int sumaMagica = SIZE * (SIZE * SIZE + 1) / 2;

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

int main() {
    int matrix[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };
    return 0;
}
