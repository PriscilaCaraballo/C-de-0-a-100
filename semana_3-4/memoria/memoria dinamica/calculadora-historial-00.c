#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **operaciones; // Array dinámico de punteros a string
    int cantidad;       // Cuántos strings tiene actualmente
    int capacidad;      // Tamaño máximo reservado
} Historial;

// TODO: Implementar 
Historial* crear_historial() {
    Historial *h = malloc(sizeof *h);
    if(h == NULL){
        printf("error al usar malloc");
        return NULL;
    }
    h -> capacidad = 2;
    h -> cantidad = 0;
    h -> operaciones = (char**) malloc(h->capacidad * sizeof(char*));
    if(h->operaciones == NULL){
        printf("error al usar malloc");
        free(h);
        return NULL;
    }

    return h;

}

void agregar_operacion(Historial *h, char *op) {
    if(h->cantidad == h->capacidad) {
        int nueva_capacidad = h->capacidad * 2;
        char **new_dates = realloc(h->operaciones, nueva_capacidad * sizeof(char*));
        if(new_dates == NULL){
            printf("error al usar realloc");        
            return;
        }
        h->operaciones = new_dates;
        h->capacidad = nueva_capacidad;
    }
        //como mierd copio 
        h->operaciones[h->cantidad] = malloc(strlen(op) + 1);
        if(h->operaciones[h->cantidad] == NULL) {
             printf("error al usar malloc\n");
        return;
        }
        strcpy(h->operaciones[h->cantidad], op);
        //error
        h->cantidad++;
    
    //strdup
}

void mostrar_historial(Historial *h){

    if(h == NULL || h->cantidad == 0){
        printf("esta vacio el historical");
        return;
    }

    printf("Historial de operaciones:\n");
    for (int i = 0; i < h->cantidad ; i++)
    {
        printf("%d: %s \n", i+1, h->operaciones[i] );
    }
    
} 

void liberar_historial(Historial *h){
    for (int i = 0; i < h->cantidad; i++) {
        free(h->operaciones[i]);
    }
    free(h->operaciones);
    free(h);
    h = NULL;
}

int main () {
        Historial *h = crear_historial();
        if(h == NULL) {
            printf("No se pudo crear historial.\n");
            printf("MANEJATE");
            return 1;
        }
        char opcion;
        do {
            printf("¿queres agregar operaciones? ");
            printf("Si [S] / No [N] \n");
            scanf(" %c", &opcion);

            if (opcion == 'S' || opcion == 's')
            {
                char operacion[100];
                printf("operacion a agregar:");
                scanf(" %99[^\n]", operacion);
                agregar_operacion(h, operacion);
            }
            
        } while (opcion == 'S' || opcion == 's');
            mostrar_historial(h);
            liberar_historial(h);
        }
