# Nome do executável
EXEC = programa

# Lista de arquivos fonte
SRC = main.c TerminalEngine.c

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Regra padrão
all: $(EXEC)

# Como compilar o executável
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Limpa arquivos compilados
clean:
	rm -f $(EXEC)
