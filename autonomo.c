#include <stdio.h>

int main() {
    int C, C1, C2;

    scanf("%d %d %d", &C, &C1, &C2);

    if(C == (C1 + C2)/2 || C > C1 && C > C2 || C < C1 && C < C2){
        printf("C\n");
    } else if((C - C1) < (C - C2)){
        printf("A\n");
    } else if((C - C1) > (C - C2)){
        printf("F\n");
    }
    return 0;
}