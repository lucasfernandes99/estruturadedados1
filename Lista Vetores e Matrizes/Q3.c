#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (void){
    int tamanho,cont;

    printf("Informe o tamanho da matriz quadrada:\n");
    scanf("%d",&tamanho);

    int **matriz=(int**) malloc(tamanho*sizeof(int**));
    if (matriz==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    for(cont=0;cont<tamanho;cont++){
        matriz[cont]=(int*) malloc(tamanho*sizeof(int));
        if (matriz==NULL){
        printf("Erro de alocacao\n");
        exit(1);
        }
    }

    int linha,coluna;

    for(linha=0;linha<tamanho;linha++){
        for(coluna=0;coluna<tamanho;coluna++){
        matriz[linha][coluna]=1+(rand()%100);
        }
    }

    printf("\n");
    printf("Matriz\n");
    for(linha=0;linha<tamanho;linha++){
        for(coluna=0;coluna<tamanho;coluna++){
            printf("%d ",matriz[linha][coluna]);
        }
        printf("\n");
    }

     
    for(linha=0;linha<tamanho;linha++){
        free(matriz[linha]);
    }
    free(matriz);


    return 0;
    
}