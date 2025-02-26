#include <stdio.h>
#include <stdlib.h>

void printaVet(int vet[], char nome[]){
    printf("&%s = %p | &%s = %d\n", nome, &vet, nome, vet);
    for(int i = 0; i < 5; i++){
        printf("&%s[%d] = %p | &%s[%d] = %d\n", nome, i, &vet[i], nome, i, vet[i]);
    }
}

int main(){
    int vetin[5] = {0, 10, 20, 30, 40};

    printaVet(vetin, "VETOR NORMAR");
    puts("\n\n");

    int *vetinMalloc = (int *) malloc(5 * sizeof(int));

    printaVet(vetinMalloc, "VETOR MALLOC");
    puts("\n\n");

    int *vetinCalloc = (int *) calloc(5, sizeof(int));

    printaVet(vetinCalloc, "VETOR CALLOC");
    puts("\n");
}
