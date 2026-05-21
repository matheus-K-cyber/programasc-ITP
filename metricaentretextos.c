#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void read_line(char linha[], int tam, FILE* f){
    fgets(linha, tam, f);
    while(linha[0] == '\n')
        fgets(linha, tam, f);
    if(linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1]='\0';
}

void compara(char** palavras, int tam, int *max, int *min) {
    char* palavra[tam];
    *max = strlen(palavras[0]);
    *min = strlen(palavras[1]);

    if(*min > *max) {
        int temp = *max;
        *max = *min;
        *min = temp;
    }

    for(int i = 2; i < tam; i++) {
        if(strlen(palavras[i]) > *max) {
            *max = strlen(palavras[i]);
        } else if(strlen(palavras[i]) < *min) {
            *min = strlen(palavras[i]);
        }
    }
}

float metade(char** palavras, int tam) {
    float valores = 0;

    for(int i = 0; i < tam; i++) {
        valores += strlen(palavras[i]);
    }

    return valores / tam;
}

void impressaofinal(char** palavras, int tam, int max, int min, float media) {
    float minD = 999.0;
    int alvo = 0;

    printf("Tamanho máximo: %d\n", max);
    printf("Tamanho mínimo: %d\n", min);
    printf("Tamanho médio: %.2f\n", media);

    for(int i = 0; i < tam; i++) {
        float distancia = fabs(strlen(palavras[i]) - media);

        if(distancia < minD) {
            minD = distancia;
            alvo = strlen(palavras[i]);
        }
    }

    printf("Tamanho mais próximo da média %d\n", alvo);
    printf("Textos\n");

    for(int i = 0; i < tam; i++) {
        if(strlen(palavras[i]) == alvo) {
            printf("%s\n", palavras[i]);
        }
    }
}

void freedom(char** palavras, int tam) {
    for(int i = 0; i < tam; i++) {
        free(palavras[i]);
    }
    free(palavras);
}

int main() {
    int tam;
    int max, min;

    scanf("%d", &tam);
    getchar();

    char** palavras = malloc(tam * sizeof(char*));

    for(int i = 0; i < tam; i++) {
        palavras[i] = malloc(201 * sizeof(char));
        read_line(palavras[i], 201, stdin);
    }

    compara(palavras, tam, &max, &min);

    float media = metade(palavras, tam);

    impressaofinal(palavras, tam, max, min, media);

    freedom(palavras, tam);

    return 0;
}