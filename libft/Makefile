NAME=libft.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
SOURCES=ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_min.c \
		ft_max.c \
		ft_swap.c \
		ft_abs.c \
		ft_streq.c

BONUS=	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJECTS=$(SOURCES:.c=.o)

BONUS_OBJECTS=$(BONUS:.c=.o)

HEADER=libft.h

all: $(NAME)

bonus: $(NAME)

$(NAME): ${OBJECTS} $(if $(findstring bonus, $(MAKECMDGOALS)), $(BONUS_OBJECTS))
	ar rcs $(NAME) $?

%.o: %.c ${HEADER}
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -rf ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re bonus
