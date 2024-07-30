/*Arquivo cabeçalho para o tipo abstrato de dados (TAD) Aluno*/

/*Tipo exportado*/
typedef struct aluno Aluno;

/*Funçao que aloca dinamicamente uma struct aluno na memoria */
Aluno * alocarAluno(void);

/*Funçao para imprimir uma struct Aluno. A funçao recebe um endereço para aluno e imprime os dados*/
void imprime(Aluno *aluno);

/*Funçao para preencher uma struct Aluno. A funçao recebe um endereço para aluno*/
void captura(Aluno *aluno);
