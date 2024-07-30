#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"

struct aluno {
    int mat;
    char nome[20];
    int idade;
};

Aluno * alocarAluno(void){
    Aluno *aluno=(Aluno*)malloc(sizeof(Aluno));
    if(aluno==NULL){
    printf("Falha na Alocacao Dinamica!!!\n");
    exit(1);
    }
    return aluno;
}

void imprime(Aluno *aluno){
    printf("Nome: %s \t Idade: %d \t Matricula: %d\n", aluno->nome, aluno->idade, aluno->mat);
}
void captura(Aluno *aluno){
    printf("Digite o nome\n");
    scanf(" %[^\n]", &aluno->nome);
    printf("Digite idade e matricula\n");
    scanf("%d %d", &aluno->idade, &aluno->mat);
}
