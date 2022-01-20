/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:33:15 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:03:42 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= (-1);
	return (num);
}

void	clear_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	current = (*stack);
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	*stack = NULL;
}
