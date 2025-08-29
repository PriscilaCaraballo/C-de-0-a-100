#include <stdio.h>
#include <stdlib.h>

int main () {

    int *array;
    //aca va coma
    array = calloc(10, sizeof(int));
    if(array == NULL) {
        printf("error al reservar memoria");
        exit(1);
    }

    for(int i = 0; i < 10; i++) 
        // array[i] == *(array + i)
        printf("%i", array[i]);
    
        //todo cero, por que?
        //los inicializa en 0
    free(array);

}