#include <stdio.h>
#include <string.h>

//crear struct
typedef struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
 } Estudiante;

//(*p) === p->
void print_data(struct Estudiante *p){
    printf("%s %d %.2f", (*p).nombre, (*p).edad, (*p).promedio);
}

int main () {
    //asignacion
    Estudiante persona1;
    //strcpy SOLO PARA STRINGS
    strcpy(persona1.nombre, "Ana Martinez");
    persona1.edad = 18;
    persona1.promedio = 9.0;

    print_data(&persona1);
}  

