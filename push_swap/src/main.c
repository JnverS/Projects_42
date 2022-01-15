/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/13 18:46:24 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	show_list(t_list **stack)
{
	t_list	*current;

	current = *stack;
	int k = 0;
	printf("\033[01;38;05;18;48;05;97m"" Index \t Elem \t Ind_s \t Flag \t Score ""\033[m\n");
	while (current != NULL)
	{
		printf("   %d\t  %d\t   %d\t  %d\t  %d\n", k++, (int)(current->content), current->index, current->flag, current->score);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list 	*new = NULL;
	int	status = 0;

	if (argc > 2)
	{
		validation(argc, argv);
		i = argc - 1;
		while (i > 0)
		{
			if (status)
				return(write(2, "Arg more that int!\n", 19));
			new = ft_lstnew((int *)ft_long_atoi(argv[i], &status));
			ft_lstadd_front(&stack_a, new);
			i--;
		}
		i = argc - 2;
		while (i >= status)
			fnd_maxmin(stack_a, &status, &i);
		new = fnd_elem(&stack_a, &i, 0);
		if (check_sort(&stack_a, new) == 0)
			return (write(1, "Stack is sorted!\n", 17));
		rotate(&stack_a, &stack_b, ft_lstsize(stack_a) - 1);
		calc_score(&stack_a, &stack_b);
		// while (ft_lstsize(stack_b) > 0)
		// {
			rotate_to_a(&stack_a, &stack_b);
		// }
		printf("\033[01;38;05;226m""--------------- stack_a ---------------""\033[m\n");
		show_list(&stack_a);
		printf("\033[01;38;05;46m""--------------- stack_b ---------------""\033[m\n");
		show_list(&stack_b);
	}
	return (0);
}