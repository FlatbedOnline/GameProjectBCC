#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>
#include "TerminalEngine.h"

void raw(){
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void normal(){
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int fselect(int numOptions, ...){
  int value;
  va_list list;
  char **selectOptions = malloc(numOptions * sizeof(char*));
  if(!selectOptions){
    printf("fselect error: malloc falhou.");
  }

  va_start(list, numOptions);

  for(int i = 0; i < numOptions; i++){
    selectOptions[i] = va_arg(list, char *); 

    printf("%s\n", selectOptions[i]);
  }
  char keyboard;
  
  raw();

  while(1){
    keyboard = getchar();

    switch (keyboard) {
      case 72 :
        printf("%s", selectOptions[0]);
        break;
      case 80 : printf("%s", selectOptions[1]);
        break;
      case 'a' : printf("teste"); break;
      default: value = 10;
    }
  }

  normal();
  free(selectOptions);
  va_end(list);

  return 0;
}
