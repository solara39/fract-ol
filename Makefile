.PHONY: all clean fclean re

NAME = fractol
CC = cc
CFALGS = -Wall -Wextra -Werror

SRCS = src/
OBJS = $(SRCS:.c=.o)
MAIN = src/main.c


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
# $(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)



clean:

fclean:

re:fclean all
