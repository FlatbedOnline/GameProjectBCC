A regra padrão se chama `all:` e será chamada simplesmente por colocar:
```Makefile
all:
	gcc main.c -o main
```

---

Para criar variáveis simplesmente faça:
```Makefile
VARIAVEL = gcc main.c -o main #aqui você criou a variavel

all:
	$(VARIAVEL) #aqui você está usando ela como parametro no comando all.
```

