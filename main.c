#include <stdio.h>
#include <stdarg.h>
#include "TerminalEngine.h"
#include <stdlib.h>
#include <time.h>
#include "class.h"

// exibe todas as classes
void mostrar_todas_classes() {
    printf("\033[H\033[J");
    printf(
    "=========== GUERREIRO ===========   ============= MAGO =============   ============ BÁRBARO ============\n"
    "Tanque equilibrado, bom HP e        Frágil, mas poderoso com magias.   Muito dano físico, baixa energia.\n"
    "ótimo para combate direto.          Ideal para ataques à distância.     \n"
    "HP:         125                     HP:         85                     HP:         140\n"
    "ATK Base:   12                      ATK Base:   13                     ATK Base:   20\n"
    "PP:         11                      PP:         18                     PP:         5\n\n"
    "Habilidades:                        Habilidades:                       Habilidades:\n"
    "- Golpe Espada (0PP): 12 dano       - Ataque Mágico (0PP): 13 dano     - Ataque Machado (0PP): 20 dano\n"
    "- Golpe Escudo (2PP): 18 dano       - Bola de Fogo (5PP): 35 dano      - Esmagada Brutal (4PP): 45 dano\n"
    "- Investida (4PP): 35 dano          - Raio Gélido (3PP): 20 dano       - Lapada Seca (2PP): 25 dano\n"
    "- Postura Defensiva (3PP): bloqueia - Cura Arcana (5PP): +30 HP        - Fúria (3PP): 40 dano\n"
    "o dano de um round.                                                      \n"
    "==========================================================================================================\n\n"
    "=========== ARQUEIRO ============   ============ LADRÃO =============   \n"
    "Versátil e técnico, ideal para      Ágil e furtivo, especialista       \n"
    "combates de longa distância.        em ataques críticos.               \n"
    "HP:         100                     HP:         100                    \n"
    "ATK Base:   10                      ATK Base:   12                     \n"
    "PP:         14                      PP:         16                     \n\n"
    "Habilidades:                        Habilidades:                        \n"
    "- Flechada (0PP): 10 dano           - Facada (0PP): 12 dano            \n"
    "- Tiro Certeiro (3PP): 25 dano      - Golpe Sombrio (2PP): 25 dano     \n"
    "- Rajada de Flechas (5PP): 3x10     - Apunhalada (1PP): 16 dano        \n"
    "- Flecha Envenenada (4PP): 27 dano  - Passo Sombrio (3PP): 2x15 dano   \n"
    "========================================================================\n\n"
    );
}

// exibe apenas a classe escolhida
void mostrar_classe(int escolha) {
    printf("\033[H\033[J");
    switch (escolha) {
        case 1: // guerreiro
            printf("=========== GUERREIRO ===========\n"
                   "Tanque equilibrado, bom HP e ótimo para combate direto.\n"
                   "HP:  125\nATK: 12\nPP:  11\n"
                   "Habilidades:\n"
                   "- Golpe Espada (0PP): 12 dano\n"
                   "- Golpe Escudo (2PP): 18 dano\n"
                   "- Investida (4PP): 35 dano\n"
                   "- Postura Defensiva (3PP): bloqueia o dano de um round\n"
                   "=================================\n\n");
            break;
        case 2: // mago
            printf("============= MAGO =============\n"
                   "Frágil, mas poderoso com magias.\n"
                   "HP:  85\nATK: 13\nPP:  18\n"
                   "Habilidades:\n"
                   "- Ataque Mágico (0PP): 13 dano\n"
                   "- Bola de Fogo (5PP): 35 dano\n"
                   "- Raio Gélido (3PP): 20 dano\n"
                   "- Cura Arcana (5PP): +30 HP\n"
                   "================================\n\n");
            break;
        case 3: // bárbaro
            printf("=========== BÁRBARO ============\n"
                   "Muito dano físico, baixa energia.\n"
                   "HP:  140\nATK: 20\nPP:  5\n"
                   "Habilidades:\n"
                   "- Ataque Machado (0PP): 20 dano\n"
                   "- Esmagada Brutal (4PP): 45 dano\n"
                   "- Lapada Seca (2PP): 25 dano\n"
                   "- Fúria (3PP): 40 dano\n"
                   "===============================\n\n");
            break;
        case 4: // arqueiro
            printf("=========== ARQUEIRO ===========\n"
                   "Versátil, ideal para longa distância.\n"
                   "HP:  100\nATK: 10\nPP:  14\n"
                   "Habilidades:\n"
                   "- Flechada (0PP): 10 dano\n"
                   "- Tiro Certeiro (3PP): 25 dano\n"
                   "- Rajada de Flechas (5PP): 3x10 dano\n"
                   "- Flecha Envenenada (4PP): 27 dano\n"
                   "===============================\n\n");
            break;
        case 5: // ladrão
            printf("=========== LADRÃO =============\n"
                   "Ágil e furtivo, especialista em críticos.\n"
                   "HP: 100\nATK: 12\nPP: 16\n"
                   "Habilidades:\n"
                   "- Facada (0PP): 12 dano\n"
                   "- Golpe Sombrio (2PP): 25 dano\n"
                   "- Apunhalada (1PP): 16 dano\n"
                   "- Passo Sombrio (3PP): 2x15 dano\n"
                   "===============================\n\n");
            break;
    }
}

// mostra a classe e o texto da narrativa
void narrativa(const char* texto, int escolha) {
    mostrar_classe(escolha);
    printf("%s", texto);
    printf("\n(Pressione Enter para continuar...)");
    fflush(stdout);
    getchar();
}

int main() {
    srand(time(NULL));
    int escolha, HP, ATK, PP, escolhamenu;
    char nome_classe[20];

    printf(
    "    ███        ▄████████  ▄█          ▄████████    ▄████████ \n"
    "▀█████████▄   ███    ███ ███         ███    ███   ███    ███ \n"
    "   ▀███▀▀██   ███    ███ ███         ███    █▀    ███    █▀  \n"
    "    ███   ▀   ███    ███ ███        ▄███▄▄▄       ███        \n"
    "    ███     ▀███████████ ███       ▀▀███▀▀▀     ▀███████████ \n"
    "    ███       ███    ███ ███         ███    █▄           ███ \n"
    "    ███       ███    ███ ███▌    ▄   ███    ███    ▄█    ███ \n"
    "   ▄████▀     ███    █▀  █████▄▄██   ██████████  ▄████████▀  \n"
    "                         ▀                                   \n"
    );

    init_audio();
    escolhamenu = menu("Escolha:", 1, 2, "Jogar", "Sair");
    if (escolhamenu == 2) {
        printf("Saindo do jogo...\n");
        return 0;
    }

    mostrar_todas_classes();
    escolha = menu("Escolha sua classe:", 1, 5, "Guerreiro", "Mago", "Bárbaro", "Arqueiro", "Ladrão");
    classe(escolha, &PP, &ATK, &HP, nome_classe);

    mostrar_classe(escolha);
    printf("Classe escolhida: %s\nHP: %d\nATK: %d\nPP: %d\n", nome_classe, HP, ATK, PP);
    getchar();

    narrativa("Suspiros ecoam na escuridão, cada um, um sussurro perdido no tempo...\n...\nRespiração pesada rasga o silêncio, misturada ao som distante de gotas que caem.", escolha);
    narrativa("Meus olhos pesam enquanto a dor nas costas cresce...\nÀ minha frente, um velho encapuzado emerge das sombras, seus olhos brilham com sabedoria ancestral.", escolha);
    narrativa("— Quem és tu? — minha voz sai áspera...\n— Calma, jovem aventureiro — ele responde.\n— Vim contar uma história. Uma escolha que pode mudar seu destino.", escolha);
    narrativa("Ele se senta à luz trêmula da tocha.\n— Escute com atenção.", escolha);
    narrativa("— Há séculos, muito antes de impérios caírem, um artefato foi forjado pelo próprio deus Tales, agora adormecido.\n— O Amuleto carrega o poder de enxergar além das barreiras do tempo e da realidade.", escolha);
    narrativa("— Porém, este poder tem um preço.\n— Aquele que o possuir poderá alcançar glória inimaginável... ou perder-se para sempre nas memórias esquecidas.\n— Por que você não o busca? — pergunto.\n— Meus ossos são frágeis. Mas você... ainda tem tempo.", escolha);
    narrativa("— Traga o amuleto para mim.\n— Serás recompensado com armas que cortam o ar, magias que desafiam a morte.\n— Mas o caminho será traiçoeiro.", escolha);
    narrativa("— Aceita essa missão? Que os deuses guiem seus passos.", escolha);
    narrativa("Com a missão selada no coração, adentro a masmorra...\nO ar é denso, úmido. Cada passo ecoa entre as sombras adormecidas.", escolha);
    narrativa("Símbolos antigos cobrem as paredes. Quantos já passaram por aqui? Quantos voltaram?", escolha);
    narrativa("Um grunhido rompe o silêncio.\nDe trás de uma pilha de ossos, um goblin salta com ódio nos olhos.", escolha);

    printf("Oponente: %s\n", inimigos[0].nome);
    if (combate(escolha - 1, 0) == 1)
        narrativa("O golpe final ecoa no ar. Meu braço lateja, mas a vitória me aquece.\nSinto o sangue pulsar em minhas veias. O perigo ainda não terminou.", escolha);
    else {
        printf("Game Over! Você foi derrotado por %s.\n", inimigos[0].nome);
        return 0;
    }

    narrativa("Ofegante, apoio-me na parede fria. As palavras do velho mago ecoam na mente.", escolha);
    narrativa("As inscrições ficam mais complexas. O silêncio pesa. Algo me observa.", escolha);
    narrativa("Um som metálico rasga o ar. Um esqueleto armado emerge das sombras.", escolha);

    printf("Oponente: %s\n", inimigos[1].nome);
    if (combate(escolha - 1, 1) == 1)
        narrativa("O som seco dos ossos caindo me desperta do transe.\nA masmorra parece respirar.", escolha);
    else {
        printf("Game Over! Você foi derrotado por %s.\n", inimigos[1].nome);
        return 0;
    }

    narrativa("Antigas tapeçarias pendem ao redor. Retratam batalhas há muito esquecidas.", escolha);
    narrativa("Adentro uma câmara coberta de limo. O ar está podre.", escolha);
    narrativa("Um slime nojento rasteja até mim, seus olhos fixos como se eu fosse sua próxima refeição.", escolha);

    printf("Oponente: %s\n", inimigos[2].nome);
    if (combate(escolha - 1, 2) == 1)
        narrativa("Vomito com o cheiro. Uma sombra toca minha mente.\nMas continuo.", escolha);
    else {
        printf("Game Over! Você foi derrotado por %s.\n", inimigos[2].nome);
        return 0;
    }

    narrativa("As chamas se apagam. O breu toma conta. Silêncio total.", escolha);
    narrativa("Olhos surgem no escuro. Um espírito sombrio se materializa diante de mim.", escolha);

    printf("Oponente: %s\n", inimigos[3].nome);
    if (combate(escolha - 1, 3) == 1)
        narrativa("O espírito se dissipa em névoa. Um sussurro ecoa. O velho está me observando.", escolha);
    else {
        printf("Game Over! Você foi derrotado por %s.\n", inimigos[3].nome);
        return 0;
    }

    narrativa("Chego ao coração da masmorra.\nUm altar de pedra com um caixão selado por runas.", escolha);
    narrativa("O caixão se abre lentamente. Um vampiro ancestral desperta.", escolha);

    printf("Oponente: %s\n", inimigos[4].nome);
    if (combate(escolha - 1, 4) == 1)
        narrativa("Com um último rugido, o vampiro se desfaz em cinzas. O amuleto surge, pulsando poder.", escolha);
    else {
        printf("Game Over! Você foi derrotado por %s.\n", inimigos[4].nome);
        return 0;
    }

    narrativa("Estendo a mão e toco o amuleto.\nVisões me assaltam: batalhas épicas, deuses adormecidos, segredos esquecidos.", escolha);
    narrativa("A voz do mago retorna, fria e distante...", escolha);
    narrativa("— Obrigado por libertar o amuleto...\nEle precisava de um novo portador.\nAgora você é o receptáculo... e a maldição te acompanha para sempre.", escolha);
    narrativa("Sinto meu corpo se desfazer em luzes e sombras.\nTento gritar, mas não tenho mais voz.\nEstou preso, fundido à masmorra, parte dela para toda a eternidade.", escolha);
    narrativa("Suspiros ecoam na escuridão, cada um, um sussurro perdido no tempo... \n — Ele ainda está dormindo...", escolha);

    printf("\nJogo finalizado. Obrigado por jogar!\n");
    return 0;
}
