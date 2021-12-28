NAME = so_long


SRC = main.c solong_utils.c solong_utils2.c solong_utils3.c init.c validation.c ft_itoa.c

SRC_B = so_long_bonus.c

SRCS = $(addprefix ./src/, $(SRC))

SRCS_B = $(addprefix ./src/, $(SRC_B))

OBJ = ${SRCS:.c=.o}

OBJ_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror -I../include/
LFLAGS = -L minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit

LDIR = minilibx_opengl_20191021/

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LDIR)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

# bonus : $(OBJ_B)
# 	@make -C $(LDIR)
# 	gcc $(OBJ_B) $(LFLAGS) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
