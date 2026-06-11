#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    char pais[26];
    int aeroportos;
} Cidade;

void lermatriz(int **tabela, int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        for(int j = 0; j < quantidade; j++) {
            scanf("%d", &tabela[i][j]);
        }
    }
}

Cidade analise(int quantidade, Cidade *city, int **tabela, int destino, int *preco, char *destino_nome) {
    Cidade melhor;
    melhor.aeroportos = 0;
    melhor.nome[0] = '\0';
    int barato = 999999;
    int alvo = destino;

    for(int i = 0; i < quantidade; i++) {
        if(tabela[i][alvo] < barato && tabela[i][alvo] != -1) {
            barato = tabela[i][alvo];
            melhor = city[i];
        }
    }
    *preco = barato;
    strcpy(destino_nome, city[alvo].nome);

    return melhor;
}

Cidade impressao(Cidade info, int *preco, char *destino_nome) {
    if(info.aeroportos == 0) {
        printf("Não há voos disponíveis para essa cidade\n");
    } else {
        printf("Voo mais barato chegando em %s: %s (%s) - %d aeroporto(s) - R$%d\n", destino_nome, info.nome, info.pais, info.aeroportos, *preco);
        
    }
}

void freedom(int *preco, char *destino_nome, Cidade *city, int **tabela, int quantidade) {
    free(preco);
    free(destino_nome);
    free(city);
    for(int i = 0; i < quantidade; i++) {
        free(tabela[i]);
    }
    free(tabela);
}

int main() {
    int quantidade, aux = 0, destino;
    int *preco = malloc(sizeof(int));
    char *destino_nome = malloc(51 * sizeof(char));

    scanf("%d", &quantidade);
    getchar();

    Cidade *city = malloc(quantidade * sizeof(Cidade));

    int **tabela = (int **)malloc(quantidade * sizeof(int *));
    for(int i = 0; i < quantidade; i++) {
        tabela[i] = (int *)malloc(quantidade * sizeof(int));
    }

    while(aux < quantidade) {
        fgets(city[aux].nome, 51, stdin);
        city[aux].nome[strcspn(city[aux].nome, "\n")] = '\0';
        fgets(city[aux].pais, 26, stdin);
        city[aux].pais[strcspn(city[aux].pais, "\n")] = '\0';
        scanf("%d", &city[aux].aeroportos);
        getchar();

        aux++;
    }

    lermatriz(tabela, quantidade);

    scanf("%d", &destino);

    Cidade ideal = analise(quantidade, city, tabela, destino, preco, destino_nome);

    impressao(ideal, preco, destino_nome);

    freedom(preco, destino_nome, city, tabela, quantidade);

    return 0;
}