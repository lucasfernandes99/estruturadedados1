typedef struct disciplina Disciplina;

/* Aloca dinamicamente uma estrutura do tipo Disciplina 
e retorna o seu endereço. Os campos nome e codigo devem 
ser fornecidos como parâmetros.*/
Disciplina* cria_disciplina(char nome[], int codigo);

/* Libera o espaço alocado dinamicamente para a estrutura 
da disciplina.*/
void exclui_disciplina(Disciplina* disciplina);