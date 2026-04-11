#include <stdio.h>

int main() {
    int vetorA[15] = {0}, vetorB[15] = {0}, vetorC[15] = {0}, vetorD[15] = {0};
    int tamA, tamB, tamC, tamD;
    int n, i;

    scanf("%d", &tamA);

    for(i = 0; i < tamA; i++) {
        scanf("%d", &n);
        vetorA[i] = n;
    }

    if(tamA == 15) {
        for(i = 0; i < tamA; i++) {
            if(vetorA[i] % 2 == 0) {
                vetorB[tamB] = vetorA[i];
                tamB++;
            } else if(vetorA[i] % 3 == 0) {
                vetorC[tamC] = vetorA[i];
                tamC++;
            } else {
                vetorD[tamD] = vetorA[i];
                tamD++;
            }
        }

    }
    
    printf("Vetor B: ");
    for(i = 0; i < tamB; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("\n");

    printf("Vetor C: ");
    for(i = 0; i < tamC; i++) {
        printf("%d ", vetorC[i]);
    }
    printf("\n");

    printf("Vetor D: ");
    for(i = 0; i < tamD; i++) {
        printf("%d ", vetorD[i]);
    }
    printf("\n");

    return 0;
}