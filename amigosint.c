#include <stdio.h>
#include <stdbool.h>

// retorna verdadeiro se numero é divisível por divisor e falso em caso contrárioint testa_divisor(int numero, int divisor){  return 0;}       
bool  testa_divisor(int numero, int divisor) {

            if (numero % divisor == 0) {
                return true;
            } else {
                return false;
            }
        }

// retorna a soma dos divisores de value no intervalo [1,value)int soma_divisores(int value){  return 0;}
int soma_divisores(int value) {
    int i, soma = 0;
    int numero = value;

     for(i = 1; i < numero; i++) {
        if(testa_divisor(numero, i)) {
            soma += i;
        }

    }

    return soma;
}

// retorna verdadeiro se a é amigo de b e falso em caso contrárioint testa_amigos(int a, int b){  return 0;}
bool testa_amigos(int a, int b) {
    int somaA = soma_divisores(a);
    int somaB = soma_divisores(b);

    if(somaA == b && somaB == a && a != b) {
        return true;
    } else {
        return false;
    }
}

// recebe dois intervalos naturais L1 = [A,B] e L2 = [C,D]
// apresenta todos os valores em L1 que possuem ao menos um amigo em L2.int main(){  return 0;}
int main() {
    int A, B, C, D;
    int i, j;
    bool encontrou;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    for(i = A; i <= B; i++) {
        for(j = C; j <= D; j++) {
            if(testa_amigos(i, j)) {
                encontrou = true;
                printf("O %d possui um amigo!\n", i);
                break;
            } 
        }
    }
    
    if(!encontrou) {
                printf("Os intervalos nao apresentam amigos!\n");
    }
    
    return 0;
}