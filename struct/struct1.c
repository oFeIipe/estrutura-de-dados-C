#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno{
    char nome[100];
    int idade;
}Aluno;

Aluno * alocaAluno(){
    return (Aluno *) calloc(1, sizeof(Aluno));
}

int main(){
    Aluno *aluno1 = alocaAluno();

    aluno1->idade = 20;
    strcpy(aluno1->nome, "Fulano da silva");

    printf("Idade de %s eh %d", aluno1->nome, aluno1->idade);
}
