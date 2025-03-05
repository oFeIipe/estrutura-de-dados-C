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

typedef struct _aluno
{
    char nome[100];
    int idade;
    Livro *livro;
}Aluno;

Livro *cria_livro(const char *titulo, int num_paginas, float preco){
    Livro *livro =  (Livro *) calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->numero_paginas = num_paginas;
    livro->preco = preco;

    return livro;
}

Livro *copy_livro(Livro *livro){
    return cria_livro(livro->titulo, livro->numero_paginas, livro->preco);
}

Aluno *cria_aluno(char *nome, int idade, Livro *livro){
    Aluno *aluno = (Aluno *) calloc(1, sizeof(Aluno));

    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro = copy_livro(livro);

    return aluno;
}

void delete_livro(Livro **livro_ref){
    Livro *aux = *livro_ref;
    free(aux);
    *livro_ref = NULL;
}

void delete_aluno(Aluno **aluno_ref){
    Aluno *aluno = *aluno_ref;
    delete_livro(&aluno->livro);
    free(aluno);
    *aluno_ref = NULL;
}

void print_livro(Livro *Livro){
    printf("Titulo: %s\n", Livro->titulo);
    printf("Numero de paginas: %d\n", Livro->numero_paginas);
    printf("Preco: R$%.2f\n", Livro->preco);
    printf("Endereco de memoria: %p\n\n", Livro);
}

void print_aluno(Aluno *aluno){
    printf("Nome: %s\n", aluno->nome);
    printf("idade: %d\n", aluno->idade);
    puts("--------");
    print_livro(aluno->livro);
}

bool sao_iguais(Livro *livro1, Livro *livro2){
    return strcmp(livro1->titulo, livro2->titulo) == 0;
}

int main(){
    Livro *livro = cria_livro("Cafe com Deus pai", 200, 49.99);
    Aluno *aluno1 = cria_aluno("Fulanderson", 30, livro);

    print_aluno(aluno1);

    puts("\n");

    if(sao_iguais(aluno1->livro, livro)){
        printf("TRUE");
    }
    else{
        printf("FALSE");
    }

    puts("\n");
    
    delete_livro(&livro);

    printf("livro == NULL? %d\n", livro == NULL);

    delete_aluno(&aluno1);

    printf("aluno1 == NULL? %d\n", aluno1 == NULL);

    

    
}