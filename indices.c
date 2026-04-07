#include <stdio.h>

int main() {
    int anos, anos_validos = 0, i;
    float distancia_anual, soma = 0, media = 0;

    scanf("%d", &anos);

    for(i = 0; i < anos; i++){
        scanf("%f", &distancia_anual);
        
        if(distancia_anual > 0){
            soma += distancia_anual;
            anos_validos++;
        }
    }

    if(anos_validos > 0) {
    media = soma/anos_validos;

    printf("%.2f\n", media);
    } else {
        printf("A competicao nao possui dados historicos!\n");
    }

    return 0;
}