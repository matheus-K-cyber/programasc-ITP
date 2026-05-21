#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max(char *p1, char *p2, int *maiorD, int *menorD) {
    *maiorD = strlen(p1);
    *menorD = strlen(p2);

    if (*menorD > *maiorD) {
        int temp = *maiorD;
        *maiorD = *menorD;
        *menorD = temp;
    }
}

void cabecalho(char **palavras, int quantidade) {
    printf("%-10s", " ");

    for(int i = 0; i < quantidade; i++) {
        printf("%10s", palavras[i]);
    }

    printf("\n");
}

void lateral(char *p1) {
        printf("%-10s", p1);
}

void resultado(int similaridade, int maiorD) {
        char espaco[10];

        sprintf(espaco, "%d/%d", similaridade, maiorD);

        printf("%10s", espaco);

}

void analise(char **palavras, int quantidade) {
    cabecalho(palavras, quantidade);

    int i, j, k;
    int maior, menor;

    for(i = 0; i < quantidade; i++) {
        lateral(palavras[i]);

        for(j = 0; j < quantidade; j++) {
            max(palavras[i], palavras[j], &maior, &menor);
            int similaridade = 0;

            for(k = 0; k < menor; k++) {
                if(palavras[i][k] == palavras[j][k]) {
                    similaridade++;
                }

            }
        resultado(similaridade, maior);
        }
    printf("\n");
    }
}

int main() {
    int quantidade;

    scanf("%d", &quantidade);

    char **palavras = malloc(quantidade * sizeof(char *));
    for (int i = 0; i < quantidade; i++) {
        palavras[i] = malloc(10 * sizeof(char));
        scanf(" %s", palavras[i]);
    }

    if (quantidade >= 2) {
        analise(palavras, quantidade);
    }

    return 0;
}