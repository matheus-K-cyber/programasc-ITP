#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nlin, ncol;
    char **lab;
} LabirintoP;

typedef struct {
    int plin, pcol;
    int Bcomidas;
} Pacman;

LabirintoP* producao(int nlin, int ncol) {
    LabirintoP* m = malloc(sizeof(LabirintoP));
    m->nlin = nlin;
    m->ncol = ncol;
    m->lab = malloc(nlin * sizeof(char*));
    for (int i = 0; i < nlin; i++) {
        m->lab[i] = malloc(ncol * sizeof(char));
    }
    return m;
}

void leitura(LabirintoP *m){
    for (int i = 0; i < m->nlin; i++) {
        for (int j = 0; j < m->ncol; j++) {
            scanf(" %c", &m->lab[i][j]);
        }
    }
}

Pacman buscador(LabirintoP *m) {
    Pacman pacoord;

    for(int i = 0; i < m->nlin; i++) {
        for(int j = 0; j < m->ncol; j++) {
            if(m->lab[i][j] == 'C') {
                pacoord.plin = i;
                pacoord.pcol = j;
                break;
            }
        }
    }
    return pacoord;
}

void guia(LabirintoP *m, int plin, int pcol, int *Bcomidas, int passou[100][100]) {
    if(plin < 0 || plin >= m->nlin ||
       pcol < 0 || pcol >= m->ncol ||
       passou[plin][pcol] == 1 || m->lab[plin][pcol] == '*' ||
    m->lab[plin][pcol] == 'M') {
       return;
        } //caso base
    
    if(m->lab[plin][pcol] == '.') {
    m->lab[plin][pcol] = ' ';
    (*Bcomidas)++;
    }

    passou[plin][pcol] = 1;

    guia(m, plin - 1, pcol, Bcomidas, passou);
    guia(m, plin + 1, pcol, Bcomidas, passou);
    guia(m, plin, pcol - 1, Bcomidas, passou);
    guia(m, plin, pcol + 1, Bcomidas, passou);
}

void imprimir(LabirintoP *m, int Bcomidas) {
    printf("Total de bolinhas devoradas: %d\n", Bcomidas);
    printf("Mapa final:\n");

    for (int i = 0; i < m->nlin; i++) {
        for (int j = 0; j < m->ncol; j++) {
            printf("%c", m->lab[i][j]);
        }
        printf("\n");
    }
}

void freedom(LabirintoP **m) {
    for (int i = 0; i < (*m)->nlin; i++) {
        free((*m)->lab[i]);
    }
    free((*m)->lab);
    free(*m);
}

int main() {
    int lin, col;
    int passou[100][100];
    LabirintoP* mapa;
    Pacman bola;
    bola.Bcomidas = 0;

    memset(passou, 0, sizeof(passou));

    scanf("%d %d", &lin, &col);
    mapa = producao(lin, col);
    leitura(mapa);

    Pacman pacoord = buscador(mapa);

    guia(mapa, pacoord.plin, pacoord.pcol, &bola.Bcomidas, passou);

    imprimir(mapa, bola.Bcomidas);

    freedom(&mapa);

    return 0;
}