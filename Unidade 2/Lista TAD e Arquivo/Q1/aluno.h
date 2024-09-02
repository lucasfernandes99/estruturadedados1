// Definição da TAD Aluno
typedef struct aluno Aluno;

// Função para criar um novo aluno
Aluno criarAluno(int matricula, const char *nome, float media);

// Função para salvar um aluno em um arquivo
void salvarAlunoEmArquivo(const char *nomeArquivo, Aluno aluno);

// Função para exibir todos os alunos cadastrados em um arquivo
void exibirAlunos(const char *nomeArquivo);

// Função para criar um arquivo de texto vazio (caso não exista)
void criarArquivo(const char *nomeArquivo);