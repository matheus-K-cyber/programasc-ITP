#include <stdio.h>

void ordem(int *n1, int *n2) {
    int box;
    if (*n1 < *n2) {
        box = *n1;
        *n1 = *n2;
        *n2 = box;
    }
}

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    ordem(&num1, &num2);

    printf("%d\n%d\n", num1, num2);

    return 0;
}