#include <stdio.h>
#include <stdarg.h>
#include "TerminalEngine.h"
#include <stdlib.h>
#include "class.h"
/*                                -------------AVISO----------
* QUANDO ESTIVER TESTANDO SEU CÓDIGO, NÃO ESQUEÇA DE APAGAR TUDO O QUE DEIXOU AQUI PARA TESTES.
* NÃO DE PUSH COM CÓDIGO DE TESTE AQUI. TAMBÉM NÃO DE PUSH COM OS EXECUTAVEIS, SEMPRE DE MAKE CLEAN.
*/


int main(){

int escolha, HP, ATK, PP;
char nome_classe[20];

printf("Bem vindo Aventureiro! \n");
printf("Escolha a classe do seu personagem \n");
printf("\n");
printf("=========== GUERREIRO ===========\n"
"Um combatente equilibrado, com boa vida e defesa.\n"
"HP:\t\t120\n"
"Ataque Base:\t20\n"
"PP:\t\t10\n\n"
"Habilidades:\n"
" - Golpe Escudo: 15 de dano + atordoamento (2 PP)\n"
" - Investida: 35 de dano (4 PP)\n"
" - Postura Defensiva: Reduz dano por 2 turnos (3 PP)\n"
"==================================\n \n"
);

printf(
  "============ MAGO ==============\n"
  "Frágil, mas com ataques poderosos e variados.\n"
  "HP:\t\t80\n"
  "Ataque Base:\t10\n"
  "PP:\t\t20\n\n"
  "Habilidades:\n"
  " - Bola de Fogo: 30 de dano (4 PP)\n"
  " - Raio Gélido: 20 de dano + reduz velocidade (3 PP)\n"
  " - Cura Arcana: Recupera 30 HP (5 PP)\n"
  "==================================\n\n"
);

printf(
  "=========== BÁRBARO ============\n"
  "Muito dano e muita vida, mas sem defesa mágica.\n"
  "HP:\t\t150\n"
  "Ataque Base:\t25\n"
  "PP:\t\t6\n\n"
  "Habilidades:\n"
  " - Esmagada Brutal: 50 de dano (50%% de chance de errar) (3 PP)\n"
  " - Grito Selvagem: Aumenta ataque em 10 por 2 turnos (2 PP)\n"
  " - Fúria: 40 de dano e se machuca em 10 (3 PP)\n"
  "==================================\n\n"
);

printf(
  "=========== ARQUEIRO ============\n"
  "Ágil e preciso, com chance de crítico e habilidades de longo alcance.\n"
  "HP:\t\t100\n"
  "Ataque Base:\t18\n"
  "PP:\t\t12\n\n"
  "Habilidades:\n"
  " - Tiro Certeiro: 25 de dano (30%% chance de crítico) (3 PP)\n"
  " - Rajada de Flechas: 3x10 de dano em um turno (5 PP)\n"
  " - Flecha Envenenada: 15 de dano + envenena por 3 turnos (4 PP)\n"
  "==================================\n\n"
);

printf(
  "=========== LADRÃO =============\n"
  "Especialista em furtividade, ataques rápidos e evasivos.\n"
  "HP:\t\t90\n"
  "Ataque Base:\t16\n"
  "PP:\t\t14\n\n"
  "Habilidades:\n"
  " - Golpe Sombrio: 20 de dano + chance de esquiva aumentada (3 PP)\n"
  " - Roubo de Vida: 15 de dano e recupera metade como HP (4 PP)\n"
  " - Passo Sombrio: Avança e ataca duas vezes com 15 de dano cada (5 PP)\n"
  "==================================\n"
);

printf("Escolha sua classe:\n"
"1 - Guerreiro\n"
"2 - Mago\n"
"3 - Bárbaro\n"
"4 - Arqueiro\n"
"5 - Ladrão\n");
scanf("%d", &escolha);

classe(escolha, &PP, &ATK, &HP, nome_classe);

printf("Classe escolhida: %s\n", nome_classe);
printf("Atributos do personagem:\n");
printf("HP: %d\n", HP);
printf("ATK: %d\n", ATK);
printf("PP: %d\n", PP);

  return 0;
  
}


