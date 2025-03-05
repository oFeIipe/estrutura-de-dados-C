#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

typedef struct _livro
{
    char titulo[100];
    int numero_paginas;
    float preco;
}Livro;

Livro *cria_livro(const char *titulo, int num_paginas, float preco){
    Livro *livro =  (Livro *) calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->numero_paginas = num_paginas;
    livro->preco = preco;

    return livro;
}
void delete_livro(Livro **livro_ref){
    Livro *aux = *livro_ref;
    free(aux);
    *livro_ref = NULL;
}


void print_livro(Livro *Livro){
    printf("Titulo: %s\n", Livro->titulo);
    printf("Numero de paginas: %d\n", Livro->numero_paginas);
    printf("Preco: R$%.2f\n", Livro->preco);
    printf("Endereco de memoria: %p\n\n", Livro);
}


bool sao_iguais(Livro *livro1, Livro *livro2){
    return strcmp(livro1->titulo, livro2->titulo) == 0;
}

int main(){

    Livro **vet_livro = (Livro **) calloc(3, sizeof(Livro*));

    
    vet_livro[0] = cria_livro("Cafe com Deus pai", 200, 49.99);
    vet_livro[1] = cria_livro("Senhor dos aneis", 500, 59.99);
    vet_livro[2] = cria_livro("Harry Potter", 340, 39.99);
    
    for(int i = 0; i < 3; i++){
        print_livro(vet_livro[i]);
    }

    for(int i = 0; i < 3; i++){
        delete_livro(&vet_livro[i]);
    }

    free(vet_livro);
    vet_livro = NULL;
    
    
}