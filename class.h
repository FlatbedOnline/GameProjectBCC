#ifndef CLASS_H
#define CLASS_H

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

extern ClasseInfo classes[];
extern Habilidade habilidades[];

extern InimigoInfo inimigos[];
extern HabilidadeInimigo habilidadesInimigos[];

int classe(int escolha, int *PP, int *ATK, int *HP, char *nome_classe);
int inimigo(int id, int *HP, int *ATK, int *PP, char *nome_inimigo);
#endif

