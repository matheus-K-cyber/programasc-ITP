#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char funcionarios[51][51];
    int funcount;
} Analista;

Analista scanner() {
    Analista L;
    L.funcount = 0;
    strcpy(L.funcionarios[0], "\0");
    int flag = 0;
    char comando[10] = "";

    scanf("%d", &L.numero);

    while(flag != L.numero) {
        scanf(" %s", comando);

        if(strcmp(comando, "IMPRIMIR") == 0) {
            printf("Atualmente trabalhando:\n");

            for(int i = 0; i < L.funcount; i++) {
                printf("%s\n", L.funcionarios[i]);

                if(i == L.funcount - 1) {
                    printf("\n");
                }
            }

        }
        if(strcmp(comando, "INSERIR") == 0) {
            scanf(" %s", L.funcionarios[L.funcount]);
            L.funcount++;
        }
        if(strcmp(comando, "REMOVER") == 0) {
            char excluido[51] = "";
            scanf(" %s", excluido);
            int posicao = -1;
            
            for(int i = 0; i < L.funcount; i++) {
                if(strcmp(L.funcionarios[i], excluido) == 0) {
                    posicao = i;
                    break;
                }
            }

            if(posicao != -1) {
                for(int i = posicao; i < L.funcount - 1; i++) {
                    strcpy(L.funcionarios[i], L.funcionarios[i + 1]);
                }
                L.funcount--;
            }
        }

        flag++;
    }
}

int main() {
    scanner();

    return 0;
}