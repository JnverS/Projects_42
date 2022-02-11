# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:25:42 by kdominic          #+#    #+#              #
#    Updated: 2022/02/10 15:33:58 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_B = philo_bonus

INC_B = philo_bonus.h

SRCS_B = philo_bonus.c init_bonus.c \
		life_cycle_bonus.c philo_utils_bonus.c monitors_bonus.c

OBJ_B = ${SRCS_B:.c=.o}

FLAGS = -Wall -Wextra -Werror

.c.o:
	@gcc $(FLAGS) -I $(INC_B) -c $< -o $(<:.c=.o)

all : $(NAME_B)

bonus : $(NAME_B)

clean :
	@rm -f $(OBJ_B)

fclean : clean
	@rm -f $(NAME_B)

${NAME_B} : $(OBJ_B) $(INC_B)
	gcc -o $(NAME_B) $(OBJ_B)

re : fclean all

.PHONY: all clean fclean re bonus
