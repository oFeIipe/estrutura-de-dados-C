#include <stdio.h>
#include <stdlib.h>

int * cria_matriz_vetor(int n_rows, int n_cols){
    return (int *) calloc(n_rows*n_cols, sizeof(int));
}

int main(){
    int n_rows = 2, n_cols = 3;
    int *matriz_vetor = cria_matriz_vetor(n_rows, n_cols);

    for(int i = 0; i < n_rows*n_cols; i++){
        matriz_vetor[i] = i * 2;
    }

    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            int p = (i * n_cols) + j;
            printf("%d\n", matriz_vetor[p]);
        }
    }
}