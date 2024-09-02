#include<stdio.h>
#include<stdlib.h>

int main(void){
    char nome[50];
    float media,n1,n2,n3;

    FILE * notas = fopen("entrada_q3.txt","r");
    if(notas == NULL){
        printf("Erro na abertura do arquivo de entrada!\n");
        return 1;
    }
    FILE * resultado = fopen("saida_q3.txt","wt");
    if(resultado == NULL){
        printf("Erro na abertura do arquivo de saida!\n");
        fclose(notas);
        return 1;
    }

    while(!feof(notas)){
        fscanf(notas,"%s\t%f\t%f\t%f", nome,&n1,&n2,&n3);
        media=(n1+n2+n3)/3;
        if(media>=7){
            fprintf(resultado,"%s\t%.1f\tAprovado\n", nome,media);
        }else{
            fprintf(resultado,"%s\t%.1f\tReprovado\n",nome,media);
        }
        
    }
    
    fclose(notas);
    fclose(resultado);

    return 0;
}
