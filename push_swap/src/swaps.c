/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:45:29 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 16:03:17 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_rotations(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rr(stack_a, stack_b);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		rrr(stack_a, stack_b);
		a++;
		b++;
	}
	do_solo_rotate(stack_a, stack_b, a, b);
}

void	do_solo_rotate(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (b < 0)
	{
		rrb(stack_b);
		b++;
	}
	while (b > 0)
	{
		rb(stack_b);
		b--;
	}
	while (a < 0)
	{
		rra(stack_a);
		a++;
	}
	while (a > 0)
	{
		ra(stack_a);
		a--;
	}
}
