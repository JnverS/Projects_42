NAME = push_swap

INC = include/push_swap.h

SRC = main.c

SRCS = $(addprefix ./src/, $(SRC))

OBJ = ${SRCS:.c=.o}

LDIR = libft/

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@make bonus -C $(LDIR)
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(LFLAGS) -I $(INC)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

bonus : $(OBJ_B) $(INC_B)
	@make -C $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) $(FLAGS) -I $(INC_B) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
