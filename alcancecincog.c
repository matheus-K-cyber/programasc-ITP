#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    int i;
    int user_rangeL = user - distance, user_rangeR = user + distance;

    *left_index = -1;
    *right_index = -1;

    for (i = 0; i < n; i++) {
        if (cells[i] >= user_rangeL) {
            if (*left_index == -1) {
                *left_index = i;
            }
        } else if (cells[i] <= user_rangeR) {
            if (*right_index == -1) {
                *right_index = i;
            }
        } else {
            break;
        }
    }

    

    return 0;
}

int main() {
    int n, distance, user, i, left_index, right_index;

    scanf("%d %d %d", &n, &distance, &user);

    int cells[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &cells[i]);
    }

    get_range(n, cells, distance, user, &left_index, &right_index);
    
    return 0;
}