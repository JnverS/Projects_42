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
int		check_sort(t_list **stack_a, t_list *markup_head);
t_list	*fnd_elem(t_list **stack_a, int *r, int index);
void	rotate(t_list **stack_a, t_list **stack_b, int max);
void	rotate_to_a(t_list **stack_a, t_list **stack_b);
void	calc_score(t_list **stack_a, t_list **stack_b);


void	show_list(t_list **stack);


#endif