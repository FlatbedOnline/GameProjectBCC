#include <stdio.h>
#include "inimigo.h"

int main() {
    int hp, atk, pp;
    char nome[30];
    int id;

    printf("escreva o id do inimigo que deseja buscar (1 a 5 pois só tem isso): ");
    scanf("%d", &id);

    int resultado = inimigo(id, &hp, &atk, &pp, nome);

    if (resultado) {
        printf("\nInimigo encontrado\n");
        printf("Nome: %s\n", nome);
        printf("HP: %d\n", hp);
        printf("ATK: %d\n", atk);
        printf("PP: %d\n", pp);
    } else {
        printf("\n nada foi encontrado para o id %d.\n", id);
    }

    return 0;
}

