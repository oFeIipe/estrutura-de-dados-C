#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _queue_node{
    int val;
    struct _queue_node *next;
    struct _queue_node *prev;
}QueueNode;

typedef struct _queue{
    QueueNode *begin;
    QueueNode *end;
    long size;
}Queue;

Queue *Queue_create(){
    Queue *q = (Queue*) calloc(1, sizeof(Queue));

    q->begin = NULL;
    q->end = NULL;
    q->size = 0;

    return q;
}

QueueNode *QNode_create(int val){
    QueueNode *q = (QueueNode*) calloc(1, sizeof(QueueNode));

    q->next = NULL;
    q->prev = NULL;
    q->val = val;

    return q;
}

void Queue_destroy(Queue **q_ref){
    Queue *Q = *q_ref;

    QueueNode *p = Q->begin;
    QueueNode *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
        
    }
    Q->size = 0;
    free(Q);

    *q_ref = NULL;
}

bool Queue_is_empty(Queue *Q){
    return Q->size == 0;
}

long Queue_size(Queue *Q){
    return Q->size;
}

void enqueue(Queue *Q, int val){

    QueueNode *p = QNode_create(val);

    if(Queue_is_empty(Q)) Q->begin = p;
    else Q->end->next = p;

    Q->end = p;
    Q->size++;
}

int peek(Queue *Q){
    if(Queue_is_empty(Q)){
        fprintf(stderr, "ERROR in 'peek'\n");
        fprintf(stderr, "STACK IS EMPTY!");
        exit(EXIT_FAILURE);
    }
    
    return Q->begin->val;
}

int dequeue(Queue *Q){
    if(!Queue_is_empty(Q)){
        QueueNode *p = Q->begin;
    
        if(Q->size == 1) Q->begin = Q->end = NULL;
        else{
            Q->begin = p->next;
            Q->begin->prev = NULL;
        }
        free(p);
        Q->size--;
        return p->val;
    }
}

void printQueue(Queue *Q){
    QueueNode *p = Q->begin;

    printf("Size: %d\n", Q->size);
    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("L End -> %d\n", Q->end->val);
    printf("L Begin -> %d\n\n", Q->begin->val);

}

int main(){
    Queue *q = Queue_create();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);

    dequeue(q);

    printQueue(q);
 
    dequeue(q);
    printQueue(q);

    dequeue(q);
    printQueue(q);

    dequeue(q);
    printQueue(q);


    return 0;
}