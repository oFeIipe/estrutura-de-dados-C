#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void somaVet(int vet[], int tam, int escalar){
    for(int i = 0; i < tam; i++){
        vet[i] += escalar;
    }
}

void mostraVet(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("&VET[%d] = %p | *VET[%d] = %d\n", i, vet + i, i, *(vet + i));
    }
    printf("\n\n");
}

void desalocaVetor(int **v){
    free(*v);
    *v = NULL;
}

int main(){
    int *vetin = (int *) calloc(TAMANHO, sizeof(int));

    for(int i = 0; i < TAMANHO; i++){
        *(vetin + i) = i * 50;
    }

    mostraVet(vetin, TAMANHO);
    somaVet(vetin, TAMANHO, 3);
    mostraVet(vetin, TAMANHO);

    desalocaVetor(&vetin);

    mostraVet(vetin, TAMANHO);

    return 0;
}