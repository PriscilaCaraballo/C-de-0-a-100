#include <stdio.h>
 int main () {
    char mensaje[] = "Hola 10";
    char *ptr = mensaje;
    // Recorrer caracter por caracter
    while (*ptr != '\0') {
    printf("'%c' en dirección %p\n", *ptr,
    ptr);
    ptr++;
    }

   // Implementando strlen con punteros:
    int strlen(char *str) {
    int longitud = 0;
    while (*str != '\0') {
    longitud++;
    str++;
    }
    return longitud;
    }
    
    // Versión más compacta
    int strlen_v2(char *str) {
    char *inicio = str;
    // Avanzar hasta '\0'
    while (*str) str++;
    // Diferencia de punteros
    return str - inicio;
    } 
 }