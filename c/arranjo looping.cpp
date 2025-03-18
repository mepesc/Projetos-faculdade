#include <stdio.h>
#include <string.h>

void cadastrar_candidato();
void cadastrar_eleitores();

void imprime() {
    printf("Seja bem-vindo � urna \n\n");
}

void menu_principal() {
    int opcao;

    do {
        printf("O que deseja fazer?\n");
        printf("1 - Cadastrar os candidatos\n");
        printf("2 - Cadastrar os eleitores\n");
        printf("3 - Iniciar a vota��o\n");
        printf("4 - Sair do programa\n\n");

        printf("Escolha a sua op��o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_candidato();
                break;
            case 2:
                cadastrar_eleitores();
                break;
            case 3:
                // Implementar a fun��o de vota��o
                break;
            case 4:
                // Finaliza o programa
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o errada!\n");
                break;
        }

    } while(opcao != 4);
}

void cadastrar_candidato() {
    printf("Voc� est� na fun��o cadastrar candidato.\n");

    char nome_candidato[2][100];
    char nome_partido[2][3];
    int numero_candidato[2];
    
    for (int i = 0; i < 2; i++) {
        printf("Digite o nome do candidato: ");
        getchar(); // Limpa o buffer do teclado antes de usar fgets
        fgets(nome_candidato[i], sizeof(nome_candidato[i]), stdin);
        nome_candidato[i][strcspn(nome_candidato[i], "\n")] = 0; // Remove a nova linha gerada pelo fgets

        printf("Digite o nome do partido: ");
        scanf("%s", nome_partido[i]);

        printf("Digite o n�mero do candidato: ");
        scanf("%d", &numero_candidato[i]);
    }
}

void cadastrar_eleitores() {
    printf("Voc� est� na fun��o cadastrar eleitores.\n");

    char nome_eleitor[2][100];
    int numero_titulo[2];  // Corre��o: o vetor de t�tulo deve ser 2, n�o 100

    for (int i = 0; i < 2; i++) {
        printf("Digite o nome do eleitor: ");
        getchar(); // Limpa o buffer do teclado antes de usar fgets
        fgets(nome_eleitor[i], sizeof(nome_eleitor[i]), stdin);
        nome_eleitor[i][strcspn(nome_eleitor[i], "\n")] = 0; // Remove a nova linha gerada pelo fgets

        printf("Digite o 




