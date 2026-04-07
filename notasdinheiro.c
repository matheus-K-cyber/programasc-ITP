#include <stdio.h>
int main() {
    int valor;

    scanf("%d", &valor);

    if(valor >= 100){
        printf("%d nota(s) de 100\n", valor / 100);

        valor %= 100;
    }
    if(valor >= 50){
        printf("%d nota(s) de 50\n", valor / 50);

        valor %= 50;
    }
    if(valor >= 20){
        printf("%d nota(s) de 20\n", valor / 20);

        valor %= 20;
    }
    if(valor >= 10){
        printf("%d nota(s) de 10\n", valor / 10);

        valor %= 10;
    }
    if(valor >= 5){
        printf("%d nota(s) de 5\n", valor / 5);

        valor %= 5;
    }
    if(valor >= 2){
        printf("%d nota(s) de 2\n", valor / 2);
        
        valor %= 2;
    }
    if(valor >= 1){
        printf("%d moeda(s) de 1\n", valor / 1);
    }
    return 0;
}