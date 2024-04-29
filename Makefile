NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN = main.c
SRCS = srcs/init.c\
		srcs/utils.c\
		srcs/mouse_keys.c\
		srcs/draw.c\
		srcs/mandelbrot.c\
		srcs/julia.c

LIBFT_PATH = include/libft
LIBFT = include/libft/libft.a
MLX_PATH = lib/minilibx
MLX_FLAGS = -L$(MLX_PATH)
MLX_COM = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX = lib/minilibx/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(MAIN)
	$(CC) $(MAIN) $(SRCS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(NAME): $(MAIN)
#	$(CC) $(MAIN) -o $@ $^ $(SRCS) $(LIBFT_PATH) $(MLX_COM) -o $(NAME)


clean:
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
