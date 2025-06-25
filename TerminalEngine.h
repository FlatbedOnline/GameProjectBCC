#ifndef TERMINALENGINE_H 
#define TERMINALENGINE_H

typedef struct {
    int id;
    char nome[20];
    int HP, ATK, PP;
} ClasseInfo;

typedef struct {
    int classe_id;
    char nome[30];
    char descricao[100];
    int dano;
    int custo_pp;
} Habilidade;

extern ClasseInfo classes[];
extern Habilidade habilidades[];

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

#endif // !TERMINALENGINE_H 
#define TERMINALENGINE_H
