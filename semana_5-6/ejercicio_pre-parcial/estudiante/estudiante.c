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
    if (capacidad_inicial <= 0)
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
    if (strlen(nom) == 0 || strlen(nom) >= 50) {
        printf("Nombre invalido.\n");
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
    if (curso == NULL || curso->cantidad == 0) {
        printf("No hay estudiantes en el curso.\n");
        return NULL;
    }

    for (int i = 0; i < curso->cantidad; i++) {
        if (strcmp(curso->estudiantes[i].nombre, nombre) == 0){
            return &curso->estudiantes[i];
        }
    }
    return NULL;
}

// Retorna el estudiante de mayor edad
Estudiante* estudiante_mayor_edad(Curso *curso) {
    if (curso->cantidad == 0) return NULL;

    int mayor_edad = curso->estudiantes[0].edad;
    Estudiante *estudiante_mayor = &curso->estudiantes[0];
    for (int i = 0; i < curso->cantidad; i++) {
        if (curso->estudiantes[i].edad > mayor_edad){
            mayor_edad = curso->estudiantes[i].edad;
            estudiante_mayor = &curso->estudiantes[i];
        }
    }
     return estudiante_mayor;
}

// Retorna el promedio de edades del curso
float promedio_edades(Curso *curso) {

    float conteo = 0;
    for (int i = 0; i < curso->cantidad; i++) {
            conteo += curso->estudiantes[i].edad;
    }
    if (curso->cantidad == 0) {
        printf("No hay estudantes.");
        return -1;
    }
    
    float resultado = conteo / curso->cantidad;
    return resultado;
}

// Retorna la cantidad de estudiantes de un género específico
int contar_por_genero(Curso *curso, char genero) {
    //recorrer todo el array, si genero es igual a M sumar 1 a masculino ysino sumar 1 a femenino
    if (curso->cantidad == 0) return -1;

    int suma_genero = 0;
    for (int i = 0; i < curso->cantidad; i++) {
            if (curso->estudiantes[i].genero == genero)
            {
                suma_genero++;
            }
        
    }
    return suma_genero;
}

// Elimina un estudiante del curso por nombre
int eliminar_estudiante(Curso *curso, const char *nombre) {
    if (curso == NULL || curso->cantidad == 0) {
        printf("No hay estudiantes en el curso.\n");
        return 1;
    }
    //pido el nombre, lo busco comparaando el nombre con el strcmp y cuando lo encuentro lo elimino
    //tomo a la posicion i (donde estoy) y lo cambio por el de alado, hasta el final y bajo la cantidad en 1
    for (int i = 0; i < curso->cantidad; i++) {
        if (strcmp(curso->estudiantes[i].nombre, nombre) == 0){
            for (int cambio = i; cambio < curso->cantidad - 1 ; cambio++)
            {
                curso->estudiantes[cambio] = curso->estudiantes[cambio + 1];
            }
            curso->cantidad--; 
            return 0;
        }
       
    }
    return 1;
}

// Ordena los estudiantes por edad (menor a mayor)
void ordenar_por_edad(Curso *curso){
    if (curso->cantidad == 0) {
        printf("array vcaio.");
    }

    for (int i = 1; i < curso->cantidad; i++) {
        Estudiante temp = curso->estudiantes[i];
        int j = i - 1;
        while (j >= 0 && curso->estudiantes[j].edad > temp.edad) {
            curso->estudiantes[j + 1] = curso->estudiantes[j];
            j--;
        }
        curso->estudiantes[j+1] = temp;
    }
}

// Retorna un array con los nombres de todos los estudiantes
char** obtener_nombres(Curso *curso){
    //debo recorrer el arrat, buscar cada nombre y meterlo en un array despues devolver ese array

    if (curso == NULL || curso->cantidad == 0) {
        printf("No hay estudiantes en el curso.\n");
        return NULL;
    }

    char** dest = malloc(sizeof(char*) * curso->cantidad);
        if (dest == NULL)
        {
            printf("error al asignar memoria con malloc");
            return NULL;
        }
    for (int i = 0; i < curso->cantidad; i++) {
        dest[i] = malloc(strlen(curso->estudiantes[i].nombre) + 1);
        if (dest[i] == NULL)
        {
            printf("error al asignar memoria con malloc");
            for (int j = 0; j < i; j++) {
                free(dest[j]);
            }
            free(dest);
            return NULL;
        }
        
        strcpy(dest[i], curso->estudiantes[i].nombre);
    }
    return dest;
    
}
// Libera toda la memoria del curso
void liberar_curso(Curso *curso) {
    if (curso == NULL) return;
    free(curso->estudiantes);
    free(curso);
}

int main() {
    int capacidad;
    printf("Ingrese la capacidad del curso: ");
    scanf("%d", &capacidad);

    Curso *curso = crear_curso(capacidad);
    if (curso == NULL) return 1;

    int opcion;
    char nombre[51];
    int edad;
    float altura;
    char genero;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar estudiante\n");
        printf("2. Buscar estudiante\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Contar estudiantes por genero\n");
        printf("5. Mostrar lista de estudiantes\n");
        printf("6. Ordenar estudiantes por edad\n");
        printf("7. Obtener nombres de estudiantes\n");
        printf("0. Salir\n");
        printf("Ingrese opcion: ");
        scanf(" %d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese nombre: ");
                scanf(" %50[^\n]", nombre);
                printf("Ingrese edad: ");
                scanf(" %d", &edad);
                if (edad <= 0) {
                    printf("Edad invalida.\n");
                    break;
                }

                printf("Ingrese altura: ");
                scanf(" %f", &altura);
                if (altura <= 0) {
                    printf("Altura invalida.\n");
                    break;
                }

                printf("Ingrese genero (M/F): ");
                scanf(" %c", &genero);
                if (genero != 'M' && genero != 'F') {
                    printf("Genero invalido. Debe ser M o F.\n");
                    break;
                }

                if (agregar_estudiante(curso, nombre, edad, altura, genero) == 0)
                    printf("Estudiante agregado con exito.\n");
                break;

            case 2:
                printf("Ingrese nombre a buscar: ");
                scanf(" %[^\n]", nombre);
                Estudiante *busqueda = buscar_estudiante(curso, nombre);
                if (busqueda != NULL) {
                    printf("Estudiante encontrado: %s, %d años, %.2f m, %c\n",
                           busqueda->nombre, busqueda->edad, busqueda->altura, busqueda->genero);
                } else {
                    printf("Estudiante no encontrado.\n");
                }
                break;

            case 3:
                printf("Ingrese nombre a eliminar: ");
                scanf(" %[^\n]", nombre);
                if (eliminar_estudiante(curso, nombre) == 0) {
                    printf("Estudiante eliminado con exito.\n");
                } else {
                    printf("Estudiante no encontrado.\n");
                }
                break;

            case 4:
                printf("Ingrese genero a contar (M/F): ");
                scanf(" %c", &genero);
                int cantidad = contar_por_genero(curso, genero);
                if (cantidad != -1)
                    printf("Cantidad de estudiantes con ese genero: %d\n", cantidad);
                else
                    printf("No hay estudiantes en el curso.\n");
                break;

            case 5:
                printf("\nLista de estudiantes:\n");
                for (int i = 0; i < curso->cantidad; i++) {
                    printf("%d. %s, %d años, %.2f m, %c\n",
                           i + 1,
                           curso->estudiantes[i].nombre,
                           curso->estudiantes[i].edad,
                           curso->estudiantes[i].altura,
                           curso->estudiantes[i].genero);
                }
                break;

            case 6:
                ordenar_por_edad(curso);
                printf("Estudiantes ordenados por edad.\n");
                break;
            
            case 7: {
                char** nombres = obtener_nombres(curso);

                if (nombres != NULL) {
                    printf("\nNombres de estudiantes:\n");
                    for (int i = 0; i < curso->cantidad; i++) {
                        printf("%s\n", nombres[i]);
                    }

                    for (int i = 0; i < curso->cantidad; i++) {
                        free(nombres[i]);
                    }
                    free(nombres);
                }
                break;
            }
            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    // Liberar memoria
    liberar_curso(curso);
    return 0;
}
