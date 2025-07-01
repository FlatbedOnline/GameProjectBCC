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
    int opc, atk = 0, item;
    int hpPlayer = classes[escolha].HP;
    int hpInimigo = inimigos[inimigo].HP;
    int ppPlayer = classes[escolha].PP;
    
    int inv[2] = {5, 5}; 
    int itensDisponiveis[2] = {0, 1}; // IDs dos itens possíveis

    while(1){
        printf("\33[2K\rVida Player: %d - PP: %d | Vida Inimigo: %d\n", hpPlayer, ppPlayer, hpInimigo);
        opc = menu("                      ", 1, 2, "Lutar", "Inventario"); // menu

        if(opc == 1){ // opc de escolhas do menu
            atk = telaAtaques(escolha);
            if(ppPlayer >= habilidades[(atk-1)+(4*escolha)].custo_pp){
                hpInimigo -= habilidades[(atk-1)+(4*escolha)].dano; // dano no inimigo
                ppPlayer -= habilidades[(atk-1)+(4*escolha)].custo_pp; // reducao de pp
            }
            if (hpInimigo < 0) hpInimigo = 0; // vida minima do inimigo
        } else if(opc == 2){
            item = telaInventario(inv); // inventario
            int indiceItem = buscaLinear(itensDisponiveis, 2, item); // busca linear aplicada aqui

            if(indiceItem == 0 && inv[0] > 0){ 
                hpPlayer += 50; // VIDA DA POCAO PARA O PLAYER
                inv[0] -= 1;
            } else if(indiceItem == 1 && inv[1] > 0){
                ppPlayer += 5; // PP DA POCAO
                if (ppPlayer > classes[escolha].PP) ppPlayer = classes[escolha].PP; // PP DA POCAO PARA O PLAYER
                inv[1] -= 1;
            } 
        }

        if(hpPlayer < 0) hpPlayer = 0; // Vida minima
        if(ppPlayer < 0) ppPlayer = 0; // PP minima

        if(habilidades[(atk-1)+(4*escolha)].cura != 0) hpPlayer += habilidades[(atk-1)+(4*escolha)].cura; // Cura das Habilidades

        if (hpPlayer > classes[escolha].HP) hpPlayer = classes[escolha].HP; // Limitador de vida na cura

        if(habilidades[(atk-1)+(4*escolha)].stun != 1){ // Stun
            hpPlayer -= habilidadesInimigos[aleatorio(3)+(3*inimigo)].dano; //Dano do inimigo
        }

        if(hpPlayer <= 0){ // verificacao de derrota
            return 0;
            break;
        } else if(hpInimigo == 0){ // verificacao de vitoria
            return 1;
            break;
        }   
    }
}