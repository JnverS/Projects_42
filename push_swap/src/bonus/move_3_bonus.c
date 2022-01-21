/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:19:03 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/21 15:28:52 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

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
	}
}
