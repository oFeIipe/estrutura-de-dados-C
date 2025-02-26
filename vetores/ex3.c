#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1[5] = {0, 1, 2, 3, 4};
    int *v2, *p;
    int i;

    p = v1;
    p[3] = p[4] = 10;

    v2 = (int *) malloc(5 * sizeof(int));

    for(i = 0; i < 5; i++){
        v2[i] = v1[i];
    }

    for(int j = 0; j < 5; j++){
        printf("%d\n", v2[j]);
    }
    
    free(v2);
    v2 = NULL;

    
}