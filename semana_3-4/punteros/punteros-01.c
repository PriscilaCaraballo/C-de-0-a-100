#include <stdio.h>

// Función que *intercambia* los valores de las variables originales
void intercambiar(int *a, int *b) { // Recibe direcciones (punteros)
    int temp = *a; // temp = valor al que apunta 'a'
    *a = *b;       // el valor en 'a' se cambia por el valor en 'b'
    *b = temp;     // el valor en 'b' se cambia por temp
}

int main() {
    int x = 10, y = 20;
    printf("Antes: x=%d, y=%d\n", x, y); // Salida: Antes: x=10, y=20

    intercambiar(&x, &y); // Pasamos las *direcciones* de x e y

    printf("Después: x=%d, y=%d\n", x, y); // Salida: Después: x=20, y=10
    
    printf("devuelta...\n");
    int z= 5, w=15;  
    printf("antes: z=%d, w=%d\n",z, w);  //valor 5, 15
    intercambiar(&z, &w);  
    //a= z y b=w
    //temp = *a el valor que apunta a = z = 5
    // *a = *b el valor de a = z =5 se cambia por b =w =15,  entonces a =z =15, b = w=15
    // *b = temp el valor de temp = z= 5 se cambia por b, entonces b = w = 5
    printf("despues: z=%d, w=%d",z ,w); //z = 15 y w = 5
    return 0; 
}