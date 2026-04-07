#include <stdio.h>
#include <stdbool.h>

bool teste (int numero) {
    int i, soma = 0;

    for(i = 1; i < numero; i++) {
        if(numero % i == 0) {
            soma += i;
        }

    }
    if(soma == numero) {
        return true;
    } else {
        return false;
    }
}

int main () {
    int casos, numero, i;
    
    scanf("%d", &casos);

    for(i = 0; i < casos; i++) {
        scanf("%d", &numero);

        bool resultado = teste(numero);
    
    if(resultado == true) {
            printf("%d eh perfeito\n", numero);
        } else {
            printf("%d nao eh perfeito\n", numero);
        }
    }

    return 0;
}