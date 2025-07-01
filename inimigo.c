#include <stdio.h>
#include <string.h>
#include "class.h"
#include "TerminalEngine.h"

//parte dos inimigos
InimigoInfo inimigos[] = {
    {1, "Goblin", 30, 7, 6},
    {2, "Esqueleto Guerreiro", 90, 15, 6},
    {3, "Slime Tóxico", 75, 10, 6},
    {4, "Espírito Sombrio", 85, 13, 10},
    {5, "Vampiro Ancestral", 200, 25, 12}
};

//parte das habilidades dos inimigos
HabilidadeInimigo habilidadesInimigos[] = {
    {1, "Golpe Basico", "10 de dano", 10, 0},
    {1, "Golpe Sangrento", "20 de dano", 20, 2},
    {1, "Golpe Investida", "20 de dano", 20, 2},

    {2, "Golpe Basico", "15 de dano", 12, 0},
    {2, "Golpe do Túmulo", "15 de dano", 15, 2},
    {2, "Ossada Giratória", "25 de dano giratório", 25, 3},

    {3, "Golpe Basico", "20 de dano", 15, 0},
    {3, "Jato Ácido", "20 de dano direto", 20, 3},
    {3, "Pancada Pegajosa", "15 de dano físico", 15, 2},

    {4, "Golpe Basico", "18 de dano", 18, 0},
    {4, "Toque Etéreo", "20 de dano", 20, 3},
    {4, "Sussurro Assombrado", "15 de dano + chance de atordoar", 15, 4},

    {5, "Golpe Basico", "20 de dano", 20, 0},
    {5, "Mordida Vampírica", "30 de dano", 30, 4},
    {5, "Aura Sangrenta", "35 de dano", 35, 5},
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
