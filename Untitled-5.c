#include<stdio.h>

typedef enum dias_semana{
    SEGUNDA=2,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
}DiaSemana;

typedef enum mes{
    JANEIRO=1,
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
}Mes;

int main(void){
    DiaSemana d;
    Mes m;
    printf("Informe o dia da semana: 2 - 8 \t");
    scanf("%d",&d);
    printf("Informe o mes: 1 - 12 \t");
    scanf("%d",&m);
    switch(d){
        case SEGUNDA:
            printf("Segunda-feira\t");
            break;
        case TERCA:
            printf("Terca-feira\t");
            break;
        case QUARTA:
            printf("Quarta-feira\t");
            break;
        case QUINTA:
            printf("Quinta-feira\t");
            break;
        case SEXTA:
            printf("Sexta-feira\t");
            break;
        case SABADO:
            printf("Sabado\t");
            break;
        case DOMINGO:
            printf("Domingo\t");
            break;
        default:
            printf("Dia nao cadastrado!");
            break;
    }

        switch(m){
        case JANEIRO:
            printf("Janeiro\n");
            break;
        case FEVEREIRO:
            printf("Fevereiro\n");
            break;
        case MARCO:
            printf("Marco\n");
            break;
        case ABRIL:
            printf("Abril\n");
            break;
        case MAIO:
            printf("Maio\n");
            break;
        case JUNHO:
            printf("Junho\n");
            break;
        case JULHO:
            printf("Julho\n");
            break;
        case AGOSTO:
            printf("Agosto\n");
            break;
        case SETEMBRO:
            printf("Setembro\n");
            break;
        case OUTUBRO:
            printf("Outubro\n");
            break;
        case NOVEMBRO:
            printf("Novembro\n");
            break;
        case DEZEMBRO:
            printf("Dezembro\n");
            break;
        default:
            printf("Mes nao cadastrado!");
            break;
    }
    
    return 0;
}