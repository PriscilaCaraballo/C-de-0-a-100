#include <stdio.h>
int main() {

//ejemplo 1
int arr[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
printf("arr[%d] = %d, dirección = %p\n", i, arr[i], &arr[i]);
}

//ejemplo 2
int numeros[5] = {10, 20, 30, 40, 50};
printf("\n numeros = %p\n", numeros);
printf("&numeros[0] = %p\n", &numeros[0]);
printf("¿Son iguales?\n");
if (numeros == &numeros[0]) printf("SÍ\n");
else printf("NO\n");
printf("*numeros = %d\n", *numeros);
printf("numeros[0] = %d\n", numeros[0]);
printf("¿Son iguales?");
if (*numeros == numeros[0]) printf("SÍ\n");
else printf("NO\n");

//ejemplo 3
int arr3[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
printf("\n Tradicional: arr3[%d] = %d\n", i, arr3[i]);
printf("Punteros: *(arr3+%d) = %d\n", i, *(arr3 +
i));
printf("¿Son iguales?\n");
if (arr3[i] == *(arr3 + i)) printf("SÍ\n");
else printf("NO\n");
}

//ejemplo 4

return 0;
}