/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:31 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 19:24:41 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_dubl(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (i > j)
		{
			if (!ft_strcmp(argv[j], argv[i]) && i != j)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_dub(t_list *stack_a)
{
	t_list	*cur;
	t_list	*cur2;

	cur2 = stack_a;
	while (cur2->next != NULL)
	{
		cur = cur2->next;
		while (cur != NULL)
		{
			if (cur->content == cur2->content)
			{
				clear_stack(&stack_a);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			cur = cur->next;
		}
		cur2 = cur2->next;
	}
}

void	validation(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] != 0)
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	check_dubl(argv);
}
