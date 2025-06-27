# Nome do executável
EXEC = programa

# Lista de arquivos fonte
SRC = main.c TerminalEngine.c miniaudio.c class.c combate.c inimigo.c

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Outras regras
RULES = -lpthread -lm

# Regra padrão
all: $(EXEC)

# Como compilar o executável
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC) $(RULES)

# Limpa arquivos compilados
clean:
	rm -f $(EXEC)
