/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:19:00 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:15 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = ft_lstlast((*stack_a));
		tmp->next = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = ft_lstlast((*stack_b));
		tmp->next = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp = ft_lstlast((*stack_a));
		tmp->next = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next->next = NULL;
		tmp = ft_lstlast((*stack_b));
		tmp->next = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next->next = NULL;
		write(1, "rr\n", 3);
	}
}
