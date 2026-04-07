#include <stdio.h>

int main() {
    int N, i, vencedor;
    float nota1, nota2, nota3, media, maiornota = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%f %f %f", &nota1, &nota2, &nota3);

        media = (nota1 + nota2 + nota3) / 3;

        if(media >= maiornota){
            maiornota = media;
            vencedor = i + 1;
        }
    }

    printf("Vencedor: %d\n", vencedor);
    printf("Nota: %.2f\n", maiornota);

    return 0;
}