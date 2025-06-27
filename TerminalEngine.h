#ifndef TERMINALENGINE_H 
#define TERMINALENGINE_H

int init_audio();

void shutdown_audio();
int play_som(const char *filename);

void play_som_simples(const char *arquivo); 
void pare_som();
char getch();
void showMenu(char * extra,int select, int options, char ** vet); 
int menu(char * extra,int sound, int numOption, ...);
int buscaLinear(int vetor[], int tamanho, int alvo);
int classe(int escolha, int *PP, int *ATK, int *HP, char *nome_classe);

//combate Joao Pedro Veloso
int telaInventario(int *inv);
int telaAtaques(int escolha);
int combate(int escolha);
int turnoinimigo();

#endif // !TERMINALENGINE_H 
#define TERMINALENGINE_H
