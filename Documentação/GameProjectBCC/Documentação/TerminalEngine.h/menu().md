## Abstração

Cria um menu de seleção com X opções(`...`) em que ao serem selecionadas com a tecla `Enter` ou `Space` retorna um número relativo ao seu index.

---
## Syntax

```c
int menu(int numOption, ...);
```
- `int numOptions` = Quantidade de opções a serem colocadas. 
- `...` = quantidade indefinida de variáveis do tipo **string**.

>[!Warning ]
>Somente insira strings em `...`

---
## Exemplo

```c
int opcao; 
opcao = menu(3, "Atacar", "Abrir inventário", "Correr",);
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
