/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/20 19:20:50 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_list(t_list **stack_a, int count_elem, char **argv, int max_ind)
{
	int		status;
	t_list	*new;
	int		i;

	new = NULL;
	status = 0;
	i = 0;
	while (count_elem > 0)
	{
		if (status)
		{
			clear_stack(stack_a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		new = ft_lstnew((int *)ft_long_atoi(argv[count_elem], &status));
		ft_lstadd_front(stack_a, new);
		count_elem--;
	}
	check_dub(*stack_a);
	while (i <= max_ind)
		fnd_maxmin(*stack_a, &i, &max_ind);
}

void	full_sort(t_list **stack_a, t_list **stack_b, int max_ind)
{
	rotate(stack_a, stack_b, ft_lstsize(*stack_a) - 1);
	calc_score(stack_a, stack_b, max_ind);
	rotate_to_a(stack_a, stack_b, max_ind);
	find_elem(stack_a, ft_lstsize(*stack_a), 0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		status;
	t_list	*stack_a;
	t_list	*stack_b;

	status = 0;
	if (argc > 1)
	{
		validation(argc, argv);
		make_list(&stack_a, argc - 1, argv, argc - 2);
		if (ft_lstsize(stack_a) < 6)
			sort_min_stack(&stack_a, &stack_b);
		else
		{
			if (give_flags(&stack_a) == 0)
			{
				clear_stack(&stack_a);
				return (0);
			}
			find_elem(&stack_a, ft_lstsize(stack_a), 0);
			full_sort(&stack_a, &stack_b, argc - 2);
		}
		clear_stack(&stack_a);
	}
	return (0);
}
