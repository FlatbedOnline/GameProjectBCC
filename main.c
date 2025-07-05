#include <stdio.h>
#include <stdarg.h>
#include "TerminalEngine.h"
#include <stdlib.h>
#include <time.h>
#include "class.h"

// Função que imprime a área fixa das classes no topo
void mostrar_classes() {
    printf("\033[H\033[J"); // Limpa a tela e volta ao topo

    // Área fixa - informações das classes
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
//atualizar linha 
void narrativa(const char* texto) {
    mostrar_classes(); // fixa info das classes no topo
    printf("%s", texto);
    printf(" (Pressione Enter para continuar...)");
    fflush(stdout);
    getchar();
}

int main(){
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

narrativa("Suspiros ecoam na escuridão, cada um um sussurro perdido no tempo...\n...\nRespiração pesada rasga o silêncio, misturada ao som distante de gotas que caem incessantes.\n...\n— Ele ainda está dormindo...");

narrativa("Meus olhos pesam enquanto a dor nas costas cresce.\nO cheiro úmido e rançoso do mofo invade minhas narinas, lembrando que não estou em um lugar comum.\nÀ minha frente, um velho encapuzado emerge das sombras, seus olhos profundos brilham com uma sabedoria ancestral, e sua barba longa parece carregar o peso das eras.");

narrativa("— Quem és tu? — minha voz sai áspera, enquanto puxo a arma instintivamente.\n— Calma, jovem guerreiro — ele responde, voz firme mas serena.\n— Não vim te ferir. Vim contar uma história, oferecer uma escolha que pode mudar seu destino.");

narrativa("Ele se senta perto da chama vacilante da tocha, as sombras dançam no rosto enrugado.\n— Escute com atenção.\n— Há séculos, muito antes de impérios caírem, um artefato foi forjado pelo próprio deus Tales, agora adormecido.\n— O Amuleto carrega o poder de enxergar além das barreiras do tempo e da realidade.");

narrativa("— Porém, este poder tem preço.\n— Aquele que o possuir poderá alcançar glória inimaginável... ou perder-se para sempre nas memórias esquecidas.\n— Por que você não o busca? — pergunto, a curiosidade e desconfiança misturadas.\n— Meus ossos são frágeis, a idade me aprisiona.\n Mas você, com seu vigor e coragem, tem a chance que eu não tive.");

narrativa("— Traga o Amuleto para mim.\n— Serás recompensado com armas forjadas nas chamas da antiguidade, armas que cortam o próprio ar, arcos guiados pela vontade, magias que desafiam a morte.\n— Mas não será fácil. O caminho é traiçoeiro e cheio de horrores.\n— Aceita essa missão? Que os deuses guiem seus passos.");

mostrar_classes();
printf("Escolha a classe do seu personagem\n\n");

escolha = menu("Escolha sua classe:", 1, 5, "Guerreiro", "Mago", "Bárbaro", "Arqueiro", "Ladrão");
classe(escolha, &PP, &ATK, &HP, nome_classe);

mostrar_classes();
printf("\nClasse escolhida: %s\n", nome_classe);
printf("Atributos do personagem:\nHP: %d\nATK: %d\nPP: %d\n", HP, ATK, PP);

narrativa("Com a missão selada em meu coração, adentro a masmorra.\nO ar é denso, impregnado de umidade e cheiro de terra velha.\nCada passo ecoa, despertando sombras adormecidas.\nPenso nas palavras do velho mago e sinto a pulsação do destino.");

narrativa("Enquanto caminho pelos corredores estreitos, vejo marcas estranhas nas paredes — símbolos que parecem contar a história de antigos guerreiros e suas lutas contra forças sombrias.\nPergunto-me quantos já passaram por aqui, quantos caíram e quantos nunca mais foram vistos.\nA solidão começa a pesar, e a incerteza tenta corroer minha coragem.");

narrativa("Um grunhido rompe o silêncio.\nDe trás de uma pilha de ossos, um goblin enfurecido salta com olhos brilhando de ódio.");

printf("Oponente: %s\n", inimigos[0].nome);
if (combate(escolha - 1, 0) == 1) {
    narrativa("O golpe final ecoa no ar. Meu braço lateja, mas a vitória me aquece.\nSinto o sangue pulsar em minhas veias, o perigo ainda não terminou.");
} else {
    printf("Game Over! Você foi derrotado por %s.\n", inimigos[0].nome);
    return 0;
}

narrativa("Após o combate, me apoio contra a parede fria, tentando recuperar o fôlego.\nEnquanto observo a tocha que tremula, meus pensamentos vagam até a história que o velho mago contou.\nO Amuleto de Tales... Um poder tão antigo que parece desafiar até a própria realidade.\nSerá que vale o preço? A dúvida me assombra, mas a vontade de continuar é mais forte.");

narrativa("Sigo adiante e noto que as inscrições nas paredes ficam mais elaboradas, quase vivas, como se tentassem me contar um segredo.\nAs sombras parecem se mover de forma inquietante, e o silêncio torna-se quase sufocante.\nPosso jurar que algo me observa, aguardando o momento certo para atacar.");

narrativa("Um som metálico corta o ar.\nDas sombras ergue-se um esqueleto, ainda trajando armadura corroída pelo tempo, com sua espada enferrujada.");

printf("Oponente: %s\n", inimigos[1].nome);
if (combate(escolha - 1, 1) == 1) {
    narrativa("Os ossos caem com um estrondo seco.\nToco a parede e sinto um calor estranho, como se a própria masmorra respirasse e reagisse à minha presença.");
} else {
    printf("Game Over! Você foi derrotado por %s.\n", inimigos[1].nome);
    return 0;
}

narrativa("O silêncio volta, pesado e profundo.\nCaminho por um corredor onde antigas tapeçarias pendem, suas cores desbotadas pelo tempo, retratando batalhas e reis há muito esquecidos.\nImagino a história que aquele lugar guarda, vidas que se perderam tentando conquistar ou proteger o amuleto.");

narrativa("Me pergunto se o velho mago já teve algum contato com esse passado.\nSua voz ecoa na minha mente, avisando sobre a maldição.\nO que me espera adiante? Minhas mãos tremem, mas sigo firme.");

narrativa("Adentro uma câmara tomada por limo viscoso.\nPedaços de corpos derretem no chão, um cheiro acre e tóxico preenche o ar.");

narrativa("Um slime repulsivo se arrasta na minha direção, seus olhos gelatinosos fixos em mim como se soubesse que sou o intruso.");

printf("Oponente: %s\n", inimigos[2].nome);
if (combate(escolha - 1, 2) == 1) {
    narrativa("O cheiro me faz vomitar, minha garganta arde.\nSinto uma sombra escura invadir meus pensamentos, uma mudança que não entendo.\nMas o caminho ainda não terminou.");
} else {
    printf("Game Over! Você foi derrotado por %s.\n", inimigos[2].nome);
    return 0;
}

narrativa("Afasto-me da câmara, ofegante.\nSinto meu corpo enfraquecer, e a presença do amuleto — ainda distante — parece exercer uma força que me atrai e ao mesmo tempo repele.\nA masmorra guarda segredos que nem o tempo ousou desvendar.");

narrativa("As chamas da tocha tremulam e se apagam.\nO silêncio absoluto envolve tudo, e o som do meu próprio coração ressoa como um tambor solitário.");

narrativa("Olhos surgem no breu, numerosos e espectrais.\nUm espírito ancestral se materializa diante de mim, sua presença impõe respeito e temor.");

printf("Oponente: %s\n", inimigos[3].nome);
if (combate(escolha - 1, 3) == 1) {
    narrativa("O espírito se desfaz em uma névoa etérea.\nOuço um sussurro indecifrável, e por um instante, vejo o mago observando, em silêncio, dos recantos sombrios.");
} else {
    printf("Game Over! Você foi derrotado por %s.\n", inimigos[3].nome);
    return 0;
}

narrativa("Silêncio absoluto.\nSinto o peso da presença daquele espírito, como se ele tivesse guardado um segredo que agora só eu posso carregar.\nMeu coração bate acelerado, consciente de que o fim está próximo.");

narrativa("Finalmente, chego ao coração da masmorra.\nUm altar maciço, coberto por runas antigas e um caixão de pedra repousa sobre ele.");

narrativa("O caixão se abre lentamente, revelando um vampiro ancestral, seus olhos rubros perfuram a escuridão.");

printf("Oponente: %s\n", inimigos[4].nome);
if (combate(escolha - 1, 4) == 1) {
    narrativa("Com um último rugido, o vampiro se desfaz em cinzas.\nA luz púrpura envolve o altar, revelando o Amuleto de Tales, pulsando com um poder indescritível.");
} else {
    printf("Game Over! Você foi derrotado por %s.\n", inimigos[4].nome);
    return 0;
}

narrativa("Estendo a mão e toco o amuleto.\nVisões me assaltam: batalhas épicas, deuses adormecidos, sacrifícios esquecidos e segredos proibidos.\nMinha mente se enche e se perde ao mesmo tempo.");

narrativa("A voz do mago ecoa, mas agora sua tonalidade é fria, distante.");

narrativa("— Obrigado por libertar o amuleto...\nEle precisava de um novo portador.\nAgora você é o seu receptáculo... e a maldição te acompanha para sempre.");

narrativa("Sinto meu corpo se desfazer em luzes e sombras.\nTento gritar, mas não tenho mais voz.\nEstou preso, fundido à masmorra, parte dela para toda a eternidade.");

narrativa("— Ele ainda está dormindo... — a voz retorna, sombria e silenciosa, ecoando pelo vazio.");

printf("\nJogo finalizado. Obrigado por jogar!\n");

}