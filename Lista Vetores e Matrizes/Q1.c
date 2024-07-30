#include<stdio.h>
#include<stdlib.h>

int main (void){
    int tamanho;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d",&tamanho);

    int *vetor=(int*) malloc(tamanho*sizeof(int));
    if (vetor==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    else{
        printf("Alocacao realizada com sucesso\n");
    }
    int contador;
    printf("Digite os Valores do vetor: \n");
    for(contador=0;contador<tamanho;contador++){
        scanf("%d",&vetor[contador]);
    }
    for(contador=tamanho;contador>=0;contador--){
        printf("%d\n",vetor[contador]);
    }
    free(vetor);

    return 0;
    
}