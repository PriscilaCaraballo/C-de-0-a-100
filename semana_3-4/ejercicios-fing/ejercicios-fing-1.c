#include <stdio.h>

float PromClase(float puntaje1, float puntaje2, float puntaje3, float puntaje4,  float puntaje5){
    float min = puntaje1;
    if (puntaje2 < min){
        min = puntaje2;
    }
    if (puntaje3 < min){
        min = puntaje3;
    }
    if (puntaje4 < min){
        min = puntaje4;
    }
    if (puntaje5 < min){
        min = puntaje5;
    }

    float suma = puntaje1 + puntaje2 + puntaje3 + puntaje4 + puntaje5;
    return (suma-min)/4.00;
}

int main () {
    float puntaje1, puntaje2, puntaje3, puntaje4, puntaje5;
    printf("Ingrese la primera calificación: \n");
    scanf("%f", &puntaje1 );
    printf("Ingrese la segunda calificación: \n");
    scanf("%f", &puntaje2 );
    printf("Ingrese la tercera calificación: \n");
    scanf("%f", &puntaje3 );
    printf("Ingrese la cuarta calificación: \n");
    scanf("%f", &puntaje4 );
    printf("Ingrese la quinta calificación: \n");
    scanf("%f", &puntaje5 );

    float prom = PromClase(puntaje1, puntaje2, puntaje3, puntaje4, puntaje5);
    printf("El promedio de las 4 calificaciones mas altas es: %.2f\n ", prom);
    return 0;
}