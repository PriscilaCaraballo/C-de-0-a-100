#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; // tamaño inicial
    int *array = malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Pedir los primeros 5 valores
    for (int i = 0; i < n; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Redimensionar el array a 10
    int nuevos = 5;
    array = realloc(array, (n + nuevos) * sizeof(int));
    if (array == NULL) {
        printf("Error al redimensionar memoria\n");
        return 1;
    }

    // Pedir los 5 valores adicionales
    for (int i = n; i < n + nuevos; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Imprimir los 10 valores
    printf("Valores en el array: ");
    for (int i = 0; i < n + nuevos; i++) {
        printf("%d ", array[i]);
    }

    free(array); // liberar memoria
    return 0;
}
