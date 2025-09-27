#include <stdio.h>

// Función para calcular el factorial de un número de forma iterativa.
// NOTA: La función devuelve 1 para 0! y 1!, que es el comportamiento esperado.
unsigned long calcularFactorial(int n) {
    unsigned long factorial = 1; // Variable para procesar el resultado del factorial.
    while (n > 1) {
        factorial = factorial * n;
        n = n - 1;
    }
    return factorial;
}

// Función principal para solicitar un número al usuario y mostrar su factorial.
int main(void) {
    int numero; // Variable para almacenar el número ingresado por el usuario.
    printf("\nIngrese un número entero no negativo: ");
    scanf("%d", &numero);
    if (numero < 0) {
        // Mostramos un mensaje de error si el número es negativo.
        printf("ERROR: El número ingresado no puede ser negativo.\n");
    } else {
        // Calculamos y mostramos el factorial del número ingresado.
        unsigned long resultado = calcularFactorial(numero);
        printf("El factorial de %d es %lu\n\n", numero, resultado);
    }
    return 0;
}

// El código original declaraba una nueva variable 'n' en el while loop de la función 'factorial', en lugar de utilizar el parámetro 'n'. (int n = n - 1)
// Como consecuencia, esa nueva variable nunca se inicializaba, lo que causaba un comportamiento indefinido y un bucle infinito.
// La solución fue eliminar 'int' para modificar el parámetro 'n' directamente.
