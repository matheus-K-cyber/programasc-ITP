#include <stdio.h>

int main() {
    float limite, tempo;
    int participantes = 0, series = 0;

    scanf("%f", &limite);

    scanf("%f", &tempo);

    while(tempo != -1){
        if(tempo <= limite){
            participantes++;
        }
        scanf("%f", &tempo);
    }

    series = participantes / 8;

    if (participantes % 8 != 0) {
        series++;
    }

    printf("%d %d\n", participantes, series);

    return 0;
}