#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("&m[%d][%d] = %p | *m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }

    return 0;
}