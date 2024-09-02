#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    int matricula;
    char nome[50];
    float media;
};

Aluno criarAluno(int matricula, const char *nome, float media) {
    Aluno aluno;
    aluno.matricula = matricula;
    strncpy(aluno.nome, nome, sizeof(aluno.nome) - 1);
    aluno.nome[sizeof(aluno.nome) - 1] = '\0';
    aluno.media = media;
    return aluno;
}

void salvarAlunoEmArquivo(const char *nomeArquivo, Aluno aluno) {
    FILE *arquivo = fopen(nomeArquivo, "a"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    fprintf(arquivo, "%d\t%s\t%.2f\n", aluno.matricula, aluno.nome, aluno.media);
    fclose(arquivo);
}

void exibirAlunos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    Aluno aluno;
    printf("Matricula\tNome\t\tMedia\n");
    printf("---------------------------------------\n");
    while (fscanf(arquivo, "%d\t%[^\t]\t%f\n", &aluno.matricula, aluno.nome, &aluno.media) == 3) {
        printf("%d\t\t%s\t\t%.2f\n", aluno.matricula, aluno.nome, aluno.media);
    }

    fclose(arquivo);
}

void criarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    fclose(arquivo);
    printf("Arquivo '%s' criado com sucesso!\n", nomeArquivo);
}