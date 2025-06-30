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
"=========== GUERREIRO ===========   ============= MAGO =============   ============ BÁRBARO ============\n"
"Um combatente equilibrado,          Frágil, ataques poderosos          Muito dano, pouca defesa mágica\n"
"com boa vida e defesa.              e variados.                        e muita vida.\n"
"HP:         120                     HP:         80                     HP:         150\n"
"ATK Base:   20                      ATK Base:   10                     ATK Base:   25\n"
"PP:         10                      PP:         20                     PP:         6\n\n"
"Habilidades:                        Habilidades:                       Habilidades:\n"
"- Golpe Escudo (2PP): 15 dano       - Bola de Fogo (4PP): 30 dano      - Esmagada Brutal (3PP): 50 dano\n"
"- Investida (4PP): 35 dano          - Raio Gélido (3PP): 20 dano       - Grito Selvagem (2PP): +10 ATK\n"
"- Postura Defensiva (3PP): defesa   - Cura Arcana (5PP): +30 HP        - Fúria (3PP): 40 dano, -10 HP\n"
"==========================================================================================================\n\n");

printf(
"=========== ARQUEIRO ============   ============ LADRÃO =============   \n"
"Ágil, preciso, crítico à distância  Furtivo, ataques duplos, evasivo   \n"
"HP:         100                     HP:         90                      \n"
"ATK Base:   18                      ATK Base:   16                      \n"
"PP:         12                      PP:         14                      \n\n"
"Habilidades:                        Habilidades:                        \n"
"- Tiro Certeiro (3PP): 25 dano      - Golpe Sombrio (3PP): 20 dano     \n"
"- Rajada (5PP): 3x10 dano           - Roubo de Vida (4PP): +HP         \n"
"- Flecha Envenenada (4PP): 15 dano - Passo Sombrio (5PP): 2x15 dano   \n"
"========================================================================\n\n");


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
    printf("Voce ganhou a batalha contra %s, pode prosseguir\n", inimigos[i].nome);
  }else{
    printf("Game Over! Voce foi derrotado por %s\n", inimigos[i].nome);
    break;
  }
}
  return 0;
}


