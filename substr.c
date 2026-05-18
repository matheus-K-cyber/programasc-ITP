#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void igualdade(char *strA, char *strB) {
    int i = 0;

    while(strA[i] != '\0') {
        strA[i] = tolower(strA[i]);
        i++;
    }

    i = 0;
    while(strB[i] != '\0') {
        strB[i] = tolower(strB[i]);
        i++;
    }
}

int substranalise(char *strA, char *strB, int *posicoes) {
    int total = 0;
    int lenA = strlen(strA);
    int lenB = strlen(strB);

    for (int i = 0; i <= lenB - lenA; i++) {
        if (strncmp(&strB[i], strA, lenA) == 0) {
            posicoes[total] = i;
            total++;
        }
    }

    return total;
}

void imprimir(int total, int *posicoes) {
    printf("Repetições: %d\n", total);

    if(total > 0) {
    printf("Posições: ");
    for(int i = 0; i < total; i++) {
        printf("%d ", posicoes[i]);

        if(i == total - 1) {
            printf("\n");
        }
    }
    }
    
}

void freedom(char *strA, char *strB, int *posicoes) {
    free(strA);
    free(strB);
    free(posicoes);
}

int main() {
    char *strA = malloc(40 * sizeof(char));
    char *strB = malloc(40 * sizeof(char));
    int *posicoes = malloc(40 * sizeof(int));

    fgets(strA, 40, stdin);
    strA[strcspn(strA, "\n")] = '\0';

    fgets(strB, 40, stdin);
    strB[strcspn(strB, "\n")] = '\0';

    igualdade(strA, strB);

    int total = substranalise(strA, strB, posicoes);

    imprimir(total, posicoes);

    freedom(strA, strB, posicoes);

    return 0;
}