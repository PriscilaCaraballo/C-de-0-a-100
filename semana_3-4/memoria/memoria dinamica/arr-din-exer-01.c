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
int p;
    for (int i = 0; i < tamano; i++)
    {
        do
        {
            printf("en que posicion del array?\n");
            printf("valores posibles entre 0 y %d  \n",tamano-1);
            scanf("%d", &p);
            if (p < 0 || p >= tamano)
            {
                printf("pusiste una posicion no validad mi rey\n");
            }
        } while (p < 0 || p >= tamano);
        printf("¿Con que vas a llenar el array pa? \n");
        scanf("%d", &arr[p]);
    }
}

void imprimir_array(int *arr, int tamano){
    for (int i = 0; i < tamano; i++) {
        printf("arr[%d] = %d \n",i, arr[i]);
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
        printf ("error al asignar memoria con realloc");
        return NULL;
    } 


    return nuevo_arr;
}

int* eliminar(int *arr, int tamano) {
    int posicion;
    do {
        printf("¿que posicion del array quieres eliminar?(0 a %d) \n", tamano-1);
        scanf("%d", &posicion);
        if (posicion < 0 || posicion >= tamano) {
            printf("la posicion que pedis eliminar es invalida querido\n");
        } 
    } while (posicion < 0 || posicion >= tamano);
            for (int i = posicion; i < tamano - 1; i++)
            {
                arr[i] =  arr[i+1];
            }
    //  arr[tamano - 1] = -1; //solo para marcar que ya no hay valor
    //arr[posicion] = -1;  //""eliminado""
    int *arr_eliminado = realloc(arr, (tamano-1) * sizeof(int));
    if(arr_eliminado == NULL) {
        printf ("error al asignar memoria con realloc");
        return arr;
    } 

    return arr_eliminado;
}

//funcion busqueda
int busqueda(int *arr, int tamano, int valor) {
    for (int i = 0; i < tamano; i++)
    {
        if (arr[i] == valor)
        {
            printf("Lo encontre en la posicion: %d \n", i);
            return i;
        } 
        
    }
    return -1;
    
}

void ordenar(int *arr, int tamano, int forma) {
int cambio;
        for (int i = 0; i < tamano-1; i++)
        {
            int min = i;
            for (int p = i+1; p < tamano; p++)
            {
                if(forma == 1) {
                    if (arr[p] < arr[min])
                    {
                        min = p;
                    }
                }
                if(forma == 2) {
                    if (arr[p] > arr[min])
                    {
                        min = p;
                    }
                }
            } 
            //arr[i] == 0
            //cambio y array[i] = 0
            cambio = arr[i]; 
            //arr[min] = -1
            //arr[i] = -1
            arr[i] = arr[min];
            //cambio = 0
            //arr[min] = 0
            arr[min] = cambio;
            
        }
        
}

void mostrar_menu(){
    printf("-----------------------\n");
    printf("|  -  SERVICIOS  -    |\n");
    printf("| 1. LLENAR ARRAY     |\n");
    printf("| 2.ELIMINAR ELEMENTOS|\n");
    printf("| 3.AGRANDAR ARRAY    |\n");
    printf("| 4.REALIZAR BUSQUEDA |\n");
    printf("| 5.ORDENAR ARRAY     |\n");
    printf("-----------------------\n");
    printf("Seleccionar cualquier\n
    otro numero te hara salir del menu\n");
}

int main() {
    int n;
    int opcion;
    printf("Tamaño del array: ");
    scanf("%d", &n);
    int *numeros = crear_array(n);
    // Completar programa...

    while (1) { 
        mostrar_menu();
        //si opcion no es un numero
        if(scanf("%d", &opcion) != 1 ){
            //imprimir entrada invalida
            printf ("Entrada invalida \n");
            //limpiar buffer
            while (getchar() != '\n');
             //continuar
            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("vamos a llenar ese array papu.. \n");
            llenar_array(numeros, n);

            printf("aca esta tu array llenito pa: \n");
            imprimir_array(numeros, n);
            break;
        
        case 2:
            printf("quieres eliminar elementos del array?\n");
            printf("Y[yes] / N[no]\n");
            char y;
            scanf(" %c", &y);
            if(y == 'Y' || y == 'y') {
                numeros = eliminar(numeros, n);
                n = n - 1;
                imprimir_array(numeros, n);
            }
            break;
        case 3:
            //funcioona agragar o agrandar array
            printf("quieres agrandar el array?\n");
            printf("Y[yes] / N[no]\n");
            char v;
            scanf(" %c", &v);
            int new_n;
            if(v == 'Y' || v == 'y') {
                
                printf("Tamaño del nuevo array (incluido el tamañon anterior)\n");
                scanf("%d", &new_n);

                while (new_n <= n) {
                    printf("El nuevo tamaño debe ser mayor que el actual\n");
                    scanf("%d", &new_n);
                }

                numeros = crear_array_grande(numeros, new_n);
                //numeros = nuevo_arr;

                for(int i = n; i < new_n; i++) {
                    printf("¿Con qué vas a llenar el nuevo elemento? \n");
                    scanf("%d", &numeros[i]);
                }
                imprimir_array(numeros, new_n);
                n = new_n;
            }
            break;
        case 4:
            printf("queres realizar una busqueda?\n");
            printf("Y[yes] / N[no]\n");
            char x;
            int valor;
            scanf(" %c", &x);
            if(x == 'Y' || x == 'y') {
                printf("que queres buscar corazon (valor)? \n");
                scanf("%d", &valor);
                int resultado = busqueda(numeros, n, valor);
                if (resultado == -1) {
                    printf("no esta ese valor en el array bobolon\n");
                }
            }
            break;
        case 5:
            printf("Ordenamos el array de forma ascendente[1]\n o de forma descendete[2]?\n");
            int forma;
            scanf("%d", &forma);
            ordenar(numeros, n, forma);
            printf("Nuevo array ordenado: " );
            imprimir_array(numeros, n);
            break;
        default:
            printf("Saliendo del programa...\n");
            printf("\n vamos a liberar ese array");
            liberar_array(numeros);
            return 0;
        }
    }
}
