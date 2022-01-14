NAME = push_swap

INC = include/push_swap.h

SRC = main.c function_sort.c validation.c sort.c


SRCS = $(addprefix ./src/, $(SRC))


OBJ = ${SRCS:.c=.o}


LDIR = libft/

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@make bonus -C $(LDIR)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LFLAGS) -I $(INC)

clean :
	@rm -f $(OBJ) $(OBJ_ARR)
	@make clean -C $(LDIR)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LDIR)

bonus : $(OBJ_B) $(INC_B)
	@make -C $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) $(FLAGS) -I $(INC_B) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
