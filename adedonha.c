#include <stdio.h>

int main() {
    int c1, c2, c3, c4;
    char letra;
    int soma;

    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    soma = c1 + c2 + c3 + c4;

    if(soma == 0){
        printf("Ei! Ninguém colocou nada!\n");
    } else if(soma > 0){
        letra = 'A' + (soma - 1) % 26;

        printf("Letra: %c\n", letra);
    } 

    return 0;
}