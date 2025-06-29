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
    return opc - 1;
}

int combate(int escolha, int inimigo){
    //status do jogador, e inimigo; 
    int opc, atk, item;
    int hpPlayer = classes[escolha].HP;
    int hpInimigo = inimigos[inimigo].HP;
    int ppPlayer = classes[escolha].PP;
    
    int inv[2] = {5, 5}; 
    while(1){
        printf("\33[2K\rVida Player: %d - PP: %d | Vida Inimigo: %d\n", hpPlayer, ppPlayer, hpInimigo);
        opc = menu("                      ", 1, 2, "Lutar", "Inventario");
        if(opc == 1){
            atk = telaAtaques(escolha);
            hpInimigo -= habilidades[(atk-1)+(4*escolha)].dano;
            ppPlayer -= habilidades[(atk-1)+(4*escolha)].custo_pp;
            if (hpInimigo < 0) hpInimigo = 0;
        }else if(opc == 2){
            item = telaInventario(inv);
            if(item == 0){
                hpPlayer += 50;
                if (hpPlayer > classes[escolha].HP) hpPlayer = classes[escolha].HP;
                inv[0] -= 1;
            }else if(item == 1){
                ppPlayer += 5;
                if (ppPlayer > classes[escolha].PP) ppPlayer = classes[escolha].PP;
                inv[1] -= 1;
            }
        }
        hpPlayer -= habilidadesInimigos[aleatorio(3)+(3*inimigo)].dano;
        
        if(hpPlayer == 0){
            return 0;
            break;
        }else if(hpInimigo == 0){
            return 1;
            break;
        }   
    }
}
