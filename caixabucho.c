#include <stdio.h>

int main () {
    int combo, preco, pagamento;

    scanf("%d %d", &combo, &pagamento);

    switch (combo)
    {
    case 1: preco = 12;     break;
    case 2: preco = 23;     break;
    case 3: preco = 31;     break;
    case 4: preco = 28;     break;
    case 5: preco = 15;     break;

    default: printf("Combo inválido!\n");
        break;
    }
    
    if(pagamento < preco){
        printf("Saldo insuficiente! Falta %d reais\n", preco - pagamento);
    } else if(pagamento == preco){
        printf("Deu certim!\n");
    } else {
        printf("Troco = %d reais\n", pagamento - preco);
    }

    return 0;
}