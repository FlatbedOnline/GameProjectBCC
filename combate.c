#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniaudio.h"
#include "TerminalEngine.h"

int telaAtaques(int escolha){
    int opc;
    opc = menu("                      ", 1, 4, habilidades->nome[0+(4*(escolha-1))], habilidades->nome[1+(4*(escolha-1))], habilidades->nome[2+(4*(escolha-1))], habilidades->nome[3+(4*(escolha-1))]);
    return opc;
}

int telaInventario(int *inv){
    int opc = menu("                      ", 1, 2, "Pocao de Cura", "Pocao de Mana");
    return opc;
}


int combate(int escolha){
    //status do jogador, e inimigo; 
    int opc, atk;
    int inv[2] = {5, 5}; 
    while(1){
        opc = menu("                      ", 1, 2, "Lutar", "Inventario");
        if(opc = 1){
            atk = telaAtaques(escolha);

        }else if(opc = 2){
            telaInventario(inv);
        }
    }
    return 1;
}
