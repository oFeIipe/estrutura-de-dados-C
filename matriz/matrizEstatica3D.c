#include <stdio.h>

int main(){
    int m [2][2][3] = {
        {
            {0, 1, 2},
            {3, 4, 5}
        },
        {
            {6, 7, 8},
            {9, 10, 11}
        }
    };


    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++){
                printf("m[%d][%d][%d] = %p || m[%d][%d][%d] = %d\n", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);
            }
        }
    }

};