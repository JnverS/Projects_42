NAME = push_swap

INC = include/push_swap.h

SRC = main.c function_sort.c validation.c
SRC_ARR = main_arr.c

SRCS = $(addprefix ./src/, $(SRC))
SRCS_ARR = $(addprefix ./src/, $(SRC_ARR))

OBJ = ${SRCS:.c=.o}
OBJ_ARR = ${SRCS_ARR:.c=.o}

LDIR = libft/

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@make -C $(LDIR)
	@make bonus -C $(LDIR)
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(LFLAGS) -I $(INC)

arr : $(OBJ_ARR) $(INC)
	@make -C $(LDIR)
	@make bonus -C $(LDIR)
	gcc -o $(NAME) $(OBJ_ARR) $(FLAGS) $(LFLAGS) -I $(INC)

clean :
	@make fclean -C $(LDIR)
	@rm -f $(OBJ) $(OBJ_ARR)

fclean : clean
	@rm -f $(NAME)

bonus : $(OBJ_B) $(INC_B)
	@make -C $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) $(FLAGS) -I $(INC_B) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
