#include <stdio.h>
#include <stdlib.h>

int ** alocaMatrizBidimensional(int n_rows, int n_cols){
    int **m = (int **) calloc(n_rows, sizeof(int*));

    for(int i = 0; i < n_cols; i++){
        m[i] = (int*) calloc(n_cols, sizeof(int)); 
    }

    return m;
}

void escalar(int escalar, int **matriz, int n_rows, int n_cols){
    int  count = 1;
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            matriz[i][j] = count++ * escalar;   
        }
    }
}

void desalocaMatriz(int ***matriz, int n_rows){
    int **aux = *matriz;
    for(int i = 0; i < n_rows; i++){
        free(aux[i]);
    }
    free(aux);
    *matriz = NULL;
}

void printaMatriz(int **matriz, int n_rows, int n_cols){
    printf("&matriz = %p || matriz = %p\n\n", &matriz, matriz);
    
    for(int i = 0; i < n_rows; i++){
        printf("&matriz[%d] = %p || matriz[%d] = %p\n\n", i, &matriz[i], i, matriz[i]);
        for(int j = 0; j < n_cols; j++){
            
            printf("&matriz[%d][%d] = %p | *matriz[%d][%d] = %d\n", i, j, &matriz[i][j], i, j, matriz[i][j]);
        }
        puts("");
    }

}
int main(){
    int n_rows = 5, n_cols = 5;
    int **m = alocaMatrizBidimensional(n_rows, n_cols);


    escalar(5, m, n_rows, n_cols);
    printaMatriz(m, n_rows, n_cols);
    desalocaMatriz(&m, n_rows);

    printf("m is NULL? %d", m == NULL);
}