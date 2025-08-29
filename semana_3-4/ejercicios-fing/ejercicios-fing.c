#include <stdio.h>
//  5 calificaciones y agarrar las 4 mas altas
// Escribir una función llamada PromClase con cinco parámetros de entrada (las calificaciones obtenidas) que realice dicho cálculo y lo devuelva
void puntajes (int *puntaje, int tamano, int *min, float *prom){
int suma = 0;
*min = *puntaje;
int *ptr = puntaje; 
int *fin = puntaje + tamano;

//recorrer
while (ptr < fin) {
    suma += *ptr;
    if (*ptr < *min) {
        *min = *ptr;
    }
ptr++;
}

 *prom = (suma - *min) / 4.00;
}

int main() {
    int notas[] = {15, 15, 99, 14, 42};
    int min;
    float prom;
    puntajes(notas, 5, &min, &prom);
    printf("Promedio: %.2f\n", prom); 
    return 0;
}