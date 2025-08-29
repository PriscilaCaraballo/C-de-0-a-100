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

 void mostrar_menu() {
        printf("\n ==| Calculadora en  C | == \n");
        printf ("1. Sumar \n");
        printf ("2. Restar \n");
        printf ("3. Multiplicacion \n");
        printf ("4. Division\n");
        printf ("5. Salir \n");
        printf ("Selecione una opcion: \n");
        printf (" ==|====================|== \n");
}
int main ()
{
    int opcion;
    float num1, num2, resultado;

    do {
        mostrar_menu();
        //si opcion no es un numero
        if(scanf("%d", &opcion) != 1 ){
            //imprimir entrada invalida
            printf ("Entrada invalida \n");
            //limpiar buffer
            while (getchar() != '\n');
             //continuar
            continue;
        }

    if (opcion >= 1 && opcion <= 4) {
        printf ("Ingrese el primer numero \n");
        while (scanf("%f", &num1) != 1 ){
            //imprimir entrada invalida
            printf ("Entrada invalida \n");
            //limpiar buffer
            while (getchar() != '\n');
        }
        printf ("Ingrese el segundo numero \n");
        while (scanf("%f", &num2) != 1 ){
            //imprimir entrada invalida
            printf ("Entrada invalida \n");
            //limpiar buffer
            while (getchar() != '\n');
        }
    }

    switch (opcion) {
    case 1:
        resultado = sumar(num1, num2);
        printf ("Resultado: %.2f \n", resultado);
    break;
    case 2:
        resultado = restar(num1, num2);
        printf ("Resultado: %.2f \n", resultado);
    break;
    case 3:
        resultado = multiplicar(num1, num2);
        printf ("Resultado: %.2f \n", resultado);
    break;
    case 4:
        resultado = dividir(num1, num2);
        printf ("Resultado: %.2f \n", resultado);
    break;
    case 5:
        printf ("Saliendo... \n");
    break;
    default:
        printf ("Ingresó invalido");
    break;
    }
     } while (opcion != 5);
     return 0;
}
