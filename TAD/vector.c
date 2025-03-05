#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct float_vector{
    int capacity;
    int size;
    float *data;
};

bool is_full(FloatVector *vector){
    return vector->size == vector->capacity;
}



FloatVector *create(int capacity){
    FloatVector *vector =  (FloatVector *) calloc(capacity, sizeof(FloatVector));

    vector->size = 0;
    vector->capacity = capacity;
    vector->data = (float *) calloc(capacity, sizeof(FloatVector));

    return vector;
}


void destroy(FloatVector **vector){
    FloatVector *aux = *vector;

    free(aux->data);
    free(aux);
    *vector = NULL;
}

int size(const FloatVector *vector){
    return vector->size;
}

int capacity(const FloatVector *vector){
    return vector->capacity;
}

float at(const FloatVector * vector, int index){
    if(index < 0 || index > vector->capacity){
        fprintf(stderr, "ERROR in 'get'\n");
        fprintf(stderr, "index [%d] is out of bounds: [0, %d]", index, vector->size);
        exit(EXIT_FAILURE);
    }

    return vector->data[index];
}

float get(const FloatVector *vector, int index){
    return vector->data[index];
}

void append(FloatVector *vector, float value){
    if(is_full(vector)){
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full");
        exit(EXIT_FAILURE);
    }
    vector->data[vector->size++] = value;
}

void unshift(FloatVector *vector, float value){
    if(is_full(vector)){
        fprintf(stderr, "ERROR in 'unshift'\n");
        fprintf(stderr, "Vector is full");
        exit(EXIT_FAILURE);
    }
    vector->size++;
    for(int i = vector->size - 1; i > 0; i--){
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[0] = value;
}

void set(FloatVector *vector, int index, float value){
    if(index < 0 || index >= vector->size){
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "index [%d] is out of bounds: [0, %d]", index, vector->size);
        exit(EXIT_FAILURE);
    }

    vector->data[index] = value;
}

void shift(FloatVector *vector){
    for(int i = 0; i < vector->size; i++){
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void pop(FloatVector *vector){
    vector->size--;
}

void reverse(FloatVector *vector){
    int left = 0, right = vector->size - 1, temp;
    while(left < right){
        temp = vector->data[left];
        vector->data[left] = vector->data[right];
        vector->data[right] = temp;

        right--;
        left++;
    }
}

void remove_at_index(FloatVector *vector, int index){
    if(index < 0 || index >= vector->size){
        fprintf(stderr, "ERROR in 'remove'\n");
        fprintf(stderr, "index [%d] is out of bounds: [0, %d]", index, vector->size);
        exit(EXIT_FAILURE);
    }
    for(int i = index; i < vector->size; i++){
        vector->data[i] = vector->data[i + 1];
    }

    vector->size--;
}

void print(const FloatVector *vector){
    puts("---------------");

    printf("Size: %d\n", vector->size);
    printf("Capacity: %d\n", vector->capacity);

    puts("---------------");

    for(int i = 0; i < vector->size; i++){
        printf("[%d] = %f\n", i, vector->data[i]);
    }

    puts("-----------------------\n");
}