#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _static_stack
{
    int *data;
    long capacity;
    long top;
}Stack;

Stack *Stack_create(size_t capacity){
    Stack *stack = (Stack*) calloc(1, sizeof(Stack));

    stack->capacity = capacity;
    stack->data = (int*) calloc(stack->capacity, sizeof(int));
    stack->top = -1;

    return stack;
}

void Stack_destroy(Stack **s_ref){
    Stack *S = *s_ref;
    free(S->data);
    free(S);

    *s_ref = NULL;
}

bool Stack_is_empty(Stack *stack){
    return stack->top == -1;
}

bool Stack_is_full(Stack *stack){
    return stack->top == (stack->capacity - 1);
}

void push(Stack *stack, int val){
    if(Stack_is_full(stack)){
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "STACK IS FULL!");
        exit(EXIT_FAILURE);
    }     

    stack->top++;
    stack->data[stack->top] = val;
    
}

void printStack(Stack *stack){
    printf("Capacity: %d\n", stack->capacity);
    printf("Top: %d\n", stack->data[stack->top]);
    for(int i = stack->top; i > -1; i--){
        printf("DATA [%d]: %d\n", i, stack->data[i]);
    }
}

int peek(Stack *stack){
    return stack->data[stack->top];
}

int pop(Stack *stack){
    int stack_top = stack->data[stack->top];
    stack->top--;
    return stack_top;
}
int main(){

    Stack *s = Stack_create(10);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    
    printStack(s);

    printf("TOPO DA PILHA: %d\n", peek(s));
    printf("REMOVENDO TOPO: %d\n\n", pop(s));

    printf("TOPO DA PILHA: %d\n", peek(s));

    return 0;
}