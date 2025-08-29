#include <stdio.h>

float num = 0, 
    suma = 0,
    cant_num = 0,
    promedio = 0
;

int main () {

printf ("Ingrese los numeros a promediar (ingrese 0 para dejar de ingresar numeros) \n");

while (1)
{
    num != 0;
    scanf ("%f", &num);

    if (num == 0)
    break;

    suma += num;
    cant_num++;
}

if (cant_num > 0) {
    promedio = suma / cant_num ;
    printf ("El promedio de los numeros ingresados es: %.2f \n", promedio);
} else {
    printf ("No ingresastes nada, que carajo queres que promedie asi");
}

}3