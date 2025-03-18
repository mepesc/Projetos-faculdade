#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 2
#define MAX_ELEITORES 2

void cadastrar_candidato();
void cadastrar_eleitores();
void iniciar_votacao();

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
                iniciar_votacao();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o errada!\n");
                break;
        }

    } while(opcao != 4);
}

typedef struct {
    char nome[100];
    char partido[3];
    int numero;
    int votos;
} Candidato;

typedef struct {
    char nome[100];
    int numero_titulo;
    int voto;  // Armazena o n�mero do candidato que o eleitor votou
} Eleitor;

Candidato candidatos[MAX_CANDIDATOS];
Eleitor eleitores[MAX_ELEITORES];

void cadastrar_candidato() {
    printf("Voc� est� na fun��o cadastrar candidato.\n");

    for (int i = 0; i < MAX_CANDIDATOS; i++) {
        printf("Digite o nome do candidato %d: ", i + 1);
        getchar();  
        fgets(candidatos[i].nome, sizeof(candidatos[i].nome), stdin);
        candidatos[i].nome[strcspn(candidatos[i].nome, "\n")] = 0; 

        printf("Digite o nome do partido do candidato %d: ", i + 1);
        scanf("%s", candidatos[i].partido);

        printf("Digite o n�mero do candidato %d: ", i + 1);
        scanf("%d", &candidatos[i].numero);

        candidatos[i].votos = 0;  // Inicializa a quantidade de votos como 0
    }
}

void cadastrar_eleitores() {
    printf("Voc� est� na fun��o cadastrar eleitores.\n");

    for (int i = 0; i < MAX_ELEITORES; i++) {
        printf("Digite o nome do eleitor %d: ", i + 1);
        getchar();  
        fgets(eleitores[i].nome, sizeof(eleitores[i].nome), stdin);
        eleitores[i].nome[strcspn(eleitores[i].nome, "\n")] = 0;  

        printf("Digite o n�mero do t�tulo de eleitor %d: ", i + 1);
        scanf("%d", &eleitores[i].numero_titulo);

        eleitores[i].voto = -1;  // Inicializa o voto como -1 (sem voto)
    }
}

void iniciar_votacao() {
    int voto_valido, numero_votado;

    printf("Iniciando a vota��o...\n");

    for (int i = 0; i < MAX_ELEITORES; i++) {
        printf("Eleitor %s, digite o n�mero do candidato para votar: \n", eleitores[i].nome);
        
        // Exibe os candidatos dispon�veis
        for (int j = 0; j < MAX_CANDIDATOS; j++) {
            printf("Candidato %d: %s (Partido %s) - N�mero: %d\n", j + 1, candidatos[j].nome, candidatos[j].partido, candidatos[j].numero);
        }

        printf("Digite o n�mero do candidato: ");
        scanf("%d", &numero_votado);

        // Verifica se o voto � v�lido
        voto_valido = 0;
        for (int j = 0; j < MAX_CANDIDATOS; j++) {
            if (candidatos[j].numero == numero_votado) {
                eleitores[i].voto = numero_votado;
                candidatos[j].votos++;  // Incrementa o voto do candidato
                voto_valido = 1;
                break;
            }
        }

        if (!voto_valido) {
            printf("Voto inv�lido! Tente novamente.\n");
            i--;  // Decrementa para repetir a vota��o do eleitor
        }
    }

    printf("\nVota��o conclu�da!\n");
    printf("Resultados da elei��o:\n");
    for (int i = 0; i < MAX_CANDIDATOS; i++) {
        printf("Candidato %s (Partido %s) recebeu %d votos.\n", candidatos[i].nome, candidatos[i].partido, candidatos[i].votos);
    }
}

int main() {
    menu_principal();
    return 0;
}

