#include <stdio.h>
#include <string.h>
#include "class.h"

ClasseInfo classes[] = {
    // id, nome, HP, ATK, PP
    {1, "Guerreiro", 125, 12, 11},  
    {2, "Mago", 85, 8, 18},         
    {3, "Bárbaro", 140, 21, 5},     
    {4, "Arqueiro", 100, 16, 14},   
    {5, "Ladrão", 100, 14, 16}       
};

// nos vetores de habilidades, o primeiro numero é a classe, basicamente é o id da classe

Habilidade habilidades[] = {
    {1, "Golpe Espada", "12 de dano", 12, 0, 0, 0, 0},
    {1, "Golpe Escudo", "15 de dano.", 18, 2, 0, 0, 1},
    {1, "Investida", "35 de dano.", 35, 4, 0, 0, 0},
    {1, "Postura Defensiva", "Bloqueia o dano inteiro de um round.", 0, 3, 0, 0, 1},

    {2, "Ataque magico", "13 de dano", 13, 0, 0, 0, 0},
    {2, "Bola de Fogo", "35 de dano.", 35, 5, 0, 0, 0},
    {2, "Raio Gélido", "20 de dano", 20, 3, 0, 0, 1},
    {2, "Cura Arcana", "Recupera 30 HP.", 0, 5, 0, 30, 0},

    {3, "Ataque Machado", "20 de dano", 20, 0, 0, 0, 0},
    {3, "Esmagada Brutal", "45 de dano.", 45, 4, 0, 0, 0},
    {3, "Lapada Seca", "25 de dano", 25, 2, 0, 0, 0},
    {3, "Fúria", "40 de dano.", 40, 3, 0, 0, 0},

    {4, "Flechada", "10 de dano", 10, 0, 0, 0, 0},
    {4, "Tiro Certeiro", "25 de dano.", 25, 3, 0, 0, 0},
    {4, "Rajada de Flechas", "3x10.", 30, 5, 0, 0, 0}, 
    {4, "Flecha Envenenada", "27 de dano.", 27, 4, 1, 0, 0}, 

    {5, "Facada", "12 de dano", 12, 0, 0, 0, 0},
    {5, "Golpe Sombrio", "25 de dano", 25, 2, 0, 0, 0},
    {5, "Apunhalada", "16 de dano.", 16, 1, 0, 1, 0},
    {5, "Passo Sombrio", "Avança e ataca duas vezes com 15 de dano cada", 30, 3, 0, 0, 0}, 

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

