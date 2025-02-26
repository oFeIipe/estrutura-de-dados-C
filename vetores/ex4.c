#include <stdio.h>
#include <stdlib.h>

int main(){
    char *v;

    for(int i = 0;i < 9999999; i++){
        v = (char *) malloc(5000 * sizeof(int));
    }

    return 0;
}