#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"

int main(void){
    Aluno * aluno = alocarAluno();
    captura(aluno);
    imprime(aluno);
    free(aluno);
    return 0;
}