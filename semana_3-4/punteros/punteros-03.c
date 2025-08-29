#include <stdio.h>

int main () {
    /*// ---EJEMPLO 1 ---
    int *punt; //cree un puntero
    int x = 7, y = 5; //valores
    punt = &x; //el punturo apunta a la direccion de x
    *punt = 4; //desreferencia de puntero a 4
    printf("%d, %d", x, y); //muestro, deberia mostrar 4, 5
    
    // ---EJEMPLO 2 ---
    int *punt; 
    int x = 7, y = 5;
    punt = &x;
    x = 4; //x vale 4 
    printf("%d, %d", *punt, y);  //direccion de x, 5
    //devolvió 4, ¿porque?
    //punt apunta a x. 
    //Luego cambié x = 4. Como punt sigue apuntando a x, *punt vale 4 también.


// ---EJEMPLO 3 ---
    int *punt;
    int x = 7, y = 5;
    punt = &x;
    x = 4;
    punt = &y; //TOMA EL VALOR DE Y
    printf("%d, %d", *punt, x); //deberia devoler 5, 4


// ---EJEMPLO 4 ---
    int *punt;
    int x = 7, y = 5;
    punt = &x;
    *punt = 3;  //x = 3
    punt = &y;
    *punt = x; //y = x, y = 3
    x = 9; 
    printf("%d, %d", *punt, x); //deberiA DEVOLVER x = 3, X = 9


// ---EJEMPLO 5 ---
    int *punta, *puntb;
    int x = 7, y = 5;
    punta = &x;
    *punta = 3; // x == 3
    puntb = &y;
    *puntb = x; // y == x; y = 3
    x = 9;
    printf("%d, %d", *puntb, x); //x = 3, 9
 */

// ---EJEMPLO 6 ---
    int *punta, *puntb;
    int x = 7, y = 5;
    punta = &x;
    *punta = 3; // x = 3
    puntb = &y; 
    *puntb = x; // x = y, y= 3
    x = 9;
    printf("%d, %d", *puntb, *punta); // deberia devolver 3, 3
    // sdevuelve 3, 9. punta apunta al valor de x que es 9 
}