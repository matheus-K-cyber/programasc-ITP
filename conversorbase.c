#include <stdio.h>

int conversorbase(int value, int base) {
    int result = 0, mul = 1;

    int temp = value;
    
    while(temp > 0){
        result += (temp % base) * mul;
        mul = mul * 10;
        temp = temp / base;
        }

    return result;
}

int main() {

  int value, base, result = 0, mul = 1;

    do {
    scanf("%d", &value);
    if (value == -1) {
        printf("Programa encerrado!\n");
        return 0;
    }
    scanf("%d", &base);

    result = conversorbase(value, base);

    printf("Numero %d(10) na base %d = %d(%d)\n", value, base, result, base);
    } while (value != -1);
  
  return 0;
}