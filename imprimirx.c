#include <stdio.h>

int main() {
    int quantidade, i, j;
    char c;

    scanf("%d %c", &quantidade, &c);

    for(i = 0; i < quantidade - 1; i++){

        for(j = 0; j < quantidade - 1; j++){
            if(i == j || i + j == quantidade - 2){
                printf("%c", c);
            } else if(i != j){
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}