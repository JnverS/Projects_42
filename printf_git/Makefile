# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 13:07:24 by kdominic          #+#    #+#              #
#    Updated: 2021/10/23 13:07:26 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_putchar_fd.c \
		ft_putstr_fd.c ft_putnbr.c \
		ft_printf.c ft_puthex.c \
		ft_putu.c ft_u_itoa.c \

OBJ = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror -I.

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@make clean -C libft
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME) libft/libft.a

re : fclean all

.PHONY: all clean fclean re bonus

