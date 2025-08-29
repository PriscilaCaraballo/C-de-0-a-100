#include <stdio.h>

// Implementar estas funciones usando punteros
int contar_palabras(char *str);
void a_mayusculas(char *str);
char* buscar_substring(char *texto, char *patron);

//contar las palabras que hay en un string
// como se?... los espacios 
    int contar_palabras(char *str) {
        int cont = 0;
    
        // recorrer str carácter por carácter
        //ne equivoque en el tipo, era char
        char *ptr = str;
        int flag = 0;
    
        //final es \0 y no hay que hacer fin
        while (*ptr != '\0') {
            //encontrar espacio
            if (*ptr != ' ' && flag == 0){
                //contador de palabras
                cont ++;
                flag = 1;
            } else if (*ptr == ' ') {
                flag = 0;
            }
            
            ptr++;
        }
        return cont;
    } 
    
//convertir todo a mayusculas
//aca no existe el uppercase, lpcdmm
     void a_mayusculas (char *str) {
        // recorrer str carácter por carácter
        //ne equivoque en el tipo, era char
        char *ptr = str;
    
        //final es \0 y no hay que hacer fin
        while (*ptr != '\0') {
            //si es un letra, ponerlo en mayuscula
            //como se que leetra es?
            //como lo paso a mayuscula
            //el chat dice q en ASCII entre mayuscula y minucula hay 32
            //mayúscula = minúscula - 32
            if (*ptr >= 'a' && *ptr <= 'z') {
                // Si el caracter está entre 'a' y 'z' en ASCII (97–122),
                // significa que es una letra minúscula. Entonces le resto 32
                // para llevarlo al rango 'A'–'Z' (65–90), o sea a mayúscula.

                *ptr = *ptr - 32;
            }
            ptr++;
        }
        
     }

//buscar una frase, y devuelve un puntero a la posicion donde esta
     char* buscar_substring(char *texto, char *patron) {
        if (*patron == '\0') return texto;
    
        //final es \0 y no hay que hacer fin
        while (*texto != '\0') {
            //apuntadores
            char *t = texto;
            char *p = patron;
            //en cada posición, comparar secuencia con patron
            while (*p != '\0' && *t == *p) {
                t++;
                p++;
            } 
            
            if (*p == '\0') {
                return texto;
            }

            texto ++;
        }

        return NULL;
     }

//lo del profe
int main() {
    char frase[] = "Hola mundo desde C";
    printf("Palabras: %d\n", contar_palabras(frase));
    a_mayusculas(frase);
    printf("Mayúsculas: %s\n", frase);
    char *pos = buscar_substring(frase, "MUNDO");
    if (pos) {
        printf("'MUNDO' encontrado en posición %td \n", pos - frase);
    }
    return 0;
}                                      