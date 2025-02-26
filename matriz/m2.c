#include <stdio.h>
#include <stdlib.h>

int nrows = 3;
int ncols = 3;

int main(){
    int **m = NULL, count = 0;

    m = (int **) calloc(nrows, sizeof(int*));

    for(int i = 0; i < nrows; i++){
        m[i] = (int *) calloc(ncols, sizeof(int));
    }

    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            m[i][j] = ++count;
            printf("&m[%d][%d] = %p | *m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }

    for(int i = 0; i < 3; i++){
        free(m[i]);
    }
    free(m);

    m = NULL;


    return 0;
}