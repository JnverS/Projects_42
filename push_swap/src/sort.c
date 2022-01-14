/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:29:34 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/14 16:42:40 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (pmin->index == -1)
		pmin->index = (*min_ind)++;
	if (pmax->index == -1)
		pmax->index = (*max_ind)--;
}

t_list	*fnd_elem(t_list **stack_a, int *r, int index)
{
	t_list	*current;

	current = *stack_a;
	while (current->index != index)
	{
		current = current->next;
		(*r)++;
	}
	return(current);
}

// void	find_elem(t_list **stack_b, int size, int index)
// {
// 	int	i;
// 	t_list	*current;

// 	current = *stack_b;
// 	i = 0;
// 	while (current->index != index)
// 	{
// 		current = current->next;
// 		i++;
// 	}
// 	if (i > (size / 2))
// 		while (size - i++ > 0)
// 			rrb(stack_b);
// 	else
// 		while (i-- > 0)
// 			rb(stack_b);
// }

int	check_sort(t_list **stack_a, t_list *markup_head)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *stack_a;
	while (current != NULL)
	{
		if (current->index == markup_head->index + 1 || current->index == 0)
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
	int	 	i;

	printf("%d\n", max);
	i = max + 1;
	current = *stack_a;
	while (i > 3)
	{
		if (current->index != 0 && current->index != max / 2 && current->index != max)
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

int	calc_score_a(t_list **stack_a, int index)
{
	t_list	*current;
	int		i;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->index < index)
			i++;
		current = current->next;
	}
	if (ft_lstsize(*stack_a) / 2 < i)
		i = ft_lstsize(*stack_a) / 2;
	return (i);
}

void	calc_score(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int i;
	int max;

	current = *stack_b;
	max = ft_lstsize(*stack_b);
	i = 0;
	while(current != NULL)
	{
		if (i < max / 2)
		{	current->score = i++ + calc_score_a(stack_a, current->index);
			current = current->next;}
		else
		{
			if (i == max / 2)
			{
				current->score = i + calc_score_a(stack_a, current->index);
				current = current->next;
			}
			while (current != NULL)
			{
				current->score = i-- + calc_score_a(stack_a, current->index);
				current = current->next;
			}
		}
	}
}

void	rotate_to_a(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*current;

	current = *stack_b;
	while (i > 0)
	{
		if (current->flag == 1)
		{
			rb(stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
			i--;
		}
		current = *stack_b;
	}
}

