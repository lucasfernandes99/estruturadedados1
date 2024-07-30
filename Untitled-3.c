#include<stdio.h>

enum dias_semana{
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
};

int main(void){
    enum dias_semana dia;
    dia = SEGUNDA;
    printf("Dia da semana: %d\n", dia);
    return 0;
}
