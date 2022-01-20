/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:44:38 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:32:08 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	calc_score_a(t_list **stack_a, int index, int max_ind)
{
	t_list	*current;
	t_list	*max;
	int		j;

	current = *stack_a;
	max = fnd_elem(stack_a, max_ind);
	j = 0;
	while (current != NULL)
	{
		if (index < current->index)
			if (current->index < max->index)
				max = current;
		current = current->next;
	}
	current = *stack_a;
	while (current != max)
	{
		j++;
		current = current->next;
	}
	if (ft_lstsize(*stack_a) / 2 < j)
		j = j - ft_lstsize(*stack_a);
	return (j);
}

void	fin_score(t_list **current, int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			(*current)->score = ft_abs(a);
		else
			(*current)->score = ft_abs(b);
	}
	else
		(*current)->score = ft_abs(a) + ft_abs(b);
}

void	calc_score(t_list **stack_a, t_list **stack_b, int max_ind)
{
	t_list	*current;
	int		i;
	int		b;
	int		a;

	current = *stack_b;
	i = 0;
	while (current != NULL)
	{
		a = calc_score_a(stack_a, current->index, max_ind);
		if (i < ft_lstsize(*stack_b) / 2)
			b = i;
		else
			b = i - ft_lstsize(*stack_b);
		fin_score(&current, a, b);
		current = current->next;
		i++;
	}
}

t_list	*fnd_min_score(t_list **stack_b, int *count)
{
	t_list	*current;
	t_list	*min;

	min = *stack_b;
	current = (*stack_b)->next;
	*count = 0;
	while (current != NULL)
	{
		if (current->score < min->score)
			min = current;
		current = current->next;
	}
	current = *stack_b;
	while (current != NULL && current->index != min->index)
	{
		current = current->next;
		(*count)++;
	}
	return (current);
}
