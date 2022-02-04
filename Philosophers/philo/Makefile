# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:25:42 by kdominic          #+#    #+#              #
#    Updated: 2022/02/04 13:03:28 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

NAME_B = philo_bonus

INC = philo.h

INC_B = philo/philo_bonus.h

SRCS = philo.c life.c philo_utils.c make_list.c

SRCS_B = philo_bonus.c

OBJ = ${SRCS:.c=.o}

OBJ_B = ${SRCS_B:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC)

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME) $(NAME_B)

bonus : ${NAME_B}

${NAME_B} : $(OBJ_B) $(INC_B)
	gcc $(FLAGS) -o $(NAME_B) $(OBJ_B) -I $(INC_B)

re : fclean all

.PHONY: all clean fclean re bonus
