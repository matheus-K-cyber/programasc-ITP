#include <stdio.h>

int main() {
    int quantidade, total = 0;
    float valor, orcamento = 0;

    while(quantidade != -1){

        scanf("%d", &quantidade);

        if(quantidade < 0){
            break;
        } else {scanf("%f", &valor);
        }
        
        total += quantidade;
        orcamento += (valor * quantidade);
        
    }

    printf("%d %.2f\n", total, orcamento);

    return 0;
}