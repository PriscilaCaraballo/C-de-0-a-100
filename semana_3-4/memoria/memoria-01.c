#include <stdlib.h>
#include<stdio.h>

int* crear_array_bueno(int tamano) {
    int *arr = malloc(tamano * sizeof(int));
       
    if (arr != NULL) {
        // Inicializar el array
        for (int i = 0; i < tamano; i++) {
            arr[i] = i + 1;
        }
    }
 return arr; // Seguro: memoria en heap
}

int main() {
    int *resultado = crear_array_bueno(5);
    
    if (resultado != NULL) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", resultado[i]);
        }
        // Liberar cuando termine
        free(resultado);
    }

    return 0;
}
