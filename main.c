#include <stdio.h>
#include <stdarg.h>
#include "TerminalEngine.h"
#include <stdlib.h>
/*                                -------------AVISO----------
* QUANDO ESTIVER TESTANDO SEU CÓDIGO, NÃO ESQUEÇA DE APAGAR TUDO O QUE DEIXOU AQUI PARA TESTES.
* NÃO DE PUSH COM CÓDIGO DE TESTE AQUI. TAMBÉM NÃO DE PUSH COM OS EXECUTAVEIS, SEMPRE DE MAKE CLEAN.
*/


int main(){
  init_audio(); //Deve ser evocado SEMPRE no começo do main.

  system("cat menu.txt");

  play_som("music.mp3");//função que realmente toca a música.

  printf("\n                     GAME: MENU DE TESTE\n");

   //Exemplo prático de uso da função menu.
  if(menu("                      ",1, 2,"Jogar","Sair") == 1){
    printf("\nO jogo não ta pronto ainda... \n");
    return 0;
  }else{
    printf("\nSaindo..\n");
  }
  
  shutdown_audio(); //Deve ser evocado SEMPRE antes do return.
  return 0;
}


