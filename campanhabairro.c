#include <stdio.h>
#include <stdlib.h>

void compute_votes(int n, int total[], int *bgv, int *littlev) {
    int vencedor = -1, vice = -1, i;
    int placar[11] = {0};

    for (i = 0; i < n; i++) {
            int votol = total[i];
            placar[votol]++;
    }

    for (i = 1; i <= 10; i++) {
        if (placar[i] > vencedor) {
            vice = vencedor;
            *littlev = *bgv;
            vencedor = placar[i];
            *bgv = i;
        } else if (placar[i] > vice) {
            vice = placar[i];
            *littlev = i;
        }
    }
}

int main() {
    int votos, bgv = 0, littlev = 0, i;
    int *total;

    scanf("%d", &votos);
    total = (int*) malloc(votos * sizeof(int));

    for (i = 0; i < votos; i++) {
        scanf("%d", &total[i]);
    }

    compute_votes(votos, total, &bgv, &littlev);

    printf("%d %d\n", bgv, littlev);

    free(total);
    return 0;
}