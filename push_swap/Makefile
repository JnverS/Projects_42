NAME = push_swap

NAME_B = checker

INC = include/push_swap.h

INC_B = include/push_swap_bonus.h

SRC = main.c movement_1.c movement_2.c movement_3.c \
		validation.c sort.c utils.c calc_score.c \
		fnd_elem.c swaps.c min_sort.c

SRC_B = main_bonus.c get_next_line.c get_next_line_utils.c \
		move_1_bonus.c move_2_bonus.c move_3_bonus.c \
		valid_bonus.c

SRCS = $(addprefix ./src/, $(SRC))

SRCS_B = $(addprefix ./src/bonus/, $(SRC_B))

OBJ = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

LDIR = libft/

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@make bonus -C $(LDIR)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS) -I $(INC)

clean :
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C $(LDIR)

fclean : clean
	@rm -f $(NAME) $(NAME_B)
	@make fclean -C $(LDIR)

bonus : ${NAME_B}

${NAME_B} : $(OBJ_B) $(INC_B)
	@make bonus -C $(LDIR)
	gcc $(FLAGS) -o $(NAME_B) $(OBJ_B) $(LFLAGS) -I $(INC_B)

re : fclean all

.PHONY: all clean fclean re bonus
