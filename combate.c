#include <stdio.h>
#include <stdlib.h>
#include "miniaudio.h"
#include "TerminalEngine.h"

#define TAM_NOME 30

typedef struct {

    char nome[TAM_NOME];
    int dano;
    int custo;
} Ataque;

Ataque ataques[4] = {
    {"Chama Flamejante", 50, 10},
    {"Golpe de Gelo", 40, 8},
    {"Raio Solar", 60, 12},
    {"Soco Rápido", 20, 4}
};


int telaAtaques(){
    int opc = menu("                      ", 1, 4, ataques->nome[0], ataques->nome[1], ataques->nome[2], ataques->nome[3]);
    return opc;
}

int telaInventario(int *inv){
    int opc = menu("                      ", 1, 2, "Pocao de Cura", "Pocao de Mana");
    return opc;
}


int combate(){
    int opc;
    int inv[2] =   {5, 5}; 
    while(1){
        opc = menu("                      ", 1, 2, "Lutar", "Inventario");
        if(opc = 1){
            telaAtaques();
        }else if(opc = 2){
            telaInventario(inv);
        }
    }
    return 1;
}
