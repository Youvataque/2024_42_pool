# Compiler
CC = gcc 

# Options du compilateur
CFLAGS = -Wall -Wextra -Werror

# Les fichiers sources
SRCS = clean.c main.c parse.c str_utils2.c str_utils.c savealpha.c conform.c

# Les fichiers objets (générés à partir des sources)
OBJS = $(SRCS:.c=.o)

# Le fichier exécutable final
NAME = rush-02

#Variable pour arguments
ARGS =

# Règle par défaut
all: $(NAME)

# Comment générer le fichier exécutable
$(NAME): $(OBJS)
	if [ ! -f $(NAME) ]; then $(CC) $(CFLAGS) -o $@ $^; fi

# Comment générer les fichiers objets
%.o: %.c struct.h
	$(CC) $(CFLAGS) -c $< -o $@

# Execution du programme
run: $(NAME)
	./$(NAME) $(ARGS)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(NAME)

# Nettoyage complet (incluant les fichiers générés par l'édition de liens)
fclean: clean
	rm -f $(NAME)

# Recompiler tout à partir de zéro
re: fclean all

# Les fichiers de dépendance
-include $(OBJS:.o=.d)

# Générer les fichiers de dépendance
%.d: %.c
