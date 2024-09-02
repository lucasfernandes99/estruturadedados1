#include"disciplina.h"
#include"aluno.h"

int main (void){
    Disciplina* disciplina;
    Aluno* aluno = cria_aluno("Lucas",2015);
    matricula_disciplina(aluno,disciplina);
    exclui_disciplina(disciplina);
    exclui_aluno(aluno);

    return 0;
}