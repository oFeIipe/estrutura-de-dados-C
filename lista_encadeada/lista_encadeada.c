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
    int size;
}Linkedlist;




bool LinkedList_is_empty(const Linkedlist *L){
    return L->size == 0;
}


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

    return s_node;
}


void Linkedlist_add_first(Linkedlist *L, int val){
    SNode *p = SNode_create(val);
    p->next = L->begin;

    if(LinkedList_is_empty(L)) L->end = p;
    
    L->begin = p;
    L->size++;
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
    printf("L End -> %d\n\n", L->end->val);

}

int LinkedLIst_size(Linkedlist *L){
    /*
   for(SNode *p = L->begin; p != NULL; p = p->next) size++;
   */

    return L->size;
}

void Linkedlist_add_last(Linkedlist *L, int val){
    SNode *q = SNode_create(val);
    if(LinkedList_is_empty(L)) L->begin = L->end = q;
    else {
        L->end->next = q;
        L->end = q;
    }
    L->size++;
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
            if(L->end == pos) L->end = prev;
            if(L->begin == pos) L->begin = pos->next;
            else prev->next = pos->next;
        }
        L->size--;
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
    L->size = 0;
    free(L);

    *L_ref = NULL;
}

int LinkedList_first_val(Linkedlist *L){
    return L->begin->val;
}

int LinkedList_last_val(Linkedlist *L){
    return L->end->val;
}

int LinkedList_get_val(Linkedlist *L, int index){
    SNode *p = L->begin;

    for(int i = 0; i < index; i++) p =p->next;

    return p->val;
}

void LinkedList_insert_val(Linkedlist *L, int index, int val){
    if(index < 0 || index > L->size) exit(-1);

    if(index == 0) Linkedlist_add_first(L, val);
    else if(index == L->size) Linkedlist_add_last(L, val);

    else{
        SNode *p = L->begin;
        for(int i = 0; i < index - 1; i++){
            p = p->next;
        }
        SNode *q = SNode_create(val);
        q->next = p->next;
        p->next = q;
    }

}

void LinkedList_reverse(Linkedlist *L){
    /*int iterador = 0;
    SNode *left = L->begin, *right = L->end;

    while(iterador < L->size / 2){
        int temp;
        SNode *penultimo = L->begin;

        temp = left->val;
        left->val = right->val;
        right->val = temp;

        left = left->next;

        for(int i = 0; i < L->size - iterador - 2; i++) penultimo = penultimo->next;

        right = penultimo;
        
        iterador++;
    }*/

    SNode *prev = NULL, *current = L->begin, *next = NULL;
    L->end = L->begin;

    while (current != NULL){
        
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        
    }
    L->begin = prev;
}

int main(){

    Linkedlist *L = Linkedlist_create();
    int index = 2;

    Linkedlist_add_last(L, 10);
    Linkedlist_add_last(L, 20);
    Linkedlist_add_last(L, 30);
    Linkedlist_add_last(L, 40);
    Linkedlist_add_last(L, 50);

    
    


    LinkedList_reverse(L);

    Linkedlist_print_val(L);
    

    return 0;
}