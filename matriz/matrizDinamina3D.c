#include <stdio.h>
#include <stdlib.h>

int main(){
    int cont = 0;
    int n_slices = 2, n_rows = 2, n_cols = 3;
    int ***m = (int ***) calloc(n_slices, sizeof(int **));


    for(int k = 0; k < n_slices; k++){
        m[k] = (int **) calloc(n_rows, sizeof(int *));

        for(int i = 0; i < n_rows; i++){
            m[k][i] = (int *) calloc(n_cols, sizeof(int));
        }
    }

    for(int i = 0; i < n_slices; i++){
        for(int j = 0; j < n_rows; j++){
            for(int k = 0; k < n_cols; k++){
                m[i][j][k] = cont++;
                printf("m[%d][%d][%d] = %p || m[%d][%d][%d] = %d\n", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);
            }
        }
    }

    for(int i = 0; i < n_slices; i++){
        for(int j = 0; j < n_rows; j++){
                free(m[i][j]);
        }
        free(m[i]);
    }

    free(m);

    m = NULL;

    

    return 0;
}