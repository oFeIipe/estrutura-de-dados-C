#include <stdio.h>
#include <stdlib.h>

int tamanho = 5;

void copiaVetorRef(int vetor[], int *copia, int tamanho){
    for(int i = 0; i < tamanho; i++){
        copia[i] = vetor[i];
    }
}

int * alocaVetor(int tamanho){
    return (int *) calloc(tamanho, sizeof(double));
}


int * copiaVetorRetorno(int vetor[], int tamanho){
    int *vet = alocaVetor(tamanho);

    for(int i = 0; i < tamanho; i++){
        vet[i] = vetor[i];
    }

    return vet;
}

void desalocaVetor(int **v){
    free(*v);
    *v = NULL;
}

int main(){
    /*;
    int vetin[5] = {0, 1, 2, 3, 4}; 
    int *vet2 = (int *)  malloc(tamanho * sizeof(int));
    copiaVetorRef(vetin, vet2, 5);

    for(int i = 0; i < 5; i++){
        printf("v[%d] = %d\n", i, vet2[i]);
    }
    
    desalocaVetor(&vet2);
    */

    int vetin[5] = {0, 1, 2, 3, 4};
    int *vet2 = copiaVetorRetorno(vetin, tamanho);

    for(int i = 0; i < 5; i ++){
        printf("&vetin[%d] = %p | *vetin[%d] = %d\n", i, &vetin[i], i, vetin[i]);
    }

    puts("");

    for(int j = 0; j < 5; j ++){
        printf("&vet2[%d] = %p | *vet2[%d] = %d\n", j, &vet2[j], j, vet2[j]);
    }

    desalocaVetor(&vet2);
}