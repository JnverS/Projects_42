/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:18:57 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:07 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
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
		write(1, "sb\n", 3);
	}
	write(1, "ss\n", 3);
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
		write(1, "pb\n", 3);
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
		write(1, "pa\n", 3);
	}
}
