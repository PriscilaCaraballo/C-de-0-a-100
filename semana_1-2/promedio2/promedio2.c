#include <stdio.h>

int main() {
    float parcial1, parcial2;
    printf ("Ingrese el valor del primer parcial: \n");
    scanf("%f", &parcial1);
    printf ("Ingrese el valor del segundo parcial: \n");
    scanf("%f", &parcial2);

    int nota_final;
    nota_final = (parcial1 + parcial2);
    printf ("El promedio de los dos parciales es: %d", nota_final);
    if (nota_final > 60) {
        printf ("\n exoneraste la materia maquina"); 
    }else if (nota_final == 60) {
        printf("\n pasaste raspando master");
    } else if ((nota_final <= 60 && nota_final >= 25) ) {
        printf ("\n te vas a examen bobolon");
    } else {
        printf ("\n deja la carrera idiota");
    }
    // cuando promedio sea mayor a 60
    return 0;
}
