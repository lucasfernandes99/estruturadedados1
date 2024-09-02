#include"aluno.c"

int main() {
    const char *nomeArquivo = "alunos.txt";

    criarArquivo(nomeArquivo);

    Aluno aluno1 = criarAluno(123, "Maria", 8.5);
    Aluno aluno2 = criarAluno(456, "Joao", 7.2);
    Aluno aluno3 = criarAluno(789, "Ana", 9.1);

    salvarAlunoEmArquivo(nomeArquivo, aluno1);
    salvarAlunoEmArquivo(nomeArquivo, aluno2);
    salvarAlunoEmArquivo(nomeArquivo, aluno3);

    exibirAlunos(nomeArquivo);

    return 0;
}