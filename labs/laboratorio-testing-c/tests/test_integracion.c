#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(){
    printf("\n[Se calculan bien totales y aplican los descuentos]\n");
    Carrito analizado;
    carrito_init(&analizado);
    Producto pan = {"pan",200,3};
    Producto leche = {"leche",350,2};
    carrito_agregar(&analizado,pan);
    carrito_agregar(&analizado,leche);
    int total = carrito_total(&analizado);
    ASSERT_IGUAL(1300,total);
    ASSERT_IGUAL(1170,carrito_descuento(total,10));
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(){
    printf("\n[Prueba carga y no pasar el maximo]\n");
    Carrito analizado;
    carrito_init(&analizado);
    Producto leche = {"leche",350,1};
    carrito_agregar(&analizado,leche);
    carrito_agregar(&analizado,leche);
    carrito_agregar(&analizado,leche);
    carrito_agregar(&analizado,leche);
    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&analizado));
    ASSERT_IGUAL(0,carrito_agregar(&analizado,leche));
    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&analizado));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
