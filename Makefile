NAME=pipex
CC=clang
CFLAGS=-Wall -Wextra -Werror -g -MMD

SRC_FILES=pipex.c \
		parse.c \
		parse_utils.c \
		pipe_utils.c \
		start_processes.c \
		utils.c \
		get_next_line.c \
		get_next_line_utils.c
SRC_DIR=src
SRC=$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ_DIR=obj
OBJ=$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

DEP=$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.d))

INC_FILES=pipex.h
INC_DIR=include
CFLAGS+=-I $(INC_DIR)

LIBFT_DIR=libft
LIBFT_NAME=ft
LIBFT=$(LIBFT_DIR)/lib$(LIBFT_NAME).a
CFLAGS+=-I $(LIBFT_DIR)


all: libft $(NAME)

bonus: all

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L $(LIBFT_DIR) -l $(LIBFT_NAME) -o $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft:
	@make -C libft bonus

clean:
	@make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re libft bonus
