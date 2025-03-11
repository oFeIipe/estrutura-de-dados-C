#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode{
    int val;
    struct _snode *next;
    struct _snode *prev;
}SNode;

typedef struct _linked_list{
    SNode *begin;
    SNode *end;
    int size;
}Linkedlist;


Linkedlist *Linkedlist_create(){
    Linkedlist *L = (Linkedlist*) calloc(1, sizeof(Linkedlist));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    return L;
}

SNode *SNode_create(int val){
    SNode *s_node = (SNode *) calloc(1, sizeof(SNode));

    s_node->val = val;
    s_node->next = NULL;
    s_node->prev = NULL;

    return s_node;
}



bool LinkedList_is_empty(const Linkedlist *L){
    return L->size == 0;
}

void Linkedlist_add_first(Linkedlist *L, int val){

    SNode *p = SNode_create(val);
    p->next = L->begin;
    if(LinkedList_is_empty(L)) L->end = p;
    else L->begin->prev = p;
    
    L->begin = p;
    L->size++;
}

void Linkedlist_add_last(Linkedlist *L, int val){
    SNode *p = SNode_create(val);
    p->prev = L->end;

    if(LinkedList_is_empty(L)) L->begin = p;
    else L->end->next = p;
    
    L->end = p;
    L->size++;
}

void LinkedList_remove(Linkedlist *L, int val){

    if(LinkedList_is_empty(L)) return;

    SNode *p = L->begin;
    
    while(p != NULL && p->val != val){
        p = p->next;
    }

    if(p != NULL){   
        if(L->begin == p){
            L->begin = p->next;
            if(L->end == p) L->end = NULL;    
            else L->begin->prev == NULL;
        }
        else if(L->end == p){
            L->end = p->prev;
            L->end->next = NULL;
        }
        else{
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p = NULL;
        }
        L->size--;   
    }     
}


void Linkedlist_print_val(Linkedlist *L){
    SNode *p = L->begin;

    printf("Size: %d\n", L->size);
    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("L End -> %d\n", L->end->val);
    printf("L Begin -> %d\n\n", L->begin->val);

}

void LinkedList_reverse(Linkedlist *L){
    SNode *left = L->begin, *right = L->end;
    int temp;
    
    for(int i = 0; i < L->size; i++){
        Linkedlist_print_val(L);
        temp = left->val;
        left->val = right->val;
        right->val = temp;

        left = left->next;
        right = right->prev;
    }
}

void Linkedlist_print_val_reverse(Linkedlist *L){
    SNode *p = L->end;

    printf("Size: %d\n", L->size);
    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL\n");
    printf("L End -> %d\n\n", L->end->val);
    printf("L Begin -> %d\n\n", L->begin->val);
    
}

void LinkedList_destroy(Linkedlist **L_ref){
    Linkedlist *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
        
    }
    L->size = 0;
    free(L);

    *L_ref = NULL;
}

int LinkedList_size(Linkedlist *L){
    return L->size;
}


int main(){

    Linkedlist *L = Linkedlist_create();

    Linkedlist_add_first(L, 10);
    Linkedlist_add_first(L, 20);
    Linkedlist_add_first(L, 30);
    Linkedlist_add_first(L, 40);
    Linkedlist_add_first(L, 50);

    
    Linkedlist_print_val(L);

    LinkedList_reverse(L);

    //LinkedList_destroy(&L);
    return 0;
}