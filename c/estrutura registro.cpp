#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// definicao da estrutura (registro)
struct Aluno {
    //campo para armazenar nome do aluno
    char nome[100];
    //campo para as notas
    float nota1, nota2, nota3, nota4;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    //criando uma variavel tipo aluno
    struct Aluno aluno;
    //atribuindo valores ao registro
    strcpy(aluno.nome, "Maria Eduarda");
    aluno.nota1 = 7.5;
    aluno.nota2 = 8.0;
    aluno.nota3 = 9.5;
    aluno.nota4 = 8.9;

    //exibindo os dados do registro
    printf("Nome: %s\n", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Nota 3: %.2f\n", aluno.nota3);
    printf("Nota 4: %.2f\n", aluno.nota4);
  return 0;
}
