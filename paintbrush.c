#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nlin, ncol;
    char **folha;
} Paintbrush;

Paintbrush* producao(int nlin, int ncol) {
    Paintbrush* f = malloc(sizeof(Paintbrush));
    f->nlin = nlin;
    f->ncol = ncol;
    f->folha = malloc(nlin * sizeof(char*));
    for (int i = 0; i < nlin; i++) {
        f->folha[i] = malloc(ncol * sizeof(char));
    }
    return f;
}

void leitura(Paintbrush *f){
    for (int i = 0; i < f->nlin; i++) {
        for (int j = 0; j < f->ncol; j++) {
            scanf(" %c", &f->folha[i][j]);
        }
    }
}

void preenchimento(Paintbrush *f, int inlin, int incol, char ideal, char base, int pintado[100][100]) {
    if(inlin < 0 || inlin >= f->nlin ||
       incol < 0 || incol >= f->ncol ||
       pintado[inlin][incol] == 1 || f->folha[inlin][incol] != base) {
       return;
        } //caso base
    f->folha[inlin][incol] = ideal;
    pintado[inlin][incol] = 1;

    preenchimento(f, inlin - 1, incol, ideal, base, pintado);
    preenchimento(f, inlin + 1, incol, ideal, base, pintado);
    preenchimento(f, inlin, incol - 1, ideal, base, pintado);
    preenchimento(f, inlin, incol + 1, ideal, base, pintado);
}

void imprimir(Paintbrush *f) {
    for (int i = 0; i < f->nlin; i++) {
        for (int j = 0; j < f->ncol; j++) {
            printf("%c", f->folha[i][j]);
        }
        printf("\n");
    }
}

void freedom(Paintbrush *f, int pintado[100][100]) {
    for (int i = 0; i < f->nlin; i++) {
        free(f->folha[i]);
    }
    free(f->folha);
    free(f);
}

int main() {
    int lin, col, inlin, incol;
    char ideal;
    int pintado[100][100];
    Paintbrush* folha;

    memset(pintado, 0, sizeof(pintado));

    scanf("%i %i", &lin, &col);
    folha = producao(lin, col);
    leitura(folha);

    scanf("%i %i", &inlin, &incol);
    scanf(" %c", &ideal);

    char base = folha->folha[inlin][incol];
    
    preenchimento(folha, inlin, incol, ideal, base, pintado);

    imprimir(folha);

    freedom(folha, pintado);

    return 0;
}