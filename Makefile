

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g
#-fsanitize=thread
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRC_DIR = ./srcs
UTILS_DIR = ./scrs/utils
INC_DIR = ./includes

VPATH = ./srcs:./srcs/utils

# find /path/to/folder -name "*.c"
#SRC_FILES = $(shell find srcs -type f -name '*.c')
SRC_FILES = actions.c \
			exit.c \
			get_time.c \
			init_structs.c \
			inputChecker.c \
			threads.c \
			checker_routine.c \
			main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all:  $(NAME)


$(NAME): $(OBJ_FILES)
	@echo $(OBJ_FILES)
	@echo $(Y)Compiling [$(OBJ_FILES)]...$(X)
	@echo $(G)Finished [$(OBJ_FILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ_FILES)  -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@rm -f $(OBJ_FILES)
	@echo $(R)Removed [$(OBJ_FILES)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

compile:
	make re
	make clean
re: fclean all
