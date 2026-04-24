#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void email_scan(char email[], int *arroba, int *ponto) {
    int i;
    *arroba = -1;
    *ponto = -1;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            *arroba = i;
        } 
        if (email[i] == '.' && *ponto == -1 && *arroba != -1) {
            *ponto = i;
        }
    }
}

int main() {
    char email[51];
    int arroba, ponto, i;;

    do {
        scanf("%s", email);

        if (strcmp(email, "FIM") != 0) {
            email_scan(email, &arroba, &ponto);

            for (i = arroba + 1; i < ponto; i++) {
        printf("%c", email[i]);
      }
        printf("\n");
        }

    } while (strcmp(email, "FIM") != 0);

    return 0;
}