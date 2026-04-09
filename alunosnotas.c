#include <stdio.h>

int main() {
    int alunos, chamada;
    float media;
    int aprovados[100] = {0}, recuperacao[100] = {0}, reprovados[100] = {0};
    int aprove = 0, rere = 0, reprove = 0;
    float notap[100] = {0}, notar[100] = {0}, notaf[100] = {0};
    int np = 0, nr = 0, nf = 0;
    int i,j, k, l;

    scanf("%d", &alunos);

    for(i = 0; i < alunos; i++) {
        scanf("%d - %f", &chamada, &media);

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

    printf("Aprovados: ");
    for(j = 0; j < aprove; j++) {
        if(j < aprove - 1) {
            printf(" %d (%.1f),", aprovados[j], notap[j]);
        } else {
            printf(" %d (%.1f)\n", aprovados[j], notap[j]);
        }
    }

    printf("Recuperação: ");
    for(k = 0; k < rere; k++) {
        if(k < rere - 1) {
            printf(" %d (%.1f),", recuperacao[k], notar[k]);
        } else {
            printf(" %d (%.1f)\n", recuperacao[k], notar[k]);
        }
    }

    printf("Reprovados: ");
    for(l = 0; l < reprove; l++) {
        if(l < reprove - 1) {
            printf(" %d (%.1f),", reprovados[l], notaf[l]);
        } else {
            printf(" %d (%.1f)\n", reprovados[l], notaf[l]);
        }
    }

    return 0;
}