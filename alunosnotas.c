#include <stdio.h>

int main() {
    int alunos, chamada;
    float media;
    int aprovados[100] = {0}, recuperacao[100] = {0}, reprovados[100] = {0};
    int aprove = 0, rere = 0, reprove = 0;
    float notap[100] = {0.0}, notar[100] = {0.0}, notaf[100] = {0.0};
    float np = 0.0, nr = 0.0, nf = 0.0;
    int i,j, k, l;

    scanf("%d", &alunos);

    for(i = 0; i < alunos; i++) {
        scanf("%d %f", &chamada, &media);

        if(media >= 7.0) {
            aprovados[aprove] = chamada;
            aprove++;
            notap[np] = media;
            np++;

        } else if(media >= 5.0 && media < 7.0) {
            recuperacao[rere] = chamada;
            rere++;
            notar[nr] = media;
            nr++;

        } else if(media < 5.0) {
            reprovados[reprove] = chamada;
            reprove++;
            notaf[nf] = media;
            nf++;

        }
    }

    for(j = 0; j < aprove; j++) {
        scanf("%d %f", &aprovados[aprove], notap[np]);

        printf("Aprovados: %d (%f)\n", aprove, np);
    }

    for(k = 0; k < rere; k++) {
        scanf("%d %f", &recuperacao[rere], notar[nr]);

        printf("Recuperação: %d (%f)\n", rere, nr);
    }

    for(l = 0; l < reprove; l++) {
        scanf("%d %f", &reprovados[reprove], &notaf[nf]);

        printf("Reprovados: %d (%f)\n", reprove, nf);
    }

    return 0;
}