#include <stdio.h>

int main () {
int arr[5] = {10, 20, 30, 40, 50};
/*
int *ptr = arr;
printf("ptr apunta a: %d\n", *ptr); // 10
// Avanzar al siguiente
ptr++;
printf("ptr++ apunta a: %d\n", *ptr); // 20
// Avanzar 2 posiciones
ptr += 2;
printf("ptr+2 apunta a: %d\n", *ptr); // 40
// Retroceder 1
ptr--;
printf("ptr-- apunta a: %d\n", *ptr); // 30
}*/
int *inicio = arr;
int *fin = arr + 5; // Pasado el final
int *ptr = inicio;
while (ptr < fin) {
printf("Elemento: %d\n", *ptr);
ptr++;
} 
int arr2[10];
int *p1 = &arr2[2];
int *p2 = &arr2[7];
int distancia = p2 - p1; // 5 elementos
printf("Distancia: %d elementos\n",
distancia);
}

