# Compiler
CC = gcc 

# Options du compilateur
CFLAGS = -Wall -Wextra -Werror

# Les fichiers sources
SRCS = ./ex00/clean.c ./ex00/main.c ./ex00/parse.c ./ex00/str_utils2.c ./ex00/str_utils.c ./ex00/savealpha.c ./ex00/conform.c

# Les fichiers objets (générés à partir des sources)
OBJS = $(SRCS:.c=.o)

# Le fichier exécutable final
EXEC = rush-02

#Variable pour arguments
ARGS =

# Règle par défaut
all: $(EXEC)

# Comment générer le fichier exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Comment générer les fichiers objets
%.o: %.c struct.h
	$(CC) $(CFLAGS) -c $< -o $@

# Execution du programme
run: $(EXEC)
	./$(EXEC) $(ARGS)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet (incluant les fichiers générés par l'édition de liens)
fclean: clean
	rm -f $(EXEC)

# Recompiler tout à partir de zéro
re: fclean all

# Les fichiers de dépendance
-include $(OBJS:.o=.d)

# Générer les fichiers de dépendance
%.d: %.c
	$(CC) -MM -MD -MP -MF $@ $<
