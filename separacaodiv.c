#include <stdio.h>

int main() {
    int vetorA[15] = {0}, vetorB[15] = {0}, vetorC[15] = {0}, vetorD[15] = {0};
    int tamB = 0, tamC = 0, tamD = 0;
    int i, n;

    for(i = 0; i < 15; i++) {
        scanf("%d", &n);

         if(n <= 0) {
            break;
         } else if(n > 0) {
            vetorA[i] = n;
         }
    }

    for(i = 0; i < 15; i++) {
            if(vetorA[i] % 2 == 0) {
                vetorB[tamB] = vetorA[i];
                tamB++;
            } 
            if(vetorA[i] % 3 == 0) {
                vetorC[tamC] = vetorA[i];
                tamC++;
            } 
            if(vetorA[i] % 2 != 0 && vetorA[i] % 3 != 0) {
                vetorD[tamD] = vetorA[i];
                tamD++;
            }
        }
    
    printf("B = [");
    for(i = 0; i < tamB; i++) {
        if(i < tamB - 1) {
            printf("%d, ", vetorB[i]);
        } else {
            printf("%d", vetorB[i]);
        }
    }
    printf("]\n");

    printf("C = [");
    for(i = 0; i < tamC; i++) {
        if(i < tamC - 1) {
            printf("%d, ", vetorC[i]);
        } else {
            printf("%d", vetorC[i]);
        }
    }
    printf("]\n");

    printf("D = [");
    for(i = 0; i < tamD; i++) {
        if(i < tamD - 1) {
            printf("%d, ", vetorD[i]);
        } else {
            printf("%d", vetorD[i]);
        }
    }
    printf("]\n");

    return 0;
}