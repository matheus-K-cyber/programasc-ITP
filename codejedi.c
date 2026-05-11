#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char** separa(char *str, int *quantidadeTextos) { 
    char **textoSeparado = (char**) malloc(501 * sizeof(char*));
    char *texto = strtok(str," ");
    int cont = 0;
    
    while(texto != NULL) {
        
        textoSeparado[cont] = texto;
        cont ++;
        texto = strtok(NULL," ");
     }
        *quantidadeTextos = cont;

        return textoSeparado;
    }

char* juntar(char **vetor_strings, int tamanho_vetor) {
    int tamanho_final = 0;

    for(int i = 0; i < tamanho_vetor; i++) {
        tamanho_final += strlen(vetor_strings[i]) + 1; 
    }

    char *strings_unidas = (char*) malloc(tamanho_final * sizeof(char));

    strings_unidas[0] = '\0';
 
    for(int i = 0; i < tamanho_vetor; i++) {
        strcat(strings_unidas,vetor_strings[i]);

        if(i < tamanho_vetor - 1) {
            strcat(strings_unidas," ");
        }
    }

    return strings_unidas;
}

int main() {
    srand(5940);

    char T[501];
    int N = 501, k = 0, descobertas = 0;
    char **E = (char**) malloc(501 * sizeof(char*));
    int *check = calloc(N, sizeof(int));

    fgets(T, 501, stdin);
    T[strcspn(T, "\n")] = '\0';

    char** M = separa(T, &N);

    while(descobertas < N) {
        int n = rand() % N;

        if(k >= 501) {
            E = realloc(E, (k + 100) * sizeof(char*));
        }

        E[k] = M[n];

        if(check[n] == 0) {
            check[n] = 1;
            descobertas++;
        }

        k++;
    }
   
    char *R = juntar(E, k);

    printf("%s\n", R);

    free(E);
    free(check);
    free(R);
    free(M);
    return 0;
}