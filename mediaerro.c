#include <stdio.h>
#include <math.h>

int main () {
    float numero;
    float soma = 0, produto = 1, somainversa = 0;
    float mediaA, mediaG, mediaH;
    float erroh, errog, errom;
    int i;

    for(i = 0; i < 10; i++){
        scanf("%f", &numero);

        soma += numero;
        produto *= numero;
        somainversa += 1/numero;
    }

    mediaA = soma/10;
    mediaG = pow(produto, 1.0/10);
    mediaH = 10/somainversa;

    erroh = (mediaH - mediaA)/mediaA;
    errog = (mediaG - mediaA)/mediaA;
    errom = (erroh + errog)/2;
    
    printf("Média aritmética é %.2f\n", mediaA);
    printf("Média harmônica é %.2f\n", mediaH);
    printf("Média geométrica é %.2f\n", mediaG);
    printf("Erro médio é %.2f %%\n", errom * 100);
    
    return 0;
}