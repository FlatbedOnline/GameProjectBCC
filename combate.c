#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniaudio.h"
#include "TerminalEngine.h"
#include "class.h"

int telaAtaques(int escolha){
    int opc;
    opc = menu("                      ", 1, 4,
        habilidades[0+(4*(escolha))].nome,
        habilidades[1+(4*(escolha))].nome,
        habilidades[2+(4*(escolha))].nome,
        habilidades[3+(4*(escolha))].nome);
    return opc;
}

int telaInventario(int *inv){
    int opc = menu("                      ", 1, 2, "Pocao de Cura", "Pocao de Mana");
    return opc;
}
int turnoinimigo(){

}


int combate(int escolha){
    //status do jogador, e inimigo; 
    int opc, atk;

    int inv[2] = {5, 5}; 
    while(1){
        printf("\r");
        opc = menu("                      ", 1, 2, "Lutar", "Inventario");
        if(opc = 1){
            atk = telaAtaques(escolha);

        }else if(opc = 2){
            telaInventario(inv);
        }
    }
    return 1;
}
