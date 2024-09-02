#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"disciplina.h"

struct disciplina{
    char nome[50];
    int codigo;
};

Disciplina* cria_disciplina(char nome[], int codigo){
    Disciplina* disciplina = (Disciplina*) malloc (sizeof(Disciplina));
    if(disciplina==NULL){
        printf("Memoria nao alocada!\n");
        exit(1);
    }
    strcpy(disciplina->nome, nome);
    disciplina->codigo = codigo;

    return disciplina;
}

void exclui_disciplina(Disciplina* disciplina){
    free(disciplina);
}