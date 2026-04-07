#include <stdio.h>
int main() {
    float temperatura;
    char escala;

    scanf("%f %c", &temperatura, &escala);

    if(escala == 'C'){
        float F = temperatura * 1.8 + 32;
        float K = temperatura + 273.15;
        
        printf("Celsius: %.2f\nFahrenheit: %.2f\nKelvin: %.2f\n", temperatura, F, K);
    } else if(escala == 'F'){
        float C = (temperatura - 32)/1.8;
        float K = C + 273.15;

        printf("Celsius: %.2f\nFahrenheit: %.2f\nKelvin: %.2f\n", C, temperatura, K);
    } else if(escala == 'K'){
        float C = temperatura - 273.15;
        float F = C * 1.8 + 32;

        printf("Celsius: %.2f\nFahrenheit: %.2f\nKelvin: %.2f\n", C, F, temperatura);
    }
 
    return 0;
}