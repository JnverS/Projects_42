/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:19:03 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:44 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = *stack_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack_a;
		*stack_a = tmp2;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = *stack_b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack_b;
		*stack_b = tmp2;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp = *stack_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack_a;
		*stack_a = tmp2;
		tmp = *stack_b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack_b;
		*stack_b = tmp2;
		write(1, "rrr\n", 4);
	}
}
