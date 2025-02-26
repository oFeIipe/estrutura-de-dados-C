#include <stdio.h>

void soma(int a, int b, int *c, int *d){
    *c = a + b;  
    *d = a - b;
}

int main(){
    int a = 10, b = 20, c, d;

    soma(a, b, &c, &d);

    printf("%d\n", c);

    printf("%d", d);
}