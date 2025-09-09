#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **operaciones; // Array dinámico de punteros a string
    int cantidad;       // Cuántos strings tiene actualmente
    int capacidad;      // Tamaño máximo reservado
} Historial;

// Funciones de historial
Historial* crear_historial() {
    Historial *h = malloc(sizeof *h);
    if(h == NULL){
        printf("Error al usar malloc\n");
        return NULL;
    }
    h->capacidad = 2;
    h->cantidad = 0;
    h->operaciones = malloc(h->capacidad * sizeof(char*));
    if(h->operaciones == NULL){
        printf("Error al usar malloc\n");
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
            printf("Error al usar realloc\n");        
            return;
        }
        h->operaciones = new_dates;
        h->capacidad = nueva_capacidad;
    }
    h->operaciones[h->cantidad] = malloc(strlen(op) + 1);
    if(h->operaciones[h->cantidad] == NULL) {
        printf("Error al usar malloc\n");
        return;
    }
    strcpy(h->operaciones[h->cantidad], op);
    h->cantidad++;
}

void mostrar_historial(Historial *h){
    if(h == NULL || h->cantidad == 0){
        printf("El historial está vacío\n");
        return;
    }
    printf("\nHistorial de operaciones:\n");
    for (int i = 0; i < h->cantidad ; i++)
        printf("%d: %s\n", i+1, h->operaciones[i]);
}

void liberar_historial(Historial *h){
    for (int i = 0; i < h->cantidad; i++)
        free(h->operaciones[i]);
    free(h->operaciones);
    free(h);
}

// Funciones de calculadora
float sumar(float a, float b){ return a + b; }
float restar(float a, float b){ return a - b; }
float multiplicar(float a, float b){ return a * b; }
float dividir(float a, float b){
    if(b == 0){
        printf("Error: división por 0\n");
        return 0;
    }
    return a / b;
}

void mostrar_menu() {
    printf("\n==| Calculadora |==\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Salir\n");
    printf("6. Ver historial\n");
    printf("Seleccione una opción: ");
}

int main() {
    int opcion;
    float num1, num2, resultado;
    Historial *h = crear_historial();
    if(h == NULL) return 1;

    do {
        mostrar_menu();
        if(scanf("%d", &opcion) != 1){
            printf("Entrada inválida\n");
            while(getchar() != '\n');
            continue;
        }

        if(opcion >= 1 && opcion <= 4){
            printf("Ingrese el primer número: ");
            while(scanf("%f", &num1) != 1){
                printf("Entrada inválida\n");
                while(getchar() != '\n');
            }
            printf("Ingrese el segundo número: ");
            while(scanf("%f", &num2) != 1){
                printf("Entrada inválida\n");
                while(getchar() != '\n');
            }
        }

        char registro[100];
        switch(opcion){
            case 1:
                resultado = sumar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                sprintf(registro, "%.2f + %.2f = %.2f", num1, num2, resultado);
                agregar_operacion(h, registro);
                break;
            case 2:
                resultado = restar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                sprintf(registro, "%.2f - %.2f = %.2f", num1, num2, resultado);
                agregar_operacion(h, registro);
                break;
            case 3:
                resultado = multiplicar(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                sprintf(registro, "%.2f * %.2f = %.2f", num1, num2, resultado);
                agregar_operacion(h, registro);
                break;
            case 4:
                resultado = dividir(num1, num2);
                printf("Resultado: %.2f\n", resultado);
                sprintf(registro, "%.2f / %.2f = %.2f", num1, num2, resultado);
                agregar_operacion(h, registro);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            case 6:
                mostrar_historial(h);
                break;
            default:
                printf("Opción inválida\n");
        }
    } while(opcion != 5);

    liberar_historial(h);
    return 0;
}
