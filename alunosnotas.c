#include <stdio.h>

int main() {
    int alunos, chamada, medias;
    int aprovados[100] = {0}, recuperacao[100] = {0}, reprovados[100] = {0};
    int i,j, k, l;

    scanf("%d", &alunos);

    for(i = 0; i < alunos; i++) {
        scanf("%d - %d", &chamada, &medias);

        if(medias >= 7) {
            aprovados[alunos] = chamada;
            alunos++;

        } else if(medias >= 5 && medias < 7) {
            recuperacao[alunos] = chamada;
            alunos++;

        } else if(medias < 5) {
            reprovados[alunos] = chamada;
            alunos++;
        }
    }

    for(j = 0; j < 100; j++) {
        scanf("%d", &aprovados[j]);
    }

    printf("Aprovados: %d\n", aprovados[j]);

    return 0;
}