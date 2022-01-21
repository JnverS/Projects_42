/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:29:34 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/21 20:03:45 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_ind(t_list *pmin, t_list *pmax, int *max_ind, int *min_ind)
{
	if (pmin->index == -1)
		pmin->index = (*min_ind)++;
	if (pmax->index == -1)
		pmax->index = (*max_ind)--;
}

void	fnd_maxmin(t_list *stack_a, int *min_ind, int *max_ind)
{
	int		max;
	int		min;
	t_list	*pmax;
	t_list	*pmin;

	pmax = stack_a;
	pmin = stack_a;
	max = (int)(stack_a->content);
	min = (int)(stack_a->content);
	while (stack_a != NULL)
	{
		if ((int)stack_a->content < min && stack_a->index == -1)
		{
			min = (int)stack_a->content;
			pmin = stack_a;
		}
		else if ((int)stack_a->content > max && stack_a->index == -1)
		{
			max = (int)stack_a->content;
			pmax = stack_a;
		}
		stack_a = stack_a->next;
	}
	check_ind(pmin, pmax, max_ind, min_ind);
}

int	give_flags(t_list **stack_a)
{
	t_list	*current;
	t_list	*markup_head;
	int		i;

	i = 0;
	markup_head = *stack_a;
	current = (*stack_a)->next;
	markup_head->flag = 0;
	while (current != NULL)
	{
		if (current->index == markup_head->index + 1)
		{
			current->flag = 0;
			markup_head = current;
		}
		else
		{
			current->flag = 1;
			i++;
		}
		current = current->next;
	}
	return (i);
}

void	rotate(t_list **stack_a, t_list **stack_b, int max)
{
	t_list	*current;
	int		i;

	i = max + 1;
	current = *stack_a;
	while (i > 2)
	{
		if (current->index != 0 && current->index != max)
		{
			pb(stack_a, stack_b);
			if (current->index > max / 2)
				rb(stack_b);
			i--;
		}
		else
		{
			ra(stack_a);
		}
		current = *stack_a;
	}
}

void	rotate_to_a(t_list **stack_a, t_list **stack_b, int max_ind)
{
	int		i;
	int		b;
	t_list	*min_ind;
	int		count_b;
	int		a;

	i = 0;
	count_b = 0;
	while ((*stack_b) != NULL)
	{
		min_ind = fnd_min_score(stack_b, &count_b);
		a = calc_score_a(stack_a, min_ind->index, max_ind);
		if (count_b <= ft_lstsize(*stack_b) / 2)
			b = count_b;
		else
			b = count_b - ft_lstsize(*stack_b);
		do_rotations(stack_a, stack_b, a, b);
		pa(stack_a, stack_b);
		calc_score(stack_a, stack_b, max_ind);
	}
}
