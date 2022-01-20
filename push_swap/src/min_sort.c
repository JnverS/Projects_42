/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:45:16 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 18:20:55 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fnd_min_index(t_list **stack_b)
{
	int		i;
	t_list	*current;
	t_list	*min;

	current = *stack_b;
	min = *stack_b;
	i = 0;
	while (current != NULL)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	current = *stack_b;
	while (current->index != min->index && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (i > (ft_lstsize(*stack_b) / 2))
		while (ft_lstsize(*stack_b) - i++ > 0)
			rrb(stack_b);
	else
		while (i-- > 0)
			rb(stack_b);
}

void	sort_minimal_elem(t_list **stack_a)
{
	if ((*stack_a)->index == 2)
		ra(stack_a);
	if ((*stack_a)->index == 1)
	{
		if ((*stack_a)->next->index == 2)
			rra(stack_a);
		else
			sa(stack_a);
		return ;
	}
	if ((*stack_a)->next->index == 2)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	sort_min_stack(t_list **stack_a, t_list **stack_b)
{
	if (give_flags(stack_a) == 0)
	{
		clear_stack(stack_a);
		exit(EXIT_SUCCESS);
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_minimal_elem(stack_a);
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		if (*stack_b != NULL && (*stack_b)->index > (*stack_a)->index)
			ra(stack_a);
	}
	find_elem(stack_a, ft_lstsize(*stack_a), 0);
}
