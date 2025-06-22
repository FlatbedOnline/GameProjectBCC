## Abstração

Cria um menu de seleção com X opções(`...`) em que ao serem selecionadas com a tecla `Enter` ou `Space` retorna um número relativo ao seu index.

---
## Syntax

```c
int menu(int* extra, int sound, int numOption, ...);
```
- `int* extra` = extra caracteres do tipo **string** que podem ser colocadas como argumento extra. Bastante util para determinar a margin lateral dos botões. Caso não queira colocar caracteres extras, apenas coloque "\0"
- `int sound` = sons que os botões fazem ao serem selecionados. 1 para ligado e 0 para desligado.
- `int numOptions` = Quantidade de opções a serem colocadas. 
- `...` = quantidade indefinida de variáveis do tipo **string**.

>[!Warning ]
>Somente insira strings em `...`

---
## Exemplo

```c
int opcao; 
opcao = menu("\0", 1, 3, "Atacar", "Abrir inventário", "Correr",);
printf("Opção selecionada: %d\n", opcao);
```

```shell
[Atacar] Abrir inventário Correr
Opção selecionada: 1
```
---

| return type: | int              |
| ------------ | ---------------- |
| headerfile:  | TerminalEngine.h |
