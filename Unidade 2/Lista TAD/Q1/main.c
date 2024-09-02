#include "contabancaria.c"

int main (void){
    ContaBancaria* conta = cria_conta("Lucas",100,200.00);
    deposita(conta,300.00);
    saca(conta,300.00);
    transfere(conta,100.00);
    saldo(conta);
    exclui_conta(conta);
    
    return 0;
}