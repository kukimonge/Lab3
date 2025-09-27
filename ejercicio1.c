#include <stdio.h>

/* El código original declaraba una nueva variable 'n' en el while loop (int n = n - 1) en lugar de modificar la existente (el parámetro).
 *
 * Además, la variable nunca fue inicializada, lo que causaba un comportamiento indefinido y un bucle infinito.
 *
 * La solución fue eliminar 'int' para modificar el parámetro 'n' directamente. */

// Función para calcular el factorial de un número de forma iterativa.
// NOTA: La función devuelve 1 para 0! y 1!, que es el comportamiento esperado.
long factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

// Función principal que solicita al usuario un número y muestra su factorial.
int main(void) {
    int numero; // Variable para almacenar el número ingresado por el usuario.
    printf("Introduzca un número entero no negativo:\n");
    scanf("%d", &numero);
    if (numero < 0) {
        printf("Error: El número debe ser no negativo.\n");
    } else {
        unsigned long resultado = factorial(numero);
        printf("El factorial de %d es %lu\n", numero, resultado);
    }
}
