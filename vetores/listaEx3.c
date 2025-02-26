#include <stdio.h>
#include <stdlib.h>

static int vet[2];

int * buscaMenorMaiorValor(int vetor[], int tamanho){
    int menor = 0, maior = 0;

    for(int i = 0; i < tamanho; i++){
        if(menor >= vetor[i]){
            menor = vetor[i];
        }
        if(maior <= vetor[i]){
            maior = vetor[i];
        }
    }

    vet[0] = maior;
    vet[1] = menor; 

    return vet;
}

int main(){
    int vetor[20] = {8, 2, -33, -6, 209, 4, 30, 1, 5, -7, 102, 910, 29, 96, 1204, -392, 102, -35, 65, 153}; 
    int *retornoFuncao = buscaMenorMaiorValor(vetor, 20);

    int maior = retornoFuncao[0];
    int menor = retornoFuncao[1];   

    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);

    return 0;
}