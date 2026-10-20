#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    (void)argc; /* aca tenemos el buen uso del (void)argc como habia dicho en el punto anterior*/

    /* no se pasaron argumentos*/
    if (argv[1] == NULL) {
        printf("1\n");
        return 0;
    }

    int iguales = 1; /*por default los ponemos a todos como iguales*/

    /* partir del segundo argumento real (argv + 2) */
    for (char **arg = argv + 2; *arg != NULL; arg++) {
        
        /* Comparamos con el primero (argv[1]) */
        if (!AreEqual(argv[1], *arg)) {
            iguales = 0; /* Encontramos una diferencia, la bandera pasa a falso (0) */
            break;
        }
    }

    printf("%d\n", iguales);
    return 0;
}
