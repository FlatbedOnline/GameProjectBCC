#include <stdio.h>
#include <string.h>
#include "class.h"

typedef struct {
    int id;
    char nome[20];
    int HP, ATK, PP;
} ClasseInfo;

typedef struct {
    int classe_id;         
    char nome[30];       
    char descricao[100];    
    int dano, custo_pp, AOT, cura; 
    float stun;         
} Habilidade;

static ClasseInfo classes[] = {
    {1, "Guerreiro", 120, 20, 10},
    {2, "Mago", 80, 10, 20},
    {3, "Bárbaro", 150, 25, 6},
    {4, "Arqueiro", 100, 18, 12},
    {5, "Ladrão", 90, 16, 14}
};

// nos vetores de habilidades, o primeiro numero é a classe, basicamente é o id da classe

static Habilidade habilidades[] = {
    {1, "Golpe Espada", "10 de dano", 10, 0, 0, 0, 0},
    {1, "Golpe Escudo", "15 de dano + atordoamento.", 15, 2, 0, 0, 1},
    {1, "Investida", "35 de dano.", 35, 4, 0, 0, 0},
    {1, "Postura Defensiva", "Bloqueia o dano inteiro de um round.", 0, 3, 0, 0, 1},

    {2, "Ataque magico", "10 de dano", 10, 0, 0, 0, 0},
    {2, "Bola de Fogo", "30 de dano.", 30, 4, 0, 0, 0},
    {2, "Raio Gélido", "20 de dano + atordoamento.", 20, 3, 0, 0, 1},
    {2, "Cura Arcana", "Recupera 30 HP.", 0, 5, 0, 30, 0},

    {3, "Ataque Machado", "10 de dano", 20, 0, 0, 0, 0},
    {3, "Esmagada Brutal", "50 de dano.", 50, 4, 0, 0, 0},
    {3, "Grito Selvagem", "Aumenta ataque em 10 por 2 turnos.", 0, 2, 0, 0, 0},
    {3, "Fúria", "40 de dano.", 40, 3, 0, 0, 0},

    {4, "Flechada", "10 de dano", 10, 0, 0, 0, 0},
    {4, "Tiro Certeiro", "25 de dano.", 25, 3, 0, 0, 0},
    {4, "Rajada de Flechas", "3x10 de dano em um turno.", 30, 5, 0, 0, 0}, 
    {4, "Flecha Envenenada", "15 de dano + envenena por 3 turnos.", 15, 4, 1, 0, 0}, //dano do veneno nao fiz mas bote 2 ou 3 por turno

    {5, "Facada", "10 de dano", 10, 0, 0, 0, 0},
    {5, "Golpe Sombrio", "20 de dano", 20, 3, 0, 0, 0},
    {5, "Roubo de Vida", "16 de dano e recupera metade como HP.", 15, 4, 0, 1, 0},
    {5, "Passo Sombrio", "Avança e ataca duas vezes com 15 de dano cada", 30, 5, 0, 0, 0}, //se tiver animação de ataque colocar 2 lapadas neste ataque

};


int classe(int escolha, int *PP, int *ATK, int *HP, char *nome_classe){
    int n = sizeof(classes)/sizeof(classes[0]);
    for (int i = 0; i < n; i++) {
        if (classes[i].id == escolha) {
            strcpy(nome_classe, classes[i].nome);
            *HP = classes[i].HP;
            *ATK = classes[i].ATK;
            *PP = classes[i].PP;
            return 1;
        }
    }
  
    strcpy(nome_classe, "Desconhecido");
    *HP = *ATK = *PP = 0;
    return 0; 

}

