#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contabancaria.h"

struct contabancaria{
    char titular[50];
    int numero;
    float saldo;
};

ContaBancaria* cria_conta(char titular[], int numero, float saldo){
    ContaBancaria* conta = (ContaBancaria*) malloc (sizeof(ContaBancaria));
    if(conta==NULL){
        printf("Memoria nao alocada!");
        exit(1);
    }
    strcpy(conta->titular,titular);
    conta->numero = numero;
    conta->saldo = saldo;
    
    return conta;
}

void deposita(ContaBancaria* conta, float deposito){
    conta->saldo += deposito;
}

void saca(ContaBancaria* conta, float saque){
    if(conta->saldo<saque){
        printf("Saldo Insuficiente!\n");
        exit(1);
    }else{
        conta->saldo -=saque;
    }
}

void transfere(ContaBancaria* conta, float transferencia){
    if(conta->saldo<transferencia){
        printf("Saldo Insuficiente!\n");
        exit(1);
    }else{
        conta->saldo -=transferencia;
    }
}

void saldo(ContaBancaria* conta){
    printf("Saldo: R$ %.2f",conta->saldo);
}

void exclui_conta(ContaBancaria* conta){
    free(conta);
}