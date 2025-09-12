#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char *titulo;
char *autor;
int anio;
float precio;
} Libro;
typedef struct {
Libro *libros;
int cantidad;
int capacidad;
} Biblioteca;

// Crea una biblioteca con capacidad inicial dada
Biblioteca* crear_biblioteca(int capacidad_inicial) {
    if (capacidad_inicial <= 0)
    {
        printf("no es poscible crear un curso con capacidad negativa");
        return NULL;
    }
    
    //pedir memoria para el curso
    Biblioteca *b = malloc(sizeof (Biblioteca));
    if (b == NULL)
    {
        printf ("error al asignar memoria con malloc");
        return NULL;
    }
    
    b->libros = malloc(sizeof(Libro) * capacidad_inicial);
    if (b->libros == NULL)
    {
        printf ("error al asignar memoria con malloc");
        free(b);
        return NULL;
    }

    b->capacidad = capacidad_inicial;
    b->cantidad = 0;

    return b;
}

// Agrega un libro a la biblioteca
int agregar_libro(Biblioteca *bib, const char *tit, const char *aut, int an, float prec) {
     if (bib->cantidad >= bib->capacidad)
    {
        printf("curso lleno");
        return 1;
    }

    bib->libros[bib->cantidad].titulo = malloc(strlen(tit) + 1);//usar srtlen
    if(bib->libros[bib->cantidad].titulo == NULL) {
        printf("No hay estudiantes en el curso.\n");
        free(bib->libros);
        return 1;
    }
    strcpy(bib->libros[bib->cantidad].titulo, tit);

    bib->libros[bib->cantidad].autor = malloc(strlen(aut) + 1);
    if(bib->libros[bib->cantidad].autor == NULL) {
        printf("No hay estudiantes en el curso.\n");
        free(bib->libros[bib->cantidad].titulo);
        return 1;
    }
    strcpy(bib->libros[bib->cantidad].autor, aut);

    bib->libros[bib->cantidad].anio = an;
    bib->libros[bib->cantidad].precio = prec;
    
    bib->cantidad++;
    return 0;
}

// Busca libros por autor
//cambiar la funcion
Libro** buscar_por_autor(Biblioteca *bib, const char *autor, int *cantidad){
    if (bib == NULL || bib->cantidad == 0) {
        printf("No hay estudiantes en el curso.\n");
        return NULL;
    }
    for (int i = 0; i < bib->cantidad; i++) {
            if (strcmp(bib->libros[i].autor, autor) == 0){
                return &bib->libros[i];
            }
    }
    return NULL;
}



int main() {
    int capacidad;
    printf("Ingrese la capacidad de la biblioteca: ");
    scanf("%d", &capacidad);

    Biblioteca *bib = crear_biblioteca(capacidad);
    if (bib == NULL) return 1;

    char titulo[100];
    char autor[100];
    int anio;
    float precio;

    printf("Ingrese titulo: ");
    scanf(" %[^\n]", titulo);
    printf("Ingrese autor: ");
    scanf(" %[^\n]", autor);

    printf("Ingrese año: ");
    scanf(" %d", &anio);
    if (anio <= 0) {
        printf("Año invalido.\n");
        return 0;
    }
    printf("Ingrese precio: ");
    scanf(" %f", &precio);
    if (precio <= 0) {
        printf("Precio invalido. Debe ser mayor q 0'.\n");
        return 1;
    }

    if (agregar_libro(bib, titulo, autor, anio, precio) == 0) {
         printf("Estudiante agregado con exito.\n");
    }

    printf("\nLista de Libros:\n");
    for (int i = 0; i < bib->cantidad; i++) {
        printf("%d. %s, %s, %d años, %.2f $\n",
            i + 1,
            bib->libros[i].titulo,
            bib->libros[i].autor,
            bib->libros[i].anio,
            bib->libros[i].precio);
    }
    
    //liberar memoria
    for(int i = 0; i < bib->cantidad; i++) {    
        free(bib->libros[i].titulo);
        free(bib->libros[i].autor);
    }
    free(bib->libros);
    free(bib);
    return 0;
}