#include <stdio.h>

int main() {
    int alunos, chamada, medias;
    int aprovados[n], recuperacao[m], reprovados[o];
    int i;

    scanf("%d", &alunos);

    for(i = 0; i < alunos; i++) {
        scanf("%d" - "%d", &chamada, &medias);

        if(medias >= 7) {
            aprovados[n] = chamada;
            n++;
        } else if(medias >= 5 && medias < 7) {
            recuperacao[m] = chamada;
            m++;
        } else if(medias < 5) {
            reprovados[o] = chamada;
            o++;
        }
    }

    printf("Aprovados: %d\nRecuperacao: %d\nReprovados: %d\n", aprovados[n], recuperacao[m], reprovados[o]);

    return 0;
}