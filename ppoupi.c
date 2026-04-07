#include <stdio.h>

int main () {
    int numero, numero_original, inverso = 0;

    scanf("%d", &numero);

    numero_original = numero;

    do {
        inverso = (inverso * 10) + (numero % 10);
        numero /= 10;
    } while (numero != 0);

    if (numero_original == inverso && numero_original % 2 == 0) {
        printf("%d é Palíndromo e par.\n", numero_original);
    } else if (numero_original == inverso && numero_original % 2 != 0) {
        printf("%d é Palíndromo e ímpar.\n", numero_original);
    } else if (numero_original != inverso && numero_original % 2 == 0) {
        printf("%d não é Palíndromo e par.\n", numero_original);
    } else {
        printf("%d não é Palíndromo e ímpar.\n", numero_original);
    }

    return 0;
}