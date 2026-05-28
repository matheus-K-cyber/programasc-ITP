#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float preco;
    int quantidade;
    int participantes;
} Churras;

float analisa(char itens[20], int flag, float total, int *participantes) {
    Churras dados;

    while(flag == 1) {
        scanf(" %s %f %d", itens, &dados.preco, &dados.quantidade);

        float valorind = dados.preco * dados.quantidade;
        total += valorind;

        scanf("%d", &flag);
    }
    scanf("%d", &dados.participantes);

    *participantes = dados.participantes;

    return total;
}


void imprime(float total, int participantes) {
    printf("Valor: R$ %.2f\n", total);
    printf("Divisão R$ %.2f para cada participante.\n", total / participantes);
}

int main() {
    float total = 0;
    char itens[20];
    int flag = 1;
    int participantes = 0;

    total = analisa(itens, flag, total, &participantes);
    imprime(total, participantes);

    return 0;
}