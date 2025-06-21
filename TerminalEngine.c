#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>
#include "TerminalEngine.h"

char getch() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void showMenu(int select, int options, char ** vet) {
  printf("\r");  
  for (int i = 0; i < options; i++) {
        if (i == select)
            printf(" [%s] ", vet[i]);
    else
            printf("  %s  ", vet[i]);
    }
}

int menu(int numOptions, ...){
  va_list list;
  char **selectOptions = malloc(numOptions * sizeof(char*));
  if(!selectOptions){
    printf("fselect error: malloc falhou.");
  }

  va_start(list, numOptions);
  for(int i = 0; i < numOptions; i++){
    selectOptions[i] = va_arg(list, char *); 
  }

  for(int i = 0; i < numOptions; i++){
    printf("\r"); // \r volta o cursor pro começo da linha, tentem usar isso, é bem útil.
    if (numOptions == 0)
        printf("[%s] ", selectOptions[i]);
    else
        printf("%s ", selectOptions[i]);
    fflush(stdout);
  }

    int selected = 0; 
    char ch;

    showMenu(selected, numOptions, selectOptions);

    while ((ch = getch()) != '\n' && ch != 32) {
        if (ch == 27) { // ESC
            if (getch() == '[') {
                char dir = getch();
                if (dir == 'C') {// → direita
                     selected = (selected + 1) % numOptions;                
              } else if (dir == 'D') { // ← esquerda
                    selected = (selected - 1 + numOptions) % numOptions;
                }
                showMenu(selected, numOptions, selectOptions);
            }
        }
        
    
    }

  
  free(selectOptions);
  va_end(list);

  return selected + 1;
}

int buscaLinear(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i; // Retorna o índice do elemento encontrado
        } else if (vetor[i] > alvo) {
            break; // Como o vetor está ordenado, não faz sentido continuar
        }
    }
    return -1; // Elemento não encontrado
}
