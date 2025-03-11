#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _stack_node{
    int val;
    struct _stack_node *next;
    struct _stack_node *prev;
}StackNode;

typedef struct _stack{
    StackNode *begin;
    StackNode *end;
    int size;
}Stack;


Stack *Stack_create(){
    Stack *S = (Stack*) calloc(1, sizeof(Stack));

    S->begin = NULL;
    S->end = NULL;
    S->size = 0;

    return S;
}

StackNode *SNode_create(int val){
    StackNode *s_node = (StackNode*) calloc(1, sizeof(StackNode));

    s_node->next = NULL;
    s_node->prev = NULL;
    s_node->val = val;

    return s_node;
}

void Stack_destroy(Stack **s_ref){
    Stack *S = *s_ref;

    StackNode *p = S->begin;
    StackNode *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
        
    }
    S->size = 0;
    free(S);

    *s_ref = NULL;
}

bool Stack_is_empty(Stack *S){
    return S->size == 0;
}

long Stack_size(Stack *S){
    return S->size;
}

void push(Stack *S, int val){

    StackNode *s_node = SNode_create(val);
    s_node->prev = S->end;

    if(Stack_is_empty(S)) S->begin = s_node;
    else S->end->next = s_node;
    
    S->end = s_node;
    S->size++;
}

int peek(Stack *S){
    if(Stack_is_empty(S)){
        fprintf(stderr, "ERROR in 'peek'\n");
        fprintf(stderr, "STACK IS EMPTY!");
        exit(EXIT_FAILURE);
    }
    return S->end->val;
}

void pop(Stack *S){
    if(Stack_is_empty(S)){
        fprintf(stderr, "ERROR in 'POP'\n");
        fprintf(stderr, "STACK IS EMPTY!");
        exit(EXIT_FAILURE);
    }
    StackNode *s_node = S->end;

    S->end = s_node->prev;
    S->end->next = NULL;
    free(s_node);
    S->size--;
}

void printStack(Stack *S){
    if(Stack_is_empty(S)){
        fprintf(stderr, "ERROR in 'printStack'\n");
        fprintf(stderr, "STACK IS EMPTY!");
        exit(EXIT_FAILURE);
    }

    StackNode *s_node = NULL;
    printf("Top: %d\n", S->end->val);

    printf("Size: %d\n", S->size);
    printf("L -> ");

    for(s_node = S->begin; s_node != S->end; s_node = s_node->next){
        printf("%d -> ", s_node->val);
    }
    printf("%d -> ", s_node->val);

    printf("NULL\n");
}


int main(){
    Stack *s = Stack_create();

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    printStack(s);

    pop(s);
    pop(s);

    printStack(s);

    return 0;
}