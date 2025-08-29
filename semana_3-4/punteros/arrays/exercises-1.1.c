// Implementar usando SOLO aritmética depunteros

void estadisticas(int *arr, int tamano,int *min, int *max, float *prom) {
// TODO: Encontrar min, max y calcularpromedio
//inicializo
int suma = 0;
*min = *arr;
*max = *arr;
int *ptr = arr; 
int *fin = arr + tamano;

//recorrer
while (ptr < fin) {
    //suma = suma + ptr
    // si ptr esta parado en 15, sumaria 15, no?
    //me olvide *
    suma += *ptr;

    //encontrar min y max
    //me olvide * en ambas condiciones
    if (*ptr < *min) {
        *min = *ptr;
    } else if (*ptr > *max){
        *max = *ptr;
    }
ptr++;
}
//me olvide *
 *prom = suma / (float) tamano;
// Solo usar aritmética de punteros
// No usar índices arr[i]
}
int main() {
    int numeros[] = {15, 3, 27, 9, 42, 1, 33};
    int min, max;
    float prom;
    estadisticas(numeros, 7, &min, &max, &prom);
    printf("Min: %d, Max: %d, Promedio: %.2f\n", min, max, prom);
    return 0;
}