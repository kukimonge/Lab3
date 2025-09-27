#include <stdio.h>

// Función para calcular el factorial de un número de forma iterativa.
// NOTA: La función devuelve 1 para 0! y 1!, que es el comportamiento esperado.
unsigned long calcularFactorial(unsigned int n) {
    unsigned long factorial = 1; // Variable para procesar el resultado del factorial.
    while (n > 1) {
        factorial = factorial * n;
        n = n - 1;
    }
    return factorial;
}

// Función principal para solicitar un número al usuario y mostrar su factorial.
int main(void) {
    unsigned int numero; // Variable para almacenar el número ingresado por el usuario.
    char sobrante; // Variable para detectar caracteres no numéricos en la entrada.
    printf("\nIngrese un número entero no negativo para calcular su factorial: ");

    // Mostramos un mensaje de error si la entrada no es válida. Esto nos permite manejar entradas que comienzan con caracteres no numéricos o números negativos.
    if (scanf("%u", &numero) != 1) {
        printf("ERROR: Debe ingresar un número válido.\n\n");
    }
    // Mostramos un mensaje de error si el número es válido pero hay caracteres no numéricos adicionales en la entrada.
    else if (scanf("%c", &sobrante) == 1 && sobrante != '\n') {
        printf("ERROR: La entrada contiene caracteres no numéricos.\n\n");
    }
    // Mostramos un mensaje de error si el número ingresado es mayor a 20, para evitar desbordamientos en el cálculo del factorial.
    else if (numero > 20) {
        printf("ERROR: El número es demasiado grande. Ingrese un número menor o igual a 20.\n\n");
    }
    // Si la entrada es válida, calculamos y mostramos el factorial del número ingresado.
    else {
        printf("%u! = %lu\n\n", numero, calcularFactorial(numero));
    }
    return 0;
}

// El código original declaraba una nueva variable 'n' en el while loop de la función 'factorial', en lugar de utilizar el parámetro 'n'. (int n = n - 1)
// Como consecuencia, esa nueva variable nunca se inicializaba, lo que causaba un comportamiento indefinido y un bucle infinito.
// La solución fue eliminar 'int' para modificar el parámetro 'n' directamente.
