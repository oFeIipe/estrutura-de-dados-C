#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct _circ_node
{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
}CNode;

typedef struct _circ_list
{
    size_t size;
    CNode *begin;
    CNode *end;
}CircList;

CircList *CircList_create(){
    CircList *CL = (CircList*) calloc(1, sizeof(CircList));

    CL->begin = NULL;
    CL->end = NULL;
    CL->size = 0;
    
    return CL;
}

CNode *CNode_create(int val){
    CNode *c_node = (CNode*) calloc(1, sizeof(CNode));

    c_node->val = val;
    c_node->next = c_node;
    c_node->prev = c_node;

    return c_node;
}

bool CircList_is_empty(CircList *Cl){
    return Cl->size == 0; 
}

void CNode_destroy(CNode **c_node_ref){
    free(*c_node_ref);
    c_node_ref = NULL;
}

void CircList_destroy(CircList **C_list_ref){
    CircList *CL = *C_list_ref;

    CNode *c_node = CL->begin;
    CNode *aux = NULL;

    for(int i = 0; i < CL->size; i++){
        aux = c_node;
        c_node = c_node->next;
        CNode_destroy(&aux);
    }
    CNode_destroy(&c_node);
    CL->size = 0;
    free(CL);

    *C_list_ref = NULL;
}

void CircList_add_first(CircList *Cl, int val){
    CNode *c_node = CNode_create(val);

    if(CircList_is_empty(Cl)) Cl->end = c_node;
    
    else{
        c_node->next = Cl->begin;
        Cl->begin->prev = c_node;
        c_node->prev = Cl->end;
        Cl->end->next = c_node;    
    }
    Cl->begin = c_node;
    Cl->size++;
}


void CircList_add_last(CircList *Cl, int val){
    CNode *c_node = CNode_create(val);

    if(CircList_is_empty(Cl)) Cl->begin = c_node;
    else{
        Cl->end->next = c_node;
        c_node->prev = Cl->end;
        c_node->next = Cl->begin;
        Cl->begin->prev = c_node;
    }
    Cl->end = c_node;
    Cl->size++;
}

void CircList_remove(CircList *Cl, int val){
    
    if(!CircList_is_empty(Cl)){
        CNode *c_node = Cl->begin;
        if(Cl->begin->val == val){
            
            if(Cl->size == 1){
                Cl->begin = NULL;
                Cl->end = NULL;
            }

            else{
                Cl->begin = c_node->next;
                Cl->begin->prev = Cl->end;
                Cl->end->next = Cl->begin;
            }
            CNode_destroy(&c_node);
        }
        else{
            c_node = c_node->next;

            while(c_node != Cl->begin){

                if(c_node->val == val){

                    if(c_node == Cl->end) Cl->end = c_node->prev;

                    c_node->prev->next = c_node->next;
                    c_node->next->prev = c_node->prev;
                    break;
                }
                else{
                    c_node = c_node->next;
                }
            }
            CNode_destroy(&c_node);
        }
        
        Cl->size--;
    }
}

void CircList_print(CircList *Cl){
    if(CircList_is_empty(Cl)){
        printf("L -> NULL\n");
        printf("L->end -> NULL");
    }
    else{
        CNode *c_node = Cl->begin;
        printf("Size: %d\n", Cl->size);
        printf("CL -> ");

        for(int i = 0; i < Cl->size; i++){
            printf("%d -> ", c_node->val);
            c_node = c_node->next;
        }

        printf("NULL\n");
        printf("CL End -> %d\n", Cl->end->val);
        printf("CL Begin -> %d\n", Cl->begin->val);
    }    
}

int main(){
    CircList *Cl = CircList_create();

    
    CircList_add_first(Cl, 20);
    CircList_add_first(Cl, 30);
    CircList_add_first(Cl, 40);
    CircList_add_first(Cl, 50);
    CircList_add_last(Cl, 10);
   
    CircList_remove(Cl, 10);
    CircList_print(Cl);
}