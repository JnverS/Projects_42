# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:55:30 by kdominic          #+#    #+#              #
#    Updated: 2021/12/18 19:05:38 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


SRC = pipex.c pipex_utils.c

SRC_B = pipex_bonus.c pipex_utils_bonus.c \
			pipex_utils.c get_next_line.c \
			get_next_line_utils.c

OBJ_DIR = ./obj

SRCS = $(addprefix ./src/, $(SRC))

SRCS_B = $(addprefix ./src/, $(SRC_B))

OBJ = ${SRCS:.c=.o}

OBJ_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror -I../include/
LFLAGS = -L libft/ -lft

LDIR = libft/

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LDIR)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@make fclean -C $(LDIR)
	@rm -f $(NAME) $(OBJ_B)

bonus : $(OBJ_B)
	@make -C $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus

