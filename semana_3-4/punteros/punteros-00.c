#include <stdio.h>

int main() {
    // Paso 1: Variable normal
    int x = 5;
    printf("x inicial = %d\n", x);

    // Paso 2: Crear puntero
    int *ptr = &x;
    printf("ptr apunta a dirección %p\n",
    ptr);
    
    // Paso 3: Modificar via puntero
    *ptr = 10;
    printf("x después de *ptr = 10: %d\n",
    x);
    return 0;
}

