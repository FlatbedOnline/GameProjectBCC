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
    int dano;               
    int custo_pp;           
} Habilidade;

static ClasseInfo classes[] = {
    {1, "Guerreiro", 120, 20, 10},
    {2, "Mago", 80, 10, 20},
    {3, "Bárbaro", 150, 25, 6},
    {4, "Arqueiro", 100, 18, 12},
    {5, "Ladrão", 90, 16, 14}
};

const char* nomes_classes[MAX_CLASSES]; // isso armazena os nomes

const char** obter_nomes_classes() {
    for (int i = 0; i < MAX_CLASSES; i++) {
        nomes_classes[i] = classes[i].nome;
    }
    return nomes_classes;
}


// nos vetores de habilidades, o primeiro numero é a classe, basicamente é o id da classe

static Habilidade habilidades[] = {
    {1, "Golpe Escudo", "15 de dano + atordoamento.", 15, 2},
    {1, "Investida", "35 de dano.", 35, 4},
    {1, "Postura Defensiva", "Reduz o dano por 2 turnos.", 0, 3},

    {2, "Bola de Fogo", "30 de dano.", 30, 4},
    {2, "Raio Gélido", "20 de dano + reduz velocidade.", 20, 3},
    {2, "Cura Arcana", "Recupera 30 HP.", 0, 5},

    {3, "Esmagada Brutal", "50 de dano (50%% de chance de errar).", 50, 3},
    {3, "Grito Selvagem", "Aumenta ataque em 10 por 2 turnos.", 0, 2},
    {3, "Fúria", "40 de dano e se machuca em 10.", 40, 3},

    {4, "Tiro Certeiro", "25 de dano (30%% chance de crítico).", 25, 3},
    {4, "Rajada de Flechas", "3x10 de dano em um turno.", 30, 5}, 
    {4, "Flecha Envenenada", "15 de dano + envenena por 3 turnos.", 15, 4}, //dano do veneno nao fiz mas bote 2 ou 3 por turno

    {5, "Golpe Sombrio", "20 de dano + chance de esquiva aumentada.", 20, 3},
    {5, "Roubo de Vida", "15 de dano e recupera metade como HP.", 15, 4},
    {5, "Passo Sombrio", "Avança e ataca duas vezes com 15 de dano cada", 30, 5}, //se tiver animação de ataque colocar 2 lapadas neste ataque

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

