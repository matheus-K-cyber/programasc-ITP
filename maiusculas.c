#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convert(char *frase) {
    char *convert = malloc(61 * sizeof(char));
    int i = 0, j = 0;

    while (frase[i] != '\0') {
        if(i == 0 || frase[i - 1] == ' ') {
            convert[j] = toupper(frase[i]);
        } else {
            convert[j] = tolower(frase[i]);
        }

        i++;
        j++;
    }

    convert[j] = '\0';

    return convert;
}

void impressao(char *convertidas) {
    while(*convertidas != '\0') {
        printf("%c", *convertidas);
        convertidas++;
    }
}

void liberar(char *frase, char *convertidas) {
    free(frase);
    free(convertidas);
}

int main() {
    char *frase = malloc(61 * sizeof(char));
    
    fgets(frase, 61, stdin);

    char *convertidas = convert(frase);

    impressao(convertidas);

    liberar(frase, convertidas);

    return 0;
}