#include <stdio.h>
#include <stdlib.h>

double * alocaDouble(int tamanho){
    return (double *) calloc(tamanho, sizeof(double));
}

void alocaDoubleRef(double **ponteiro, int tamanho){
    *ponteiro = (double *) calloc(tamanho, sizeof(double));
}

int main(){
    double *p = alocaDouble(5);

    for(int i = 0; i < 5; i ++){
        printf("&p[%d] = %p | *p[%d] = %lf\n", i, &p[i], i, p[i]);
    }
    
    free(p);
    p = NULL;
    
    puts("");

    double *p2;
    alocaDoubleRef(&p2, 5);

    for(int i = 0; i < 5; i ++){
        printf("&p2[%d] = %p | *p2[%d] = %lf\n", i, &p2[i], i, p2[i]);
    }

    free(p2);
    p2 = NULL;

    return 0;
}