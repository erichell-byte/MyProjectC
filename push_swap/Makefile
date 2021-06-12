NAME = push_swap
LIST = func.c main.c second_corr_stek_a.c checker.c lst_operation.c command_stek_1.c command_stek_2.c command_stek_3.c five_and_less_a.c five_and_less_b.c found_at_stek_1.c found_at_stek_2.c step_1_2.c step_3_4_5_6.c ft_split.c func_2.c ft_strlcpy.c ft_strlen.c back_to_stek_a.c
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) push_swap.c  $?
	
%.o : %.cmkae
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

bonus:

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: bonus clean fclean all re
