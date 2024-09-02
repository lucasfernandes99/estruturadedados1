#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"disciplina.h"
#include"aluno.h"

struct aluno{
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
};

Aluno* cria_aluno(char nome[], int matricula){
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));
    if(aluno==NULL){
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;

    return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina){
    char nome[50];
    int codigo;
    for (aluno->num_disciplinas=0;aluno->num_disciplinas<10;aluno->num_disciplinas++){
        printf("Digite o nome da Disciplina: ");
        scanf(" %[^\n]", nome);
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        aluno->disciplinas[aluno->num_disciplinas]=cria_disciplina(nome,codigo);
    }
}

void exclui_aluno(Aluno* aluno){
    free(aluno);
}
