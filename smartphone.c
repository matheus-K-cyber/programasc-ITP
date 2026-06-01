#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]){
    Smartphone novo;

    scanf(" %[^\n]s", novo.modelo);
    scanf("%d", &novo.memoria);
    scanf("%f", &novo.processador);
    scanf("%f", &novo.camera);
    scanf("%f", &novo.bateria);

    phones[qnt_cadastrada] = novo;
    qnt_cadastrada++;

    return qnt_cadastrada;
}

Smartphone requisitos() {
    Smartphone reqMin;

    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    return reqMin;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin){
    int count = 0;

    for(int i = 0; i < qnt_cadastrada; i++) {
        if(phones[i].memoria >= reqMin.memoria && phones[i].processador >= reqMin.processador && phones[i].camera >= reqMin.camera && phones[i].bateria >= reqMin.bateria) {
                printf("Modelo: %s\n", phones[i].modelo);
                printf("Memória: %dGB\n", phones[i].memoria);
                printf("Processador: %.2fGHz\n", phones[i].processador);
                printf("Câmera: %.2fMPixels\n", phones[i].camera);
                printf("Bateria: %.2fmAh\n", phones[i].bateria);
                printf("\n");

                count++;
        }
    }

    return count;
}

int main() {
    Smartphone phones[100];
    int qnt_cadastrada = 0;
    char flag;

    scanf(" %c", &flag);
    while(flag == 's') {
        qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);

        scanf(" %c", &flag);
    }

    Smartphone reqMin = requisitos();

    int achados = pesquisaSmartphones(qnt_cadastrada, phones, reqMin);

    if(achados == 0) {
        printf("0 smartphones encontrados.\n");
    } else {
        printf("%d smartphones encontrados.\n", achados);
    }

    return 0;
}