#include <stdio.h>
#include <stdlib.h>

float* vetordist(float *v1, int *tam, int *neotam) {
    int i, j, box = 0;
    float *neov = (float*) malloc((*tam) * sizeof(float));

    for (i = 0; i < *tam; i++) {
    int rept = 0;
       for (j = 0; j < *tam; j++) {
           if (v1[i] == v1[j]) {
               rept++;
           }
       }
       if (rept == 1) {
           neov[box] = v1[i];
           box++;
       }
    }

    *neotam = box;
    
    return neov;
}

int main() {
    int tam, neotam, i;
    float *vresul;

    scanf("%d", &tam);

    float v1[tam];

    for (i = 0; i < tam; i++) {
        scanf("%f", &v1[i]);
    }

    vresul = vetordist(v1, &tam, &neotam);

    printf("[");

    for (i = 0; i < neotam; i++) {
        if(i < neotam - 1) {
            printf("%.4f, ", vresul[i]);
        } else {
            printf("%.4f", vresul[i]);
        }
    }
    printf("]\n");
    
    free(vresul);

    return 0;
}