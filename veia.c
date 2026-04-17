#include <stdio.h>

int main() {
    char veia[4][4];
    char simb;
    int jx = 0, jo = 0, space = 0, x, y;
    int jogadas, i, j, k;

    for(i = 1; i <= 3; i++) {
        for(j =1; j<= 3; j++) {
            scanf(" %c", &veia[i][j]);

            if(veia[i][j] == 'X') {
                jx++;
            } else if(veia[i][j] == 'O') {
                jo++;
            } else if(veia[i][j] == '.') {
                space++;
            }
        }
    }

    scanf("%d", &jogadas);

    for(k = 0; k < jogadas; k++){
            scanf("%d %d %c", &x, &y, &simb);

            if(veia[x][y] != '.') {
                printf("Jogada inválida!\n");
            } else {
                veia[x][y] = simb;

                if (veia[x][1] == simb && veia[x][2] == simb && veia [x][3] == simb
                    || veia[1][y] == simb && veia[2][y] == simb && veia[3][y] == simb
                    || veia[1][1] == simb && veia[2][2] == simb && veia[3][3] == simb
                    || veia[1][3] == simb && veia[2][2] == simb && veia[3][1] == simb) {
                    printf("Boa jogada, vai vencer!\n");
                } else {
                    printf("Continua o jogo.\n");
                }
                veia[x][y] = '.';
            }
        }

    return 0;
}