#include <stdio.h>

int main() {
    int N, M;
    int agua = 0, hostil = 0, deserto = 0, veg = 0, dados = 0;
    int i, j;
    float pera = 0.0f, perd = 0.0f, perv = 0.0f;

    scanf("%d %d", &N, &M);

    char mapa[N][M];

    dados = N * M;

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf(" %c", &mapa[i][j]);

            if(mapa[i][j] == '~') {
                agua++;
            } else if (mapa[i][j] == 'X') {
                hostil++;
            } else if (mapa[i][j] == '^') {
                deserto++;
            } else if (mapa[i][j] == '*') {
                veg++;
            }
        }
    }

    pera = (agua * 100)/dados;
    perd = (deserto * 100)/dados;
    perv = (veg * 100)/dados;

    if(hostil > 0) {
        printf("Planeta Hostil\n");
    } else if(pera >= 50.0 && perv >= 20.0 && hostil == 0.0) {
        printf("Planeta Classe M\n");
    } else if(pera >= 85.0) {
        printf("Planeta Aquático\n");
    } else if(perd >= 60.0) {
        printf("Planeta Desértico\n");
    } else if(perv >= 65.0) {
        printf("Planeta Selvagem\n");
    } else {
        printf("Planeta Inóspito\n");
    }

    return 0;
}