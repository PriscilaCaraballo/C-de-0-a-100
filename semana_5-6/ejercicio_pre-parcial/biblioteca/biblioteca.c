#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
    float altura;
    char genero;
} Estudiante;

typedef struct {
    Estudiante *estudiantes;
    int cantidad;
    int capacidad;
} Curso;

// Crea un curso con capacidad inicial dada
Curso* crear_curso(int capacidad_inicial) {
    if (capacidad_inicial < 0)
    {
        printf("no es poscible crear un curso con capacidad negativa");
        return NULL;
    }
    
    //pedir memoria para el curso
    Curso *c = malloc(sizeof (Curso));
    if (c == NULL)
    {
        printf ("error al asignar memoria con malloc");
        return NULL;
    }
    
    c ->estudiantes = malloc(sizeof(Estudiante) * capacidad_inicial);
    if (c->estudiantes == NULL)
    {
        printf ("error al asignar memoria con malloc");
        free(c);
        return NULL;
    }

    c->capacidad = capacidad_inicial;
    c->cantidad = 0;

    return c;

}

