#include <stdio.h>

int main() {
    int horas, minutos;

    scanf("%d:%d", &horas, &minutos);

    if(horas >= 12 && minutos > 0){
        printf("Hora de acordar...\n");
    } else if(horas <= 12){
        printf("Cedo demais!\n");
    }

    return 0;
}