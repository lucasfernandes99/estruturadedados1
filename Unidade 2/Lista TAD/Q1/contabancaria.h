typedef struct contabancaria ContaBancaria;

/* Funçao que aloca dinamicamente uma struct ContaBancaria
e retorna seu endereço.

Os parametros necessarios sao: titular, numero e saldo. */
ContaBancaria* cria_conta(char titular[], int numero, float saldo);

/* Funçao que realiza deposito e atualiza o saldo da conta */
void deposita(ContaBancaria* conta, float deposito);

/* Funçao que realiza saque e atualiza o saldo da conta */
void saca(ContaBancaria* conta, float saque);

/* Funçao que realiza transferencia e atualiza o saldo da conta*/
void transfere(ContaBancaria* conta, float transferencia);

/* Funçao que exibe o saldo da conta bancaria */
void saldo(ContaBancaria* conta);

/* Funçao responsavel para liberar o espaço de memoria alocado dinamicamente*/
void exclui_conta(ContaBancaria* conta);