#include <stdio.h>
#include <stdarg.h>
#include "TerminalEngine.h"
#include <stdlib.h>
#include <time.h>
#include "class.h"
/*                                -------------AVISO----------
* QUANDO ESTIVER TESTANDO SEU CÓDIGO, NÃO ESQUEÇA DE APAGAR TUDO O QUE DEIXOU AQUI PARA TESTES.
* NÃO DE PUSH COM CÓDIGO DE TESTE AQUI. TAMBÉM NÃO DE PUSH COM OS EXECUTAVEIS, SEMPRE DE MAKE CLEAN.
*/


int main(){
srand(time(NULL));
int escolha, HP, ATK, PP;
char nome_classe[20];

printf("Bem vindo Aventureiro! \n");
printf("Escolha a classe do seu personagem \n");
printf("\n");

printf(
"=========== GUERREIRO ===========       ============= MAGO ==============\n"
"Um combatente equilibrado,              Frágil, mas com ataques poderosos\n"
"com boa vida e defesa.                 e variados.\n"
"HP:         120                         HP:         80\n"
"Ataque Base:20                         Ataque Base:10\n"
"PP:         10                         PP:         20\n\n"
"Habilidades:                            Habilidades:\n"
" - Golpe Escudo: 15 de dano             - Bola de Fogo: 30 de dano (4 PP)\n"
"   + atordoamento (2 PP)                - Raio Gélido: 20 de dano +\n"
" - Investida: 35 de dano (4 PP)           reduz velocidade (3 PP)\n"
" - Postura Defensiva:                   - Cura Arcana: Recupera 30 HP (5 PP)\n"
"   reduz dano (3 PP)\n"
"==================================     ==================================\n\n");

printf(
"=========== BÁRBARO ============        ========== ARQUEIRO ============\n"
"Muito dano e vida, mas sem              Ágil e preciso, com chance\n"
"defesa mágica.                         de crítico e longo alcance.\n"
"HP:         150                         HP:         100\n"
"Ataque Base:25                         Ataque Base:18\n"
"PP:         6                          PP:         12\n\n"
"Habilidades:                            Habilidades:\n"
" - Esmagada Brutal: 50 de dano          - Tiro Certeiro: 25 de dano\n"
"   (50%% de errar) (3 PP)                 + 30%% crítico (3 PP)\n"
" - Grito Selvagem: +10 ATK              - Rajada: 3x10 de dano (5 PP)\n"
"   por 2 turnos (2 PP)                  - Flecha Envenenada:\n"
" - Fúria: 40 de dano + -10 HP             15 de dano + veneno 3T (4 PP)\n"
"   (3 PP)\n"
"==================================     ==================================\n\n");

printf(
"============= LADRÃO ==============\n"
"\n"
"Especialista em furtividade, ataques rápidos e evasivos.\n"
"HP:         90\n"
"Ataque Base:16\n"
"PP:         14\n\n"
"Habilidades:\n"
" - Golpe Sombrio: 20 de dano + chance de esquiva (3 PP)\n"
" - Roubo de Vida: 15 de dano + recupera metade (4 PP)\n"
" - Passo Sombrio: 2x15 de dano (5 PP)\n"
"==================================\n\n");

init_audio();
escolha = menu("Escolha sua classe:", 1, 5,
               "Guerreiro", "Mago", "Barbaro", "Arqueiro", "Ladrao");

classe(escolha, &PP, &ATK, &HP, nome_classe);

printf("\n");
printf("Classe escolhida: %s\n", nome_classe);
printf("Atributos do personagem:\n");
printf("HP: %d\n", HP);
printf("ATK: %d\n", ATK);
printf("PP: %d\n", PP);

for(int i = 0; i < 5; i++){
  printf("Oponente: %s\n", inimigos[i].nome);
  if(combate(escolha-1, i) == 1){
    printf("\nVoce ganhou a batalha contra %s, pode prosseguir\n", inimigos[i].nome);
  }else{
    printf("\nPerdeu a batalha, GAME OVER\n");
    break;
  }
}
  return 0;
}


