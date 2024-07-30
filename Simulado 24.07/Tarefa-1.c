#include<stdio.h>

typedef union doc{
    long int RG;
    char CPF[14];
    long int passaporte;
    long int sus;
}Doc;

typedef enum genero{
    MASCULINO,
    FEMININO
}Genero;

typedef struct pessoa{
    char nome[20];
    Doc documentos;
    int idade;
    Genero genero;
    int op_doc;
}Pessoa;

void preenche (Pessoa *p,int quant){

    for (int i=0;i<quant;i++){
        printf("\nInforme o nome: ");
        scanf(" %[^\n]", p[i].nome);
        printf("Informe um documento: 1 - RG | 2 - CPF | 3 - Passaporte | 4 - Num. SUS \t");
        scanf("%d", &p[i].op_doc);
        switch (p[i].op_doc){
        case 1:
            scanf("%ld",&p[i].documentos.RG);
            break;
        case 2:
            scanf(" %[^\n]",p[i].documentos.CPF);
            break;
        case 3:
            scanf("%ld",&p[i].documentos.passaporte);
            break;
        case 4:
            scanf("%ld",&p[i].documentos.sus);
            break;
        
        default:
            printf("Documento invalido\n");
            break;
        }
        printf("Informe a idade: ");
        scanf("%d",&p[i].idade);
        printf("Informe o genero: 0 - MASCULINO ou 1 - FEMININO\t");
        scanf("%d", &p[i].genero);
    }
}

void imprime (Pessoa *p,int quant){

    for (int i=0;i<quant;i++){
        printf("\nDados da Pessoa %d:\n",i+1);
        printf("Nome: %s\n", p[i].nome);
        switch (p[i].op_doc){
        case 1:
            printf("Documento: %ld\n", p[i].documentos.RG);
            break;
        case 2:
            printf("Documento: %s\n",p[i].documentos.CPF);
            break;
        case 3:
            printf("Documento: %ld\n",p[i].documentos.passaporte);
            break;
        case 4:
            printf("Documento: %ld\n",p[i].documentos.sus);
            break;
        default:
            printf("Documento invalido\n");
            break;
        }
        printf("Idade: %d\n", p[i].idade);
        switch (p[i].genero){
            case MASCULINO:
                printf("Genero: Masculino\n");
                break;
            case FEMININO:
                printf("Genero: Feminino\n");
                break;
            default:
                printf("Genero invalido\n");
                break;
        }
    }
}

void atualizaIdade(Pessoa *p,int quant){
    for (int i=0;i<quant;i++){
        printf("\nDigite a nova idade da Pessoa %d: ",i+1);
        scanf("%d", &p[i].idade);
    }
}

void buscarMaisvelho_Maisnovo(Pessoa *p,int quant){
    Pessoa *maisVelho = &p[0];
    Pessoa *maisNovo = &p[0];
    for (int i=1;i<quant;i++){
        if(p[i].idade > maisVelho->idade){
            maisVelho = &p[i];
        }
        if(p[i].idade < maisNovo->idade){
            maisNovo = &p[i];
        }
    }

    printf("\nPessoa mais velha:\n");
    printf("Nome: %s\n",maisVelho->nome);
    switch (maisVelho->genero){
            case MASCULINO:
                printf("Genero: Masculino\n");
                break;
            case FEMININO:
                printf("Genero: Feminino\n");
                break;
            default:
                printf("Genero invalido\n");
                break;
        }

    printf("\nPessoa mais nova:\n");
    printf("Nome: %s\n",maisNovo->nome);
    switch (maisNovo->genero){
            case MASCULINO:
                printf("Genero: Masculino\n");
                break;
            case FEMININO:
                printf("Genero: Feminino\n");
                break;
            default:
                printf("Genero invalido\n");
                break;
        }
}

int main(void){
    Pessoa p;
    int quant;

    printf("Digite a quantidade de pessoas a cadastrar: ");
    scanf("%d",&quant);

    preenche(&p,quant);
    imprime(&p,quant);
    atualizaIdade(&p,quant);
    buscarMaisvelho_Maisnovo(&p,quant);
    
    return 0;
}