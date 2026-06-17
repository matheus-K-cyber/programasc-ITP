#include <stdio.h>

void conversor(int numero) {
    if(numero <= 0) {
        return;
    } //caso base

    conversor(numero / 2);

    printf("%d", numero % 2);
}

int main() {
    int numero;

    scanf("%d", &numero);

    if(numero == 0) {
        printf("0");
    } else {
    conversor(numero);
    }

    printf("\n");

    return 0;
}