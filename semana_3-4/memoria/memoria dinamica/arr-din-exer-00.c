#include <stdlib.h>
#include <stdio.h>

// Implementar estas funciones
int* crear_array(int tamano){
    // n = tamano;
    //n = 5; tamano = 5
    //numero y arr apuntan al mismo bloque de memoria

    int *arr = malloc(tamano * sizeof(int));
    if(arr == NULL) {
        printf ("error al asignar memoria con malloc");
        return NULL;
    } 
    return arr;
}
    
void llenar_array(int *arr, int tamano) {
for (int i = 0; i < tamano; i++)
    {
        printf("¿Con que vas a llenar el array pa? \n");
        scanf("%d", &arr[i]);
        printf("Perfecto rey...\n");
    }
}

void imprimir_array(int *arr, int tamano){
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arr[i]);
    }
}

void liberar_array(int *arr){
    free(arr);
    //mariantips
    arr = NULL;
}

int* crear_array_grande(int *arr, int nuevo_tamano){
    int *nuevo_arr = realloc(arr, nuevo_tamano * sizeof(int));
    if(nuevo_arr == NULL) {
        printf ("error al asignar memoria con malloc");
        return NULL;
    } 

    return nuevo_arr;
}

int main() {
    int n;
    printf("Tamaño del array: ");
    scanf("%d", &n);
    int *numeros = crear_array(n);
    // Completar programa...

    printf("vamos a llenar ese array papu.. \n");
    llenar_array(numeros, n);

    printf("aca esta tu array llenito pa: \n");
    imprimir_array(numeros, n);


    printf("quieres agrandar el array?\n");
    
    printf("Y[yes] / N[no]\n");
    char v;
    scanf(" %c", &v);
    int new_n;
    if(v == 'Y') {
        
        printf("Tamaño del nuevo array (incluido el tamañon anterior)\n");
        scanf("%d", &new_n);
        numeros = crear_array_grande(numeros, new_n);
        //numeros = nuevo_arr;

        for(int i = n; i < new_n; i++) {
            printf("¿Con qué vas a llenar el nuevo elemento? \n");
            scanf("%d", &numeros[i]);
        }
        imprimir_array(numeros, new_n);
    } 

    printf("\n vamos a liberar ese array");
    liberar_array(numeros);
    return 0;
}