NAME = libftprintf.a
LIST = ft_func.c printf.c display_c.c display_d.c display_p.c display_proc.c display_s.c display_x.c display_XX.c num_before_type.c star_flag.c ft_func_2.c display_d2.c display_s2.c display_x2.c display_XX2.c ft_func_3.c star_flag_2.c
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
	
%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

bonus:

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: bonus clean fclean all re