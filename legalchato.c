#include <stdio.h>
#include <stdbool.h>

bool legalchato(int vetor[100], int n) {
    for(int i = 0; i < n - 1; i++) {
        if( (vetor[i] - vetor[i + 1]) % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }

}

int main() {
    int vetor[100] = {0};
    int n, valor, numeros;
    int i;

    scanf("%d", &n);

    for(i = 1; i < n; i++) {
        scanf("%d", &valor);
        vetor[numeros] = valor;
        numeros++;

    }

    if(legalchato(vetor, n)) {
        printf("Legal");
    } else {
        printf("Chato");
    }

    return 0;
}