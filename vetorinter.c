#include <stdio.h>

int intercalar(int v1[], int v2[], int v3[], int n1, int n2) {
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(v1[i] < v2[j]) {
            v3[k] = v1[i];
            i++;
        } else {
            v3[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        v3[k] = v1[i];
        i++;
        k++;
    }

    while(j < n2) {
        v3[k] = v2[j];
        j++;
        k++;
    }

    return k;
}

int main() {
    int tam1, tam2, n1, n2, n3;
    int v1[100], v2[100], v3[200];

    scanf("%d", &tam1);

    for(int i = 0; i < tam1 - 1; i++) {
        scanf("%d", &n1);
        v1[i] = n1;
        i++;
    }

    scanf("%d", &tam2);

    for(int i = 0; i < tam2 - 1; i++) {
        scanf("%d", &n2);
        v2[i] = n2;
        i++;
    }

    n3 = intercalar(v1, v2, v3, n1, n2);

    printf("Resultado: ");
    for(int i = 0; i < n3; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}