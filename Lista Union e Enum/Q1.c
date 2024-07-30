#include <stdio.h>

typedef enum genero{
    MASCULINO,
    FEMININO
} Genero;

typedef struct pessoa{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

void lerDados(Pessoa *p) {    
    Genero genero;

    printf("Digite o nome: ");
    scanf(" %[^\n]",p->nome);
    
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    
    printf("Digite o genero: 0 - MASCULINO ou 1 - FEMININO\t");
    scanf("%d",&genero);
    
}

void imprimirDados(Pessoa *p) {
    Genero genero;
    
    printf("\nDados da Pessoa:\n");
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    switch (genero){
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

int main() {
    Pessoa p;
    
    lerDados(&p);
    
    imprimirDados(&p);
    
    return 0;
}
