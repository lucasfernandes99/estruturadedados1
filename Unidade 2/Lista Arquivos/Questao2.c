#include <stdio.h>
#include <stdlib.h>

int main(void){

    char linha[100];
    int v[10];
    FILE *e, *s;
    int i=0;
    float media=0;
    
    e = fopen("entrada_q2.txt","r");
    if (e==NULL) {
        printf("Erro na abertura do arquivo de entrada!\n");
        exit(1);
    }

    s = fopen("saida_q2.txt","w");
    if (s==NULL) {
        printf("Erro na abertura do arquivo de saida!\n");
        fclose(e);
        exit(1);
    }

    while(fgets(linha,100,e)!=NULL){
        sscanf(linha, "%d", &v[i]);
        media+=v[i];
        i++;
    }

    int menor = v[0];
    int maior = v[0];

    for(i=0; i<10; i++){
        if(v[i] < menor)
            menor =  v[i];
        if(v[i] > maior)
            maior =  v[i];
    }

    fprintf(s,"Menor Elemento: %d\nMaior Elemento: %d\nMedia dos Elementos: %f", menor, maior,media/10);
    
    fclose(e);
    fclose(s);

    return 0;
}