#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int premiado;
} Sorteio;

Sorteio grupo(char PARTICIPANTES[201]) {
    Sorteio s;

    s.premiado = 0;

    s.nome = malloc((strlen(PARTICIPANTES) + 1) * sizeof(char));

    if(s.nome == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nome.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(s.nome, PARTICIPANTES);

    return s;
}

Sorteio* listagem(Sorteio* sorteados, Sorteio integrantes, int N) {
    Sorteio* temp = realloc(sorteados, (N + 1) * sizeof(Sorteio));

    if(temp == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de sorteados.\n");
        exit(EXIT_FAILURE);
    }

    sorteados = temp;
    sorteados[N] = integrantes;

    return temp;
}

int main() {
    Sorteio* sorteados = NULL;
    Sorteio integrantes;
    char PARTICIPANTES[201];
    int indice_participante = 0, N = 0, semente;

    while(1) {
        fgets(PARTICIPANTES, 201, stdin);
        PARTICIPANTES[strcspn(PARTICIPANTES, "\n")] = '\0';

        if(strcmp(PARTICIPANTES, "acabou") == 0) {
            break;
        }

        integrantes = grupo(PARTICIPANTES);
        sorteados = listagem(sorteados, integrantes, N);
        N++;
    }

    scanf("%d", &semente);
    srand(semente);

    int count_sorteados = 0;

    while(count_sorteados < N) {
        indice_participante = rand() % N;

        if(sorteados[indice_participante].premiado == 0) {
            printf("%s\n", sorteados[indice_participante].nome);
            sorteados[indice_participante].premiado = 1;
            count_sorteados++;
        }
    }

    return 0;
}