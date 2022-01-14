/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:24 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/12 13:48:20 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list **stack_a)
{
	t_list *tmp = NULL;

	if(ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b)
{
	t_list *tmp = NULL;

	if(ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp = NULL;

	if(ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
	}
	write(1, "ss\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if(ft_lstsize(*stack_a) > 0)
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

	if(ft_lstsize(*stack_b) > 0)
	{
		tmp_a = (*stack_a);
		tmp_b = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = tmp_b;
		(*stack_a)->next = tmp_a;
		write(1, "pa\n", 3);
	}
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	if(ft_lstsize(*stack_a) > 1)
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

	if(ft_lstsize(*stack_b) > 1)
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

	if(ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
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

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if(ft_lstsize(*stack_a) > 1)
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

	if(ft_lstsize(*stack_b) > 1)
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

	if(ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
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