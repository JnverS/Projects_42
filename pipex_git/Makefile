

NAME = pipex

SRC = pipex.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I.
LFLAGS = libft/libft.a

LDIR = libft/

all : $(NAME)

$(NAME) : 
	@make -C $(LDIR)
	gcc -c $(FLAGS) $(SRC) -I $(LDIR)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C $(LDIR)
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus

