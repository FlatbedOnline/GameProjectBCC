#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <termios.h>
#include "miniaudio.h"
#include "TerminalEngine.h"

#define MINIAUDIO_IMPLEMENTATION 

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

void showMenu(char * extra, int select, int options, char ** vet) {
  printf("\r");
  printf("%s", extra); 
  for (int i = 0; i < options; i++) {
    
    if(*extra == '\0'){
     if (i == select)
            printf(" [%s] ", vet[i]);
      else
            printf("  %s  ", vet[i]);
    }else{
      if (i == select){
            printf(" [%s] ", vet[i]);
      }else{
            printf("  %s  ",vet[i]);
      }

    }

  }
}

int menu(char * extra, int sound, int numOptions,...){

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

    showMenu(extra,selected, numOptions, selectOptions);

    while ((ch = getch()) != '\n' && ch != 32) {
        if (ch == 27) { // ESC
            if (getch() == '[') {
                char dir = getch();
                if (dir == 'C') {// → direita
                     selected = (selected + 1) % numOptions;                
              } else if (dir == 'D') { // ← esquerda
                    selected = (selected - 1 + numOptions) % numOptions;
                }
                showMenu(extra,selected, numOptions, selectOptions);
            }
        }
        
    
    }
  if(sound == 1){
    pare_som();
    play_som_simples("selected.mp3"); 
  }

  sleep(2);
  free(selectOptions);
  va_end(list);

  return selected + 1;
}

int buscaLinear(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i;
        } else if (vetor[i] > alvo) {
            break; 
        }
    }
    return -1; // Elemento não encontrado
}

//----------------AUDIO ROUTINE---------------------
ma_engine engine;
ma_sound sound;

int init_audio() {
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        printf("Erro ao iniciar engine.\n");
        return 0;
    }
    return 1;
  //esse daqui bloqueia, os audios em paralelo, porém tu pode usar o pare_som()
}

void play_som_simples(const char *arquivo) {
    ma_engine_play_sound(&engine, arquivo, NULL);
    // Não bloqueia, não espera terminar mas tu não pode usar o pare_som()
}

int play_som(const char *filename) {
    if (ma_sound_init_from_file(&engine, filename, 0, NULL, NULL, &sound) != MA_SUCCESS) {
        printf("Erro ao carregar música: %s\n", filename);
        return 0;
    }
    ma_sound_start(&sound);
    return 1;
}

void pare_som() {
    ma_sound_stop(&sound);
    ma_sound_uninit(&sound);
}

void shutdown_audio() {
    ma_engine_uninit(&engine);
}

//------------------------------------------
