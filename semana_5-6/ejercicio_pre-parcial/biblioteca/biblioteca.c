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
        printf("no es posible crear una biblioteca con capacidad negativa o cero");
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
        printf("Biblioteca llena");
        return 1;
    }

    bib->libros[bib->cantidad].titulo = malloc(strlen(tit) + 1);//usar srtlen
    if(bib->libros[bib->cantidad].titulo == NULL) {
        printf("error al asignar memoria con malloc\n");
        free(bib->libros);
        return 1;
    }
    strcpy(bib->libros[bib->cantidad].titulo, tit);

    bib->libros[bib->cantidad].autor = malloc(strlen(aut) + 1);
    if(bib->libros[bib->cantidad].autor == NULL) {
        printf("error al asignar memoria con malloc. \n");
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
        printf("No hay libros en la biblioteca.\n");
        *cantidad = 0;
        return NULL;
    }  

    //contar cuantos libros hay con ese autor
    int contador = 0;
    for (int i = 0; i < bib->cantidad; i++) {
        if (strcmp(bib->libros[i].autor, autor) == 0){
            contador++;
        }
    }

     if(contador == 0) {
        *cantidad = 0;
        return NULL; // No se encontraron libros de ese autor
    }

    //pongo esos libros en un array nuevo de  puntero a LIbro por el conteo de antes
    Libro** resultado = malloc(sizeof(Libro*) * contador);
    if (resultado == NULL)
    {
            printf("error al asignar memoria con malloc");
            *cantidad = 0;
            return NULL;
    }
    

    //guardo los puntero a los libros que encontre recorriendo devuelta, comparando y guardando la direccion de la posicion
    int encontrados = 0;
    for (int i = 0; i < bib->cantidad; i++) {
        if (strcmp(bib->libros[i].autor, autor) == 0){
            resultado[encontrados] = &bib->libros[i];
            encontrados++;
        }
    }
    //igualar el puntero a la cantidad con el conteo de libros
    *cantidad = contador;
    //retornar el resultado
    return resultado;
}

// Busca libros por año de publicación
Libro** buscar_por_anio(Biblioteca *bib, int anio, int *cantidad) {
    if (bib == NULL || bib->cantidad == 0) {
        printf("No hay libros en la biblioteca.\n");
        *cantidad = 0;
        return NULL;
    }  

    //contar cuantos libros hay con ese año
    int contador = 0;
    for (int i = 0; i < bib->cantidad; i++) {
        if (bib->libros[i].anio == anio){
            contador++;
        }
    }

     if(contador == 0) {
        *cantidad = 0;
        return NULL; // No se encontraron libros de ese año
    }

    //pongo esos libros en un array nuevo de  puntero a LIbro por el conteo de antes
    Libro** resultado = malloc(sizeof(Libro*) * contador);
    if (resultado == NULL)
    {
            printf("error al asignar memoria con malloc");
            *cantidad = 0;
            return NULL;
    }
    

    //guardo los puntero a los libros que encontre recorriendo devuelta, comparando y guardando la direccion de la posicion
    int encontrados = 0;
    for (int i = 0; i < bib->cantidad; i++) {
        if (bib->libros[i].anio == anio) {
            resultado[encontrados] = &bib->libros[i];
            encontrados++;
        }
    }
    //igualar el puntero a la cantidad con el conteo de libros
    *cantidad = contador;
    //retornar el resultado
    return resultado;
}

// Retorna el libro más caro
Libro* libro_mas_caro(Biblioteca *bib) {
    if (bib == NULL || bib->cantidad == 0) {
        printf("No hay libros en la biblioteca.\n");
        return NULL;
    } 

    float mayor_precio = bib->libros[0].precio;
    Libro *libro_caro = &bib->libros[0];
    for (int i = 0; i < bib->cantidad; i++) {
        if (bib->libros[i].precio > mayor_precio){
            mayor_precio = bib->libros[i].precio;
            libro_caro = &bib->libros[i];
        }
    }
    return libro_caro;
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
    int opcion; 

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar libro\n");
        printf("2. Buscar por autor\n");
        printf("3. Buscar por año\n");
        printf("4. Buscar libro mas caro.\n");
        printf("0. Salir\n");
        printf("Ingrese opcion: ");
        scanf(" %d", &opcion);

        switch (opcion) {
            case 1:
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
                    printf("Libro agregado con exito.\n");
                }
            

                printf("\nLista de Libros:\n");
                for (int i = 0; i < bib->cantidad; i++) {
                    printf("%d. %s, %s,año: %d,precio: %.2f $\n",
                        i + 1,
                        bib->libros[i].titulo,
                        bib->libros[i].autor,
                        bib->libros[i].anio,
                        bib->libros[i].precio);
                }
            break;
            case 2:
                printf("Ingrese autor a buscar: ");
                scanf(" %[^\n]", autor);
                int cantidad_encontrada = 0;
                Libro** encontrados = buscar_por_autor(bib, autor, &cantidad_encontrada);
                if (encontrados != NULL && cantidad_encontrada > 0) {
                    printf("Libros encontrados de %s:\n", autor);
                    for (int i = 0; i < cantidad_encontrada; i++) {
                        printf("%d. %s, %s,año: %d, %.2f $\n",
                            i + 1,
                            encontrados[i]->titulo,
                            encontrados[i]->autor,
                            encontrados[i]->anio,
                            encontrados[i]->precio);
                    }
                    free(encontrados); // Liberar memoria del array de punteros
                } else {
                    printf("No se encontraron libros de ese autor.\n");
                }
            break;
            case 3:
                printf("Ingrese año a buscar: ");
                scanf(" %d", &anio);
                int cantidad_encontrada_anio = 0;
                Libro** encontrados_anio = buscar_por_anio(bib, anio, &cantidad_encontrada_anio);
                if (encontrados_anio != NULL && cantidad_encontrada_anio > 0) {
                    printf("Libros encontrados del año %d:\n", anio);
                    for (int i = 0; i < cantidad_encontrada_anio; i++) {
                        printf("%d. %s, %s,año: %d , %.2f $\n",
                            i + 1,
                            encontrados_anio[i]->titulo,
                            encontrados_anio[i]->autor,
                            encontrados_anio[i]->anio,
                            encontrados_anio[i]->precio);
                    }
                    free(encontrados_anio); // Liberar memoria del array de punteros
                } else {
                    printf("No se encontraron libros de ese año.\n");
                }
            break;
            case 4:
                printf("Libro de mayor precio");
                Libro *busqueda = libro_mas_caro(bib);
                 if (busqueda != NULL) {
                    printf("Libros encontrados mas costoso:\n");
                        printf("%s, %s,año: %d , %.2f $\n",
                            busqueda->titulo,
                            busqueda->autor,
                            busqueda->anio,
                            busqueda->precio);
                } 
            break;
            case 0:
                printf("Saliendo...\n");
                break;

                default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);
    
    //liberar memoria
    for(int i = 0; i < bib->cantidad; i++) {    
        free(bib->libros[i].titulo);
        free(bib->libros[i].autor);
    }
    free(bib->libros);
    free(bib);
    return 0;
}