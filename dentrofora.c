#include <stdio.h>
int main() {
    int x_esq, y_sup;
    int x_dir, y_inf;
    int ponto_x, ponto_y;

    scanf("%d %d", &x_esq, &y_sup);
    scanf("%d %d", &x_dir, &y_inf);
    scanf("%d %d", &ponto_x, &ponto_y);

    if(ponto_x >= x_esq && ponto_x <= x_dir && ponto_y >= y_sup && ponto_y <= y_inf){
        printf("Dentro!\n");
    } 
    else{
        printf("Fora!\n");
    }
    
    return 0;
}