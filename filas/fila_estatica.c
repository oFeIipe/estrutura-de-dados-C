#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _static_queue
{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
}Queue;

Queue * Queue_create(long capacity){
    Queue * q = (Queue*) calloc(1, sizeof(Queue));

    q->capacity=capacity;
    q->data = (int*) calloc(q->capacity, sizeof(int));
    q->size = 0;
    q->begin = 0;
    q->end = 0;

    return q;
}


void Queue_destroy(Queue **q_ref){
    Queue *q = *q_ref;
    free(q->data);
    free(q);

    *q_ref = NULL;
}

bool Queue_is_empty(Queue *q){
    return q->size == 0;
}

bool Queue_is_full(Queue *q){
    return q->size == q->capacity;
}

void enqueue(Queue *q, int val){
    if(Queue_is_full(q)){
        fprintf(stderr, "ERROR in 'enqueue'\n");
        fprintf(stderr, "QUEUE IS FULL!");
        exit(EXIT_FAILURE);
    }   

    q->data[q->end] = val;
    q->end = (q->end + 1) % q->capacity;
    q->size++;
}

int peek(Queue *q){
    if(Queue_is_empty(q)){
        fprintf(stderr, "ERROR in 'peek'\n");
        fprintf(stderr, "QUEUE IS EMPTY!");
        exit(EXIT_FAILURE);
    }   

    return q->data[q->begin];
}

int dequeue(Queue *q){
    if(Queue_is_empty(q)){
        fprintf(stderr, "ERROR in 'dequeue'\n");
        fprintf(stderr, "QUEUE IS EMPTY!");
        exit(EXIT_FAILURE);
    }   
    int val = q->data[q->begin];

    q->begin = (q->begin + 1) % q->capacity;
    q->size--;
    return val;
}

void printQueue(Queue *Q){

    if(Queue_is_empty(Q)){
        fprintf(stderr, "ERROR in 'printQueue'\n");
        fprintf(stderr, "QUEUE IS EMPTY!");
        exit(EXIT_FAILURE);
    }   

    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n\n", Q->end);

    long s, i;

    for (s = 0, i = Q->begin;
         s < Q->size;
         s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }
    puts("");

}

int main(){
    Queue *q = Queue_create(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    
    printQueue(q);

    dequeue(q);

    printQueue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);
    return 0;
}