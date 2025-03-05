#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode{
    int val;
    struct _snode *next;
}SNode;

typedef struct _linked_list{
    SNode *begin;
    SNode *end;
}Linkedlist;




bool LinkedList_is_empty(const Linkedlist *L){
    return L->begin == NULL && L->end == NULL;
}


Linkedlist *Linkedlist_create(){
    Linkedlist *L = (Linkedlist*) calloc(1, sizeof(Linkedlist));
    L->begin = NULL;
    L->end = NULL;
    return L;
}


SNode *SNode_create(int val){
    SNode *s_node = (SNode *) calloc(1, sizeof(SNode));

    s_node->val = val;
    s_node->next = NULL;

    return s_node;
}


void Linkedlist_add_first(Linkedlist *L, int val){
    SNode *p = SNode_create(val);
    p->next = L->begin;

    if(LinkedList_is_empty(L)) L->end = p;
    
    L->begin = p;

}


void Linkedlist_print_val(Linkedlist *L){
    SNode *p = L->begin;

    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("L End -> %d\n\n", L->end->val);

}

void Linkedlist_add_last(Linkedlist *L, int val){
    SNode *q = SNode_create(val);
    if(LinkedList_is_empty(L)) L->begin = L->end = q;
    else {
        L->end->next = q;
        L->end = q;
    }
}


void LinkedList_remove_element(Linkedlist *L, int val){
    if(!LinkedList_is_empty(L)){
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while(pos != NULL && pos->val != val){
            prev = pos;
            pos = pos->next;
        }

        if(pos != NULL){
            if(L->end == pos){
                L->end = prev;
            }
            if(L->begin == pos){
                L->begin = pos->next;
            }
            else{
                prev->next = pos->next;
            }
        }
        
        free(pos);
            
    }
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

    free(L);

    *L_ref = NULL;
}

int main(){

    Linkedlist *L = Linkedlist_create();


    Linkedlist_add_last(L, 30);
    Linkedlist_add_last(L, 10);
    Linkedlist_add_last(L, 50);

    Linkedlist_add_last(L, 19);
    Linkedlist_add_last(L, 91);

    Linkedlist_print_val(L);

    LinkedList_remove_element(L, 91);

    Linkedlist_print_val(L);

    LinkedList_destroy(&L);

    return 0;
}