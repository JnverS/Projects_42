/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:48:24 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 19:56:23 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

void	validation(int argc, char **argv);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	fnd_maxmin(t_list *stack_a, int *min_ind, int *max_ind);
int		give_flags(t_list **stack_a);
void	rotate_to_a(t_list **stack_a, t_list **stack_b, int max_ind);
void	rotate(t_list **stack_a, t_list **stack_b, int max);

void	clear_stack(t_list **stack);
int		ft_abs(int num);
void	sort_minimal_elem(t_list **stack_a);
void	fnd_min_index(t_list **stack_b);
void	sort_min_stack(t_list **stack_a, t_list **stack_b);
void	do_rotations(t_list **stack_a, t_list **stack_b, int a, int b);
void	do_solo_rotate(t_list **stack_a, t_list **stack_b, int a, int b);
t_list	*fnd_elem(t_list **stack_a, int index);
void	find_elem(t_list **stack_a, int size, int index);
t_list	*fnd_min_score(t_list **stack_b, int *count);
void	calc_score(t_list **stack_a, t_list **stack_b, int max_ind);
int		calc_score_a(t_list **stack_a, int index, int max_ind);
void	check_dub(t_list *stack_a);

#endif