NAME = fractol
CC = cc
CFALGS = -Wall -Wextra -Werror

MAIN = srcs/main.c
SRCS = srcs/draw.c \
		srcs/init.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/mouse_keys.c \
		srcs/utils.c \
		srcs/main.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ./obj
LIBFT_PATH = ./includes/libft
LIBFT = ./includes/libft/libft.a
MLX_PATH = ./includes/minilibx
MLX_FLAGS = -L$(MLX_PATH)
MLX_COM = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX = ./includes/minilibx/libmlx.a

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) $(CFALGS) $(MLX_FLAGS) $(LIBFT) $(MLX_COM) $(MLX) $^ -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re