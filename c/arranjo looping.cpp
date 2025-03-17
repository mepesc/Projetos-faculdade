#include <stdio.h>
#include <locale.h>

int main () {
    setlocale (LC_ALL, "portuguese");
    float notas[10], soma = 0, media;
    int i;

    for (i = 0; i < 10; i++)  {
        printf("Digite a %dª nota:", i + 1 );
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    media = soma / 10;
    printf("A media dos alunos é: %.2f\n", media);

  return 0;
}



