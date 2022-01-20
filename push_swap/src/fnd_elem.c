/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnd_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:45:06 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 15:45:07 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*fnd_elem(t_list **stack_a, int index)
{
	t_list	*current;

	current = *stack_a;
	while (current->index != index)
		current = current->next;
	return (current);
}

void	find_elem(t_list **stack_a, int size, int index)
{
	int		i;
	t_list	*current;

	current = *stack_a;
	i = 0;
	while (current->index != index)
	{
		current = current->next;
		i++;
	}
	if (i > (size / 2))
		while (size - i++ > 0)
			rra(stack_a);
	else
		while (i-- > 0)
			ra(stack_a);
}
