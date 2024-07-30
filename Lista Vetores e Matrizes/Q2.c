#include<stdio.h>
#include<stdlib.h>

int main (void){
    int linhas,colunas,cont,i,j;

    printf("Informe o numero de linhas:\n");
    scanf("%d",&linhas);
    printf("Informe o numero de colunas:\n");
    scanf("%d",&colunas);
    
    int **matriz=(int**) malloc(linhas*sizeof(int**));
    if (matriz==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    for(cont=0;cont<linhas;cont++){
        matriz[cont]=(int*) malloc(colunas*sizeof(int));
        if (matriz==NULL){
        printf("Erro de alocacao\n");
        exit(1);
        }
    }

    int linha,coluna;
    printf("Digite os dados da matriz:\n");
    for(linha=0;linha<linhas;linha++){
        for(coluna=0;coluna<colunas;coluna++){
        scanf("%d",&matriz[linha][coluna]);
        }
    }

    int **matrizT=(int**) malloc(linhas*sizeof(int**));
    if (matrizT==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    for(cont=0;cont<linhas;cont++){
        matrizT[cont]=(int*) malloc(colunas*sizeof(int));
        if (matrizT==NULL){
        printf("Erro de alocacao\n");
        exit(1);
        }
    }
    for(linha=0;linha<linhas;linha++){
        for(coluna=0;coluna<colunas;coluna++){
            matrizT[linha][coluna]=matriz[coluna][linha];
        }
    }

    printf("Matriz Original\n");
    for(linha=0;linha<linhas;linha++){
        for(coluna=0;coluna<colunas;coluna++){
            printf("%d ",matriz[linha][coluna]);
        }
        printf("\n");
    }

     printf("Matriz Transposta\n");
    for(linha=0;linha<linhas;linha++){
        for(coluna=0;coluna<colunas;coluna++){
            printf("%d ",matrizT[linha][coluna]);
        }
        printf("\n");
    }
    for(linha=0;linha<linhas;linha++){
        free(matriz[linha]);
        free(matrizT[linha]);
    }
    free(matriz);
    free(matrizT);


    return 0;
    
}