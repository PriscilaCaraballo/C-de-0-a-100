#include <stdio.h>

float sumar(float num1p, float num2p){
    return num1p + num2p;
}

float restar(float num1p, float num2p){
    return num1p - num2p;
}

float multiplicar(float num1p, float num2p){
    return num1p * num2p;
}

float dividir(float num1p, float num2p){
    if (num2p == 0) {
        printf ("Es invalido dividir por 0 ");
        return 0;
    }
    return num1p / num2p;
}