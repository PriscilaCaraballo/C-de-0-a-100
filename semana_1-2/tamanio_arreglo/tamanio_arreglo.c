#include <stdio.h>

int main () {

    int sizeArray;  //creo un valor para el tamaño del array
    printf("Tamaño del arreglo (array) \n");  //pido el tamaño
    scanf ("%d", &sizeArray);  // lo guardo
    int tail[sizeArray]; // creo un array con el tamaño que pedi antes

    for (int i = 0; i < sizeArray; i++) // mientras el contaador 'i' sea manor al tamaño del array
    {
        printf("Ingresa el valor %d \n", i+1); //pido los valores que iran en el array
        scanf("%d", &tail[i]); //guardo esos valores en el array con el valor de i
    }

    printf ("Los valores del array son: \n"); //muestro los valores
    for (int i=0; i < sizeArray; i++) //mientras i sea menor al valor del array
    {
        printf ("- %d - ", tail[i]); //imprimo los valores del array segun x con el formato 1 - 2
    }
    return 0;
}