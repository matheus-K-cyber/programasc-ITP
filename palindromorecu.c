#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int analista(char *palavra, int comeco, int fim) {
    if (comeco >= fim) {
        return 1;
    } else if(palavra[comeco] != palavra[fim]){
        return 0;
    }//caso base

    return analista(palavra, comeco + 1, fim - 1);
}

int palindromo(char *entrada) {
    int tam = strlen(entrada);
    int count = 0;
    char *palavra = malloc((tam + 1) * sizeof(char));

    for(int i = 0; i < tam; i++) {
        if(entrada[i] != ' ') {
            palavra[count] = entrada[i];
            count++;
        }
    }

    palavra[count] = '\0';

    int comeco = 0, fim = strlen(palavra) - 1;

    int sinal = analista(palavra, comeco, fim);

    free(palavra);

    return sinal;
}

int main() {
    char entrada[500];

    fgets(entrada, 500, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    int flag = palindromo(entrada);

    if(flag == 1) {
        printf("O texto \"%s\" é palíndromo\n", entrada);
    } else if(flag == 0) {
        printf("O texto \"%s\" não é palíndromo", entrada);
    }

    return 0;
}