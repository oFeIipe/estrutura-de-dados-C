#include <stdio.h>

int main(){

    float z = 2.5;
    float *fp = &z;

    printf("*&z = %f\n", *&z);
    printf("*fp = %f\n", *fp);
    printf("**&fp = %f\n", **&fp);

    return 0;
}