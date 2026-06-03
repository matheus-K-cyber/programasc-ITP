#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char name[51], int age, char gen) {
    Pessoa p;
    strncpy(p.nome, name, 51);
    p.idade = age;
    p.sexo = gen;
    return p;

}

int inserir(Pessoa identidade[51], Pessoa people, int countp) {
    identidade[countp] = people;

    countp++;

    return countp;
}

int delete(Pessoa identidade[51], Pessoa people, int countp) {
    for(int i = 0; i < countp; i++) {
        if(strcmp(identidade[i].nome, people.nome) == 0 && identidade[i].idade == people.idade && identidade[i].sexo == people.sexo) {
            for(int j = i; j < countp - 1; j++) {
                identidade[j] = identidade[j + 1];
            }
            countp--;
            break;
        }
    }

    return countp;
}

Pessoa impressao(Pessoa identidade[51], int countp) {
    for(int i = 0; i < countp; i++) {
        printf("%s, %d, %c\n", identidade[i].nome, identidade[i].idade, identidade[i].sexo);
    }
}

int main() {
    Pessoa people;
    Pessoa identidade[51];
    char name[51];
    int age, countp = 0;
    char gen;
    char comando;

    while(comando != 'p') {
        scanf(" %c", &comando);
        getchar();

        if(comando == 'i') {
            fgets(name, 51, stdin);
            name[strcspn(name, "\n")] = '\0';
            scanf("%d", &age);
            scanf(" %c", &gen);

            people = criar(name, age, gen);
            countp = inserir(identidade, people, countp);
        } else if(comando == 'd') {
            fgets(name, 51, stdin);
            name[strcspn(name, "\n")] = '\0';
            scanf("%d", &age);
            scanf(" %c", &gen);

            people = criar(name, age, gen);
            countp = delete(identidade, people, countp);
        }
    }

    impressao(identidade, countp);

    return 0;
}