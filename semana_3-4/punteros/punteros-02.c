void intercambiar (int *a,int *b, int *c){ 

    //a tenga el valor de c
    //b tenga el valor de a
    //c tenga el valor de b
    int guardar_valor_de_a = *a; //guardar_valor_de_a = a ---> 99
    int guardar_valor_de_b = *b; //guardar_el_valor_de_b = b ---> 100
    *a = *c; //a == c ---> a == 101
    *b = guardar_valor_de_a;  // b  == 99
    *c = guardar_valor_de_b; // c == *b ---> 100
}

int main () {
    int x = 99, y=100, z=101;
    printf("Antes x=%d, y=%d, z=%d \n",x, y,z);
    intercambiar(&x, &y, &z);
    printf("despues x=%d, y=%d, z=%d \n", x, y,z);
}

// a= 101
// b= 99
// c = 100