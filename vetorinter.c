#include <stdio.h>

int intercalar(int v1[], int v2[], int v3[], int tam1, int tam2) {
    int i = 0, j = 0, k = 0;

    while(i < tam1 && j < tam2) {
        v3[k] = v1[i];
        k++;
        i++;
        v3[k] = v2[j];
        k++;
        j++;
    }
    while(i < tam1 || j < tam2) {
        if(i < tam1) {
            v3[k] = v1[i];
            k++;
            i++;
        }
        if(j < tam2) {
            v3[k] = v2[j];
            k++;
            j++;
        }
    }

return k;
}

int main() {
    int tam1, tam2, n1 = 0, n2 = 0, n3 = 0;
    int v1[10] = {0}, v2[10] = {0}, v3[20] = {0};

    scanf("%d", &tam1);

    for(int i = 0; i < tam1; i++) {
        scanf("%d", &n1);
        v1[i] = n1;
    }

    scanf("%d", &tam2);

    for(int i = 0; i < tam2; i++) {
        scanf("%d", &n2);
        v2[i] = n2;
    }

    n3 = intercalar(v1, v2, v3, tam1, tam2);

    printf("Resultado: ");
    for(int i = 0; i < n3; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}