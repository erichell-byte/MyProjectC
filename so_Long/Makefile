NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIST = main.c utils/utils.c utils/lst.c gnl/get_next_line.c gnl/get_next_line_utils.c check.c move.c utils/utils2.c parse_do_map.c engine.c
OBJ = $(patsubst %.c,%.o,$(LIST))
MLX = minilibx-Linux/libmlx_Linux.a -lXext -lX11

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(LIST) $(MLX)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

