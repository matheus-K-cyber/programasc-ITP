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
    
    printf("Vetor B: [");
    for(i = 0; i < tamB; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("]\n");

    printf("Vetor C: [");
    for(i = 0; i < tamC; i++) {
        printf("%d ", vetorC[i]);
    }
    printf("]\n");

    printf("Vetor D: [");
    for(i = 0; i < tamD; i++) {
        printf("%d ", vetorD[i]);
    }
    printf("]\n");

    return 0;
}