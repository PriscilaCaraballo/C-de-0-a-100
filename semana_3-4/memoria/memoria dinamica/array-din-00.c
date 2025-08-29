#include <stdio.h>
#include <stdlib.h>

int *crear_array(int size) {
    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("NO HAY MEMORIA");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: %d \n", i, arr[i]);
    }

    return arr;
}

int main () {
    printf("tamano?");
    int size;
    scanf("%d", &size);

    int *arr = crear_array(size);
    for( int i = 0; i < size; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;
}