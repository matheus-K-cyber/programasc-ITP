#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char name[500], int age, char gen) {
    Pessoa p;
    p.idade = age;
    p.sexo = gen;

    p.nome = malloc((strlen(name) + 1) * sizeof(char));

    if(p.nome == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nome.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(p.nome, name);

    return p;

}

Pessoa* inserir(Pessoa* identidade, Pessoa people, int countp) {
    Pessoa* temp = realloc(identidade, (countp + 1) * sizeof(Pessoa));

    if(temp == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a identidade.\n");
        exit(EXIT_FAILURE);
    }

    identidade = temp;
    identidade[countp] = people;

    return temp;
}

int delete(Pessoa* identidade, Pessoa people, int countp) {
    for(int i = 0; i < countp; i++) {
        if(strcmp(identidade[i].nome, people.nome) == 0 && identidade[i].idade == people.idade && identidade[i].sexo == people.sexo) {
            free(identidade[i].nome);
            for(int j = i; j < countp - 1; j++) {
                identidade[j] = identidade[j + 1];
            }
            countp--;
            break;
        }
    }

    return countp;
}

void impressao(Pessoa* identidade, int countp) {
    for(int i = 0; i < countp; i++) {
        printf("%s,%d,%c\n", identidade[i].nome, identidade[i].idade, identidade[i].sexo);
    }
}

void freedom(Pessoa* identidade, int countp) {
    for(int i = 0; i < countp; i++) {
        free(identidade[i].nome);
    }
    free(identidade);
}

int main() {
    Pessoa* identidade = NULL;
    Pessoa people;
    char name[500];
    int age, countp = 0;
    char gen;
    char comando;

    while(1) {
        scanf(" %c", &comando);

        if(comando == 'p') {
            break;
        }

        if(comando == 'i') {
            getchar();

            fgets(name, 500, stdin);
            name[strcspn(name, "\n")] = '\0';

            scanf("%d", &age);
            scanf(" %c", &gen);

            people = criar(name, age, gen);
            identidade = inserir(identidade, people, countp);
            countp++;
        } else if(comando == 'd') {
            getchar();

            fgets(name, 500, stdin);
            name[strcspn(name, "\n")] = '\0';

            scanf("%d", &age);
            scanf(" %c", &gen);

            Pessoa delet;
            delet.nome = name;
            delet.idade = age;
            delet.sexo = gen;

            countp = delete(identidade, delet, countp);
        }
    }

    impressao(identidade, countp);

    freedom(identidade, countp);

    return 0;
}