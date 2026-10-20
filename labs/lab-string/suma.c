#include <stdio.h>
#include "Conversion.h"

/*
 * suma — imprime la suma de todos los argumentos interpretados como enteros.
 *
 * Uso: ./suma 1 2 3    →  6
 *      ./suma -5 10    →  5
 *
 * Pista: usa ToInteger de Conversion.h para convertir cada argumento.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    (void)argc; /* silenciamos el parámetro que no usamos*/

    int total = 0; /*acumulador */

    /* a partir del primer argumento*/
    for (char **arg = argv + 1; *arg != NULL; arg++) {
        /* Convertimos a entero y sumamos al total */
        total += ToInteger(*arg);
    }

    /* afuera del bucle imprimo el resultado*/
    printf("%d\n", total);
    return 0;
}
