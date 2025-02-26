#include <stdio.h>

#define TAMANHO 10

void somaVet(int vet[], int tam, int escalar){
    for(int i = 0; i < tam; i++){
        vet[i] += escalar;
    }
}

void mostraVet(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        printf("&VET[%d] = %p | *VET[%d] = %d\n", i, &vet[i], i, *(vet + i));
    }
    printf("\n\n");
}

int main(){
    int vetin[TAMANHO] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mostraVet(vetin, TAMANHO);
    somaVet(vetin, TAMANHO, 3);
    mostraVet(vetin, TAMANHO);
}