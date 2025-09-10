#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Agrega un estudiante al curso
int agregar_estudiante(Curso *curso, const char *nom, int ed, float alt, char gen) {
    if (curso->cantidad >= curso->capacidad)
    {
        printf("curso lleno");
        return 1;
    }


    strcpy(curso->estudiantes[curso->cantidad].nombre, nom);
    curso->estudiantes[curso->cantidad].edad = ed;
    curso->estudiantes[curso->cantidad].altura = alt;
    curso->estudiantes[curso->cantidad].genero = gen;
    
    curso->cantidad++;
    return 0;

}

// Busca un estudiante por nombre
Estudiante* buscar_estudiante(Curso *curso, const char *nombre) {
    for (int i = 0; i < curso->cantidad; i++) {
        if (strcmp(curso->estudiantes[i].nombre, nombre)){
            return &curso->estudiantes[i];
        }
    
    }
    return NULL;
}

int main () {
    int capacidad;
    printf("Ingrese la capacidad del curso: ");
    scanf("%d", &capacidad);

    Curso *curso = crear_curso(capacidad);
    if (curso == NULL) return 1;

    char nombre[51];
    int edad;
    float altura;
    char genero;
    int resultado;

    while (curso->cantidad < curso->capacidad) {
        printf("\nIngrese el nombre del estudiante (max 49 caracteres): ");
        scanf(" %[^\n]", nombre);

        if (strlen(nombre) >= 50) {
            printf("Nombre demasiado largo, intente nuevamente.\n");
            continue;
        }

        printf("Ingrese la edad: ");
        scanf("%d", &edad);
        printf("Ingrese la altura: ");
        scanf("%f", &altura);
        printf("Ingrese el genero (M/F): ");
        scanf(" %c", &genero);

        resultado = agregar_estudiante(curso, nombre, edad, altura, genero);
        if (resultado == 1) {
            printf("Curso lleno, no se puede agregar más estudiantes.\n");
            break;
        } else {
            printf("Estudiante agregado con éxito.\n");
        }
    }

    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < curso->cantidad; i++) {
        printf("%d. %s, %d años, %.2f m, %c\n", 
        i + 1,
        curso->estudiantes[i].nombre,
        curso->estudiantes[i].edad,
        curso->estudiantes[i].altura,
        curso->estudiantes[i].genero);
    }

    char nombre_buscar[51];
    printf("nombre del estudiante a buscar: \n");
    scanf(" %[^\n]", nombre_buscar);

    Estudiante *busqueda = buscar_estudiante(curso, nombre_buscar);
    if (busqueda != NULL) {
        printf("Estudiante encontrado: %s, %d años, %.2f m, %c\n", 
        busqueda->nombre,
        busqueda->edad,
        busqueda->altura,
        busqueda->genero);
    } else {
        printf("Estudiante no encontrado.\n");
    }

    //borrar despues
    free(curso->estudiantes);
    free(curso);
    return 0;
}
