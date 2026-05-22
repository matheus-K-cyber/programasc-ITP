#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scant(char* fonte, int tam){
    fgets(fonte, tam, stdin);
    fonte[strcspn(fonte, "\n")] = '\0';
}

void scanp(char* padrao, int tam){
    fgets(padrao, tam, stdin);
    padrao[strcspn(padrao, "\n")] = '\0';
}

void resultado(char* fonte, char* padrao, int tam) {
    int save = 0, coincidencia = 0;
    int lenf = strlen(fonte);
    int lenp = strlen(padrao);
    char* analisada = malloc(51 * sizeof(char));
    char* alvo = malloc(51 * sizeof(char));

     strcpy(analisada, fonte);
     strcpy(alvo, padrao);

    for(int i = 0; i < (lenf - lenp + 1); i++) {
        save = i;

        for(int j = 0; j < lenp; j++) {
            printf("%c ", analisada[i + j]);

            if(analisada[i + j] != alvo[j]) {
                save = 0;
                printf("não\n");

                coincidencia = 0;
                for(int k = 0; k < lenp; k++) {
                    if(analisada[i + j] == alvo[k]) {
                        coincidencia = 1;
                        break;
                    }
                }
                if(coincidencia == 0) {
                    i += j;
                }

                break;
            }

            if(save == i && j == lenp - 1) {
                printf("sim\n");
                printf("Achei o padrão no índice %d\n", save);
                return;
            }
        }
    }
    printf("Não achei o padrão\n");
}

void freedom(char* fonte, char* padrao) {
    free(fonte);
    free(padrao);
}

int main() {
    char* fonte = malloc(51 * sizeof(char));
    char* padrao = malloc(51 * sizeof(char));

    scant(fonte, 51);
    scanp(padrao, 51);

    resultado(fonte, padrao, 51);

    freedom(fonte, padrao);

    return 0;
}