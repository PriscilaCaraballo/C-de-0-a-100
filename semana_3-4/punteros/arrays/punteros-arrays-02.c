#include <stdio.h>
//recorrer arrays
//metodo 1. por indice
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
int suma = 0;
/*for (int i = 0; i < 5; i++) {
suma += arr[i];
}
printf("Suma: %d\n", suma);

for (int i = 0; i < 5; i++) {
suma += *(arr + i);
}
printf("Suma 2: %d\n", suma);

//metodo 2. punteros 
int *ptr = arr;
for (int i = 0; i < 5; i++) {
suma += *ptr;
ptr++; // Avanzar al siguiente
}
printf("Suma3: %d\n", suma);
}*/

//Método con punteros (estilo 3):
int *ptr = arr;
int *fin = arr + 5; // Puntero al final
while (ptr < fin) {
suma += *ptr;
ptr++;
}
printf("Suma4: %d\n", suma);
}