#include "float_vector.h"
#include <stdio.h>

int main(){
    FloatVector *vet = create(10);

    append(vet, 1.0);
    append(vet, 2.0);
    append(vet, 3.0);
    append(vet, 4.0);
    append(vet, 5.0);
    append(vet, 6.0);
    append(vet, 7.0);
    append(vet, 8.0);
    append(vet, 9.0);

    print(vet);

    unshift(vet, 10.0);

    print(vet);

    destroy(&vet);

    return 0;
}