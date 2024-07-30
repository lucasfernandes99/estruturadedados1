#include<stdio.h>
#include<stdlib.h>

int main(void){
    int tamanho;
    printf("informe o tamanho do vetor: \t");
    scanf("%d", &tamanho);
    int * vetor = (int*) malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        exit(1);
    }
    printf("Digite os elementos do vetor: \n");
    for(int count=0; count<tamanho;count++){
        scanf("%d", &vetor[count]);
    }

    printf("Vetor Inverso: \n");
    for (int count = tamanho-1; count>=0; count--){
        printf("%d \t", vetor[count]);
    }
    free(vetor);
    
    return 0;
}