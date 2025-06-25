#include <stdio.h>
#include <string.h>
#include "inimigo.h"

typedef struct {
    int id;
    char nome[30];
    int HP;
    int ATK;
    int PP;
} InimigoInfo;

typedef struct {
    int inimigo_id;
    char nome[30];
    char descricao[100];
    int dano;
    int custo_pp;
} HabilidadeInimigo;

//parte dos inimigos
static InimigoInfo inimigos[] = {
    {1, "Goblin", 30, 7, 6},
    {2, "Esqueleto Guerreiro", 90, 15, 6},
    {3, "Slime Tóxico", 75, 10, 6},
    {4, "Espírito Sombrio", 85, 13, 10},
    {5, "Vampiro Ancestral", 200, 25, 12}
};

//parte das habilidades dos inimigos
static HabilidadeInimigo habilidadesInimigos[] = {
    {1, "Golpe Sangrento", "10 de dano + sangramento por 2 turnos", 10, 2},
    {1, "Golpe Investida", "20 de dano, 50% de chance de cair", 20, 2},

    {2, "Golpe do Túmulo", "15 de dano", 15, 2},
    {2, "Ossada Giratória", "25 de dano giratório", 25, 3},

    {3, "Jato Ácido", "20 de dano direto", 20, 3},
    {3, "Pancada Pegajosa", "15 de dano físico", 15, 2},

    {4, "Toque Etéreo", "20 de dano", 20, 3},
    {4, "Sussurro Assombrado", "15 de dano + chance de atordoar", 15, 4},

    {5, "Mordida Vampírica", "30 de dano e cura 10 HP", 30, 4},
    {5, "Aura Sangrenta", "20 de dano + reduz precisão", 20, 5},
    {5, "Olhar Hipnótico", "Impede o jogador de atacar 1 turno", 0, 6}
};

//parte para  receber os dados por id
int inimigo(int id, int *HP, int *ATK, int *PP, char *nome_inimigo) {
    int n = sizeof(inimigos) / sizeof(inimigos[0]);
    for (int i = 0; i < n; i++) {
        if (inimigos[i].id == id) {
            strcpy(nome_inimigo, inimigos[i].nome);
            *HP = inimigos[i].HP;
            *ATK = inimigos[i].ATK;
            *PP = inimigos[i].PP;
            return 1;
        }
    }

    strcpy(nome_inimigo, "Desconhecido");
    *HP = *ATK = *PP = 0;
    return 0;
}
