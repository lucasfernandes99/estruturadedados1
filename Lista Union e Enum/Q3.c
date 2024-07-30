#include <stdio.h>
#include <stdlib.h>

typedef enum mes{
    JANEIRO = 1, 
    FEVEREIRO, 
    MARCO, 
    ABRIL, 
    MAIO, 
    JUNHO,
    JULHO, 
    AGOSTO, 
    SETEMBRO, 
    OUTUBRO, 
    NOVEMBRO, 
    DEZEMBRO
} Mes;

typedef struct data{
    int dia;
    Mes mes;
    int ano;
} Data;

void lerData(Data *d) {
    int mes;

    printf("Digite o dia: ");
    scanf("%d", &d->dia);

    printf("Digite o mes (1 para JANEIRO, 2 para FEVEREIRO, ..., 12 para DEZEMBRO): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido! \n");
        exit(1);
    } else {
        d->mes = (Mes)mes;
    }

    printf("Digite o ano: ");
    scanf("%d", &d->ano);
}

void imprimirData(const Data *d) {
    printf("%02d/%02d/%04d\n", d->dia, d->mes, d->ano);
}

int main() {
    Data data;

    lerData(&data);
    imprimirData(&data);

    return 0;
}