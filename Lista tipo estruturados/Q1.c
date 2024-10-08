#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 2

typedef struct aluno{
    int mat;
    char nome[100];
    float notas[3];
    float media;
}Aluno;

typedef struct turma{
    char id;  
    int vagas; 
    Aluno *alunos[MAX_VAGAS];
}Turma;

Turma *cria_turma(char id){
    Turma *turma=malloc(sizeof(Turma)); 
    turma->vagas=MAX_VAGAS;
    turma->id=id;
    int i;
    for (i=0;i<MAX_VAGAS;i++){
        turma->alunos[i]=NULL; 
    }
    return turma;
}

void imprime_turmas(Turma **turmas,int n){
    int i;
    printf("Listando turmas...\n");
    for(i=0;i<n;i++){
        Turma *turma=turmas[i];
        printf("Turma %c - Vagas disponiveis: %d\n",turma->id,turma->vagas);
    }
}

Turma *procura_turma(Turma **turma,int n,char id){
    int i=0, indice=-1;
    for(i=0;i<n;i++){
        if(turma[i]->id==id){
            indice=i;
        }
    }
    if(indice==-1){
        return NULL;
    }else{
        return turma[indice];
    }
}

void matricula_aluno(Turma *turma,int mat,char *nome){
    if(turma->vagas==0){
        printf("Nao ha vagas disponiveis na turma %c.\n",turma->id);
        return;
    }

    Aluno *novo_aluno=malloc(sizeof(Aluno)); 
    novo_aluno->mat=mat;
    strcpy(novo_aluno->nome,nome);
    novo_aluno->notas[0]=0;
    novo_aluno->notas[1]=0;
    novo_aluno->notas[2]=0;
    novo_aluno->media=0;
    int i;
    for(i=0;i<MAX_VAGAS;i++){
        if(turma->alunos[i]==NULL){
            turma->alunos[i]=novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

void lanca_notas(Turma *turma){
    int s,j;
    float soma=0.0;
    for(j=0;j<MAX_VAGAS;j++){
        if(turma->alunos[j]!=NULL){
            printf("Matricula: %d \tAluno: %s\n",turma->alunos[j]->mat,turma->alunos[j]->nome);
            for(s=0;s<3;s++){
                printf("Digite a nota %d: ",s+1);
                scanf("%f",&turma->alunos[j]->notas[s]); 
            }
            for(s=0;s<3;s++){
                soma+=turma->alunos[j]->notas[s];
            }
            turma->alunos[j]->media=soma/3;
        }
    }
    printf("Notas lancadas com sucesso!\n");
}

void imprime_alunos(Turma *turma){
    int i;
    for(i=0;i<MAX_VAGAS;i++){
        Aluno *aluno=turma->alunos[i];
        if(aluno!=NULL){
            printf("Matricula: %d\n",aluno->mat);
            printf("Nome: %s\n",aluno->nome);
            printf("Media: %.1f\n\n",aluno->media);
        }
    }
}

int main(void){
    
    int i;
    char id,nome[100];
    Turma **turma=(Turma**) malloc(MAX_TURMAS*sizeof(Turma*));
    if(turma==NULL){
        printf("ERRO");
        exit(1);
    }
    Turma *minhaTurma;
    int op=0,n=0,matricula=0;
    
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
    printf("funcionalidades de matricula, lancamento de notas e listagem de\n");
    printf("alunos.\n");
    printf("Autor: Ada Lovelace\t Versao: 1.0\n");

    while(op!=6){ 
        printf("\n\n\tMenu:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                printf("Criando nova turma...");
                printf("\nDigite um id: ");
                scanf(" %c",&id);
                if(n==MAX_TURMAS){
                    printf("Limite maximo atingido");
                }else if(procura_turma(turma,n,id)!=NULL){
                    printf("A turma Ja existe!");
                }else{
                    turma[n]=(Turma*)malloc(sizeof(Turma));
                    turma[n]=cria_turma(id);
                    n++;
                    printf("Turma %c criada com sucesso!",id);
                }
                break;
            case 2:
                imprime_turmas(turma, n);
                break;
            case 3:
                printf("Matriculando aluno...");
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                minhaTurma=procura_turma(turma,n,id);
                if(minhaTurma!=NULL){
                    printf("Digite a matricula: ");
                    scanf("%d",&matricula);
                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", (char *)&nome);
                    matricula_aluno(minhaTurma,matricula,nome);
                }else{
                    printf("Turma inexistente!");
                }
                break;
            case 4:
                printf("Lancando notas...");
                printf("\nDigite o id da turma: ");
                scanf(" %c", &id);
                minhaTurma=procura_turma(turma,n,id);
                if(minhaTurma!=NULL){
                    lanca_notas(minhaTurma);
                }else{
                    printf("Turma inexistente!");
                }
                break;
            case 5:
                printf("Listando alunos...");
                printf("\nDigite o id da turma: ");
                scanf(" %c",&id);
                minhaTurma=procura_turma(turma,n,id);
                if (minhaTurma!=NULL){
                    imprime_alunos(minhaTurma);
                }else{
                    printf("Turma inexistente!");
                }
                break;
            case 6:
                printf("Obrigado por usar este programa!");
                break;
            default:
                printf("opcao invalida!");
                break;
            }
        }
    for(i=0;i<n;i++){
        free(turma[i]);
    }
    free(turma);
    return 0;
}