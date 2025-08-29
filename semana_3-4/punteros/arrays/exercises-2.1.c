#include <stdio.h>
// Implementar estas funciones usando punteros
int contar_palabras(char *str);
void a_mayusculas(char *str);
char* buscar_substring(char *texto, char *patron);

//FUNCION contar_palabras
int contar_palabras(char *str){
// contador de palabras
int cont = 0;
// puntero que recorre la cadena (str)
char *ptr = str;
// flag indica si estamos dentro de una palabra
int flag = 0;

// mientras no llegue al final de la cadena
while (*ptr != '\0') {
    // si encontramos un carácter que no es espacio y no estamos dentro de una palabra
    if (*ptr != ' ' && flag == 0)
    {
        // contamos una nueva palabra
        cont++;
        // marcamos que estamos dentro de una palabra
        flag = 1;
    } else if (*ptr == ' ' ) {
    // si encontramos un espacio, salimos de la palabra
    flag = 0;
    
    }
    // avanzamos al siguiente carácter
    ptr++;
// devolvemos el número de palabras
    }
return cont;
}
//FUNCION a_mayusculas
void a_mayusculas(char *str) {
// puntero que recorre la cadena
char *ptr = str;
// mientras no llegue al final de la cadena
while (*ptr != '\0') {
    // si es letra minúscula
    if (*ptr >= 'a' && *ptr <= 'z') {
        // convertir a mayúscula usando ASCII
        *ptr = *ptr - 32;
        //mayuscula = minuscula - 32
    }
    // avanzar al siguiente carácter
    ptr++;
}
}

//FUNCION buscar_substrings
char* buscar_substring(char *texto, char *patron){
// patrón vacío → devolvemos inicio del texto
if (*patron == '\0') {
    return texto;
}
// mientras no llegue al final del texto
while (*texto != '\0')
{
    // puntero temporal en el texto
    char *t = texto;
    // puntero temporal en el patrón
    char *p = patron;

    //mientras p no hay terminado, y t y p sean iguales
    // comparar caracteres mientras coincidan
    while (*p !='\0' && *t == *p)
    {
      //sumamos a p y a t
      p++;
      t++;  
    }
    // si llegamos al final del patrón → coincidencia completa
    if (*p == '\0')
    {
      // devolvemos puntero a la posición donde empieza
        return texto;
    }
    // avanzar al siguiente carácter del texto
    texto++;
}
return NULL;
}

int main() {
    char frase[] = "Hola mundo desde C";
    printf("Palabras: %d\n", contar_palabras(frase));
    a_mayusculas(frase);
    printf("Mayúsculas: %s\n", frase);
    char *pos = buscar_substring(frase, "MUNDO");
    if (pos) {
        printf("'MUNDO' encontrado enposición %td \n", pos - frase);
    }
    return 0;
}
