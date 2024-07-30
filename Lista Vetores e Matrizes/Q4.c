#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

    int i,numero=0;

    printf("Digite o numero de pessoas: ");
    scanf("%d",&numero);
    if(numero>100){
        printf("Limite maximo de 100 pessoas!\n\n");
        printf("Digite o numero de pessoas: ");
        scanf("%d", &numero);
    }
 
    char**nome=(char**)malloc(numero*sizeof(char**));
    if(nome==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    } 

    int*idade=(int*)malloc(numero*sizeof(int));
    if(idade==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    } 
    for(i=0;i<numero;i++){
        nome[i]=(char*)malloc(50*sizeof(char));
        if (nome[i]==NULL){
            printf("Erro de alocacao\n");
            exit(1);
        } 

        printf("Digite o nome completo %d: ",i+1);
        scanf(" %[^\n]s",nome[i]);

        printf("Digite a idade %d: ",i+1);
        scanf("%d",idade+i);
    }

    printf("\nNomes Cadastrados:\n");
    for(i=0;i<numero;i++){
        printf("%s \n",nome[i]);
    }

    for(i=0;i<numero;i++){
        free(nome[i]);
    }
    free(nome);
    free(idade);
  
    return 0;
}