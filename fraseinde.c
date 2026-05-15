#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(int n, char str[]){
    int count = 0;
    while(count < n && str[count] != '\0'){
        count = count + 1;
    } 
    return count;
}

void exibir(char frase []){
    int value = (frase[0] - '0') * 100 + (frase[1] - '0') * 10 + (frase[2] - '0');
    int tam = tamanho(value, frase);
    if(value >= 0 && tam == value && frase[value] == '\0'){
        printf("%d == %d OK!", tam, value);
    } else {
        printf("Resultado inesperado! Um \\n talvez?");
    }
}

int main() {
    char rascunho[16];
    char *frase = malloc(1);
    frase[0] = '\0';
    int tamT = 0;
    
    while(fgets(rascunho, 16, stdin)) {
        int read = strlen(rascunho);
        tamT += read;

        char *bau = realloc(frase, tamT + 1);
        if (bau == NULL) {
            free(frase);
        } else {
            frase = bau;
        }
        strcat(frase, rascunho);

        if(rascunho[read - 1] == '\n') {
            break;
        }
    }
    
    if (tamT > 0 && frase[tamT - 1] == '\n') {
        frase[tamT - 1] = '\0';
    }

    exibir(frase);

    free(frase);
    return 0;
}