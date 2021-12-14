# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:55:30 by kdominic          #+#    #+#              #
#    Updated: 2021/12/14 16:49:27 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c pipex_utils.c

SRC_B = pipex_bonus.c pipex_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

FLAGS = -Wall -Wextra -Werror -I.
LFLAGS = -L libft/ -lft

LDIR = libft/

all : $(NAME)

$(NAME) :
	@make -C $(LDIR)
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C $(LDIR)
	@rm -f $(NAME)

bonus :
	@make -C $(LDIR)
	gcc -c $(FLAGS) $(SRC_B) $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus

