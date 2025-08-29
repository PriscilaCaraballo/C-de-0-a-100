#include <stdio.h>

// Implementar usando SOLO aritmética de punteros
void estadisticas(int *arr, int tamano, int *min, int *max, float *prom) {
// TODO: Encontrar min, max y calcular promedio

// Solo usar aritmética de punteros
int suma = 0;

*min = *arr;
*max = *arr;

int *ptr = arr;
int *fin = arr + tamano;  //apunto al final

while (ptr < fin) {
suma += *ptr;
    if (*ptr < *min) {
        *min = *ptr; //nuevo minimo?????
    } else if (*ptr > *max) {
        *max = *ptr;
    }
ptr++;
}

*prom = suma / (float)tamano;
printf("Promedio: %f\n", *prom);
// No usar índices arr[i]
}
int main() {
int numeros[] = {15, 3, 27, 9, 42, 1, 33};
int min, max;
float prom;
estadisticas(numeros, 7, &min, &max, &prom);
printf("Min: %d, Max: %d, Promedio: %.2f\n", min, max, prom);
return 0;
}