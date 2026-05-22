#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanp(char** prefixos, int pre) {
    for(int i = 0; i < pre; i++) {
        prefixos[i] = malloc(15 * sizeof(char));
        fgets(prefixos[i], 15, stdin);
        prefixos[i][strcspn(prefixos[i], "\n")] = '\0';
    }
}

void scans(char** sufixos, int sufi) {
    for(int i = 0; i < sufi; i++) {
        sufixos[i] = malloc(15 * sizeof(char));
        fgets(sufixos[i], 15, stdin);
        sufixos[i][strcspn(sufixos[i], "\n")] = '\0';
    }
}

char** scaninf(int *qa) {
    int k = 20;
    int count = 0;
    char** ptemp = malloc(k * sizeof(char*));

    while(1) {
        ptemp[count] = malloc(101 * sizeof(char));
        fgets(ptemp[count], 101, stdin);
        ptemp[count][strcspn(ptemp[count], "\n")] = '\0';
        count++;

        if(strcmp(ptemp[count-1], "-1") == 0) {
            free(ptemp[count-1]);
            break;
        }

        if(count >= k) {
            k *= 2;
            ptemp = realloc(ptemp, k * sizeof(char*));
        }
    }
    *qa = count - 1;

    return ptemp;
}

char** erasingpresufi(char** palavras, int qa, char** prefixos, char** sufixos, int pre, int sufi) {
    char** conclusao = malloc(qa * sizeof(char*));

    for(int i = 0; i < qa; i++) {
        conclusao[i] = malloc(101 * sizeof(char));
        strcpy(conclusao[i], palavras[i]);

        for(int j = 0; j < pre; j++) {
            if(strncmp(conclusao[i], prefixos[j], strlen(prefixos[j])) == 0) {
                memmove(conclusao[i], conclusao[i] + strlen(prefixos[j]), strlen(conclusao[i]) - strlen(prefixos[j]) + 1);
                break;
            }
        }

        for(int k = 0; k < sufi; k++) {
            int len = strlen(conclusao[i]);
            int suflen = strlen(sufixos[k]);

            if(len >= suflen && strcmp(conclusao[i] + len - suflen, sufixos[k]) == 0) {
                conclusao[i][len - suflen] = '\0';
                break;
            }
        }
    }

    return conclusao;
}

void impressao(char** analista, int qa) {
    for(int i = 0; i < qa; i++) {
        if(strlen(analista[i]) > 0) {
            printf("%s\n", analista[i]);
        }
    }
}

void freedom(char** palavras, char** prefixos, char** sufixos, char** analista, int qa, int pre, int sufi) {
    for(int i = 0; i < qa; i++) {
        free(palavras[i]);
        free(analista[i]);
    }
    free(palavras);
    free(analista);

    for(int j = 0; j < pre; j++) {
        free(prefixos[j]);
    }
    free(prefixos);

    for(int k = 0; k < sufi; k++) {
        free(sufixos[k]);
    }
    free(sufixos);
}

int main() {
    int sufi;
    int pre;
    int qa = 0;
    
    scanf("%d", &pre);
    getchar();

    char** prefixos = malloc(pre * sizeof(char*));

    if(pre >=0) {
    scanp(prefixos, pre);
}

    scanf("%d", &sufi);
    getchar();

    char** sufixos = malloc(sufi * sizeof(char*));


    if(sufi >=0) {
    scans(sufixos, sufi);
}

    char** palavras = scaninf(&qa);

    char** analista = erasingpresufi(palavras, qa, prefixos, sufixos, pre, sufi);

    impressao(analista, qa);

    freedom(palavras, prefixos, sufixos, analista, qa, pre, sufi);

    return 0;
}