#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    int i, count = 0;
    int user_rangeL = user - distance, user_rangeR = user + distance;

    *left_index = -1;
    *right_index = -1;

    for (i = 0; i < n; i++) {
        if (cells[i] >= user_rangeL && cells[i] <= user_rangeR) {
            if (*left_index == -1) {
                *left_index = i;
            }
            *right_index = i;
            count++;
        }
    }

    return count;
}

int main() {
    int n, distance, user, i, left_index, right_index, total = 0;

    scanf("%d %d %d", &n, &distance, &user);

    int cells[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &cells[i]);
    }

    total = get_range(n, cells, distance, user, &left_index, &right_index);

    if (total == 0) {
        printf("USUARIO DESCONECTADO\n");
    } else {
        for (i = left_index; i <= right_index; i++) {
            printf("%d ", cells[i]);
        }
        printf("\n");
    }
    
    return 0;
}