/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:18:57 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/21 15:28:32 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	sa(t_list **stack_a)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp_a = (*stack_a);
		tmp_b = (*stack_a)->next;
		(*stack_a) = tmp_b;
		tmp_a->next = (*stack_a)->next;
		(*stack_a)->next = tmp_a;
	}
}

void	sb(t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp_a = (*stack_b);
		tmp_b = (*stack_b)->next;
		(*stack_b) = tmp_b;
		tmp_a->next = (*stack_b)->next;
		(*stack_b)->next = tmp_a;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp_a = (*stack_a);
		tmp_b = (*stack_a)->next;
		(*stack_a) = tmp_b;
		tmp_a->next = (*stack_a)->next;
		(*stack_a)->next = tmp_a;
		tmp_a = (*stack_b);
		tmp_b = (*stack_b)->next;
		(*stack_b) = tmp_b;
		tmp_a->next = (*stack_b)->next;
		(*stack_b)->next = tmp_a;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_a) > 0)
	{
		tmp_a = (*stack_a);
		tmp_b = (*stack_b);
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = tmp_a;
		(*stack_b)->next = tmp_b;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b) > 0)
	{
		tmp_a = (*stack_a);
		tmp_b = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = tmp_b;
		(*stack_a)->next = tmp_a;
	}
}
