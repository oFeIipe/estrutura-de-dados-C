#include <stdio.h>

int main(){
    int a, *p;

    printf("sizeof(a) %ld\n", sizeof(a));
    printf("sizeof(int) %ld\n", sizeof(int));
    printf("sizeof(short) %ld\n", sizeof(short));
    printf("sizeof(long) %ld\n", sizeof(long));
    printf("sizeof(float) %ld\n", sizeof(float));
    printf("sizeof(double) %ld\n", sizeof(double));
    printf("sizeof(*p) %ld\n", sizeof(p));

    printf("sizeof(void *) %ld\n", sizeof(void *));
    printf("sizeof(int *) %ld\n", sizeof(int *));
    printf("sizeof(int **) %ld\n", sizeof(int **));
    printf("sizeof(int ***) %ld\n", sizeof(int ***));
    printf("sizeof(float *) %ld\n", sizeof(float *));
}