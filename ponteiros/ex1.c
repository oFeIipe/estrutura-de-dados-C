#include <stdio.h>

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int a = 5, b = 12;

    troca(&a, &b);

    printf("a = %d | b = %d", a, b);
    
    return 0;
}