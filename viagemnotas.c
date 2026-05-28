#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char alunos[51][51];
    float notas[50];
    int alunoscount;
    float media;
    char campeao[51];
    float maiornota;
} Turma;

Turma visto() {
    Turma E;
    strcpy(E.alunos[0], "\0");
    E.alunoscount = 0;
    char flag[50] = "";

    for (int i = 0; i < 50; i++) {
        E.notas[i] = 0.0;
    }

    while (strcmp(flag, ".") != 0) {
        scanf(" %s", flag);
         if (strcmp(flag, "*") == 0) {
            break;
         }
        
        strcpy(E.alunos[E.alunoscount], flag);

        scanf(" %f", &E.notas[E.alunoscount]);
        E.alunoscount++;
    }

    return E;
}

Turma media(Turma E){
    float notas = 0.0;

    for (int i = 0; i < E.alunoscount; i++) {
        notas += E.notas[i];
    }

    E.media = (E.alunoscount > 0) ? (notas / E.alunoscount) : 0.0;

    return E;
}

Turma impressao(Turma A, Turma B) {
    A.maiornota = 0.0;
    strcpy(A.campeao, "\0");
    B.maiornota = 0.0;
    strcpy(B.campeao, "\0");
    char campeaodef[51] = "";
    float maiornota = 0.0;

    for (int i = 0; i < A.alunoscount; i++) {
        if (A.notas[i] > A.maiornota) {
            A.maiornota = A.notas[i];
            strcpy(A.campeao, A.alunos[i]);
        }
    }

    for (int i = 0; i < B.alunoscount; i++) {
        if (B.notas[i] > B.maiornota) {
            B.maiornota = B.notas[i];
            strcpy(B.campeao, B.alunos[i]);
        }
    }

    if(A.maiornota > B.maiornota) {
        strcpy(campeaodef, A.campeao);
        maiornota = A.maiornota;
    } else if (B.maiornota > A.maiornota) {
        strcpy(campeaodef, B.campeao);
        maiornota = B.maiornota;
    }

    if (A.media <= 8 && B.media <= 8) {
        printf("Nenhuma das turmas viaja...\n");
    } else if(A.media > 8 && B.media > 8) {
        printf("Viagem para todos!\n");
    } else if(A.media > 8 && A.media > B.media) {
        printf("Viagem para turma A\n");
    } else if(B.media > 8 && B.media > A.media) {
        printf("Viagem para turma B\n");
    }

    if(maiornota > 8) {
        printf("%s ganhou viagem e ingresso no parque!\n", campeaodef);
        printf("Nota: %.2f\n", maiornota);
    } else {
        printf("Ninguem ganhou viagem e ingresso no parque...\n");
    }
}

int main () {
    Turma A = visto();
    Turma B = visto();

    A = media(A);
    B = media(B);

    impressao(A, B);

    return 0;
}