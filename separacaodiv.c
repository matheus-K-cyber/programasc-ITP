#include <stdio.h>

int main() {
    int vetorA[15] = {0}, vetorB[15] = {0}, vetorC[15] = {0}, vetorD[15] = {0};
    int tamA, tamB, tamC, tamD;
    int n, i, j, k, l;

    scanf("%d", &tamA);

    for(i = 0; i < tamA; i++) {
        scanf("%d", &n);
        vetorA[i] = n;
    }

    if(tamA == 15) {
        for(i = 0; i < tamA; i++) {
            if(vetorA[i] % 2 == 0) {
                vetorB[j] = vetorA[i];
                j++;
            } else if(vetorA[i] % 3 == 0) {
                vetorC[k] = vetorA[i];
                k++;
            } else {
                vetorD[l] = vetorA[i];
                l++;
            }
        }

    }
    

    return 0;
}