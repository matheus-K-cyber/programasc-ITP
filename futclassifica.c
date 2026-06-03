#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char times[40];
    int golsM;
    int golsL;
} Time;

Time leitor(Time times[], int quantidade) {

    for(int i = 0; i < quantidade; i++) {
        scanf(" %[^\n]s", times[i].times);
        scanf("%d", &times[i].golsM);
        scanf("%d", &times[i].golsL);
    }
}

Time ordenacao(Time times[], int quantidade) {
    Time aux;

    for(int i = 0; i < quantidade - 1; i++) {
        for(int j = 0; j < quantidade - i - 1; j++) {
            if(times[j].golsM < times[j + 1].golsM) {
                aux = times[j];
                times[j] = times[j + 1];
                times[j + 1] = aux;
            }
        }
    }
}

Time impressao(Time times[], int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        printf("%d - %s\n", i + 1, times[i].times);
        printf("Gols marcados: %d\n", times[i].golsM);
        printf("Gols sofridos: %d\n", times[i].golsL);
    }
}

int main() {
    int quantidade;

    scanf("%d", &quantidade);

    Time times[quantidade];

    leitor(times, quantidade);

    ordenacao(times, quantidade);

    impressao(times, quantidade);

    return 0;
}
