#include <stdio.h>

/* El código original declaraba una nueva variable 'n' en el while loop (int n = n - 1) en lugar de modificar la existente (el parámetro).
 *
 * Además, la variable nunca fue inicializada, lo que causaba un comportamiento indefinido y un bucle infinito.
 *
 * La solución fue eliminar 'int' para modificar el parámetro 'n' directamente. */

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

int main(int argc, char *argv[]) {
    int fac4 = factorial(4);
    int fac5 = factorial(5);
    printf ("4! = %d, 5! = %d\n", fac4, fac5);
    return 0;
}
