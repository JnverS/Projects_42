/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/18 18:09:39 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	show_list(t_list **stack)
{
	t_list	*current;

	current = *stack;
	// getchar();
	// system("clear");
	int k = 0;
	printf("\033[01;38;05;18;48;05;97m"" Index \t Elem \t Ind_s \t Flag \t Score ""\033[m\n");
	while (current != NULL)
	{
		printf("   %d\t  %d\t   %d\t  %d\t  %d\n", k++, (int)(current->content), current->index, current->flag, current->score);
		current = current->next;
	}
}

void	debug_print(t_list **stack_a, t_list **stack_b)
{
	// if (getchar() == 112)
	// 	pa(stack_a, stack_b);
	getchar();
	system("clear");
	printf("\033[04;38;05;76;48;05;232m"\
	"stack_a:                       \n""\033[m");
	show_list(stack_a);
	printf("\033[38;05;124;48;05;232m"\
	"stack_b:                       \n""\033[m");
	show_list(stack_b);
	write(1, "\033[38;05;226m", 13);
}

void	fnd_min_index(t_list **stack_b)
{
	int	i;
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

// void	start_rr(t_list **stack_a, t_list **stack_b, int *i, int *j)
// {
// 	// printf("%d %d\n", *i, *j);
// 	if (i > j)
// 	{
// 		while ((*j)-- > 0)
// 		{
// 			(*i)--;
// 			rr(stack_a, stack_b);
// 	// debug_print(stack_a, stack_b);
// 		}
// 	}
// 	else if (i < j)
// 	{
// 		while ((*i)-- > 0)
// 		{
// 			(*j)--;
// 			rr(stack_a, stack_b);
// 		}
// 	}
// }

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list 	*new = NULL;
	int	status = 0;
	int r = 0;

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
			markup(stack_a, &status, &i);
		// new = fnd_elem(&stack_a, &i, 0);
		// printf("%d\n", new->index);
		int k = check_sort(&stack_a, ft_lstsize(stack_a) - 1);
		// if (ft_lstsize(stack_a) < 6)
		// {
		// 	while (ft_lstsize(stack_a) > 3)
		// 	{
		// 		if (stack_a->index > 2)
		// 			pb(&stack_a, &stack_b);
		// 		else
		// 			ra(&stack_a);
		// 	}
		// 	sort_minimal_elem(&stack_a);
		// 	while (stack_b != NULL)
		// 	{
		// 		fnd_min_index(&stack_b);
		// 		// printf("%d", stack_b->index);
		// 		pa(&stack_a, &stack_b);
		// 		ra(&stack_a);
		// 	}
		// }
		// else
		// {
			rotate(&stack_a, &stack_b, ft_lstsize(stack_a) - 1, k);
			int a = find_elem(&stack_a, ft_lstsize(stack_a), 0);
			int b = find_elem_inb(&stack_b, ft_lstsize(stack_b), argc - 2);
			// printf("0 %d %d\n", a, b);
			if (a > ft_lstsize(stack_a)/2 && b > ft_lstsize(stack_b)/2)
			{
				// printf("1 %d %d\n", a, b);
				if (a > b)
				{
					r = b;
					while (r-- > 0)
						rrr(&stack_a, &stack_b);
				}
				else
				{
					r = a;
					while (r-- > 0)
						rrr(&stack_a, &stack_b);
				}
				if (a - r > 0)
					while (a - r++ > 0)
						ra(&stack_a);
				if (b - r > 0)
					while (b - r++ > 0)
						rb(&stack_b);
			}
			else if (a < ft_lstsize(stack_a)/2 && b < ft_lstsize(stack_b)/2)
			{
				// printf("2 %d %d\n", a, b);
				if (a > b)
					while (b-- > 0)
					{
						rr(&stack_a, &stack_b);
						a--;
					}
				else
					while (a-- > 0)
					{
						rr(&stack_a, &stack_b);
						b--;
					}
				while (a-- > 0)
					ra(&stack_a);
				while (b-- > 0)
					rb(&stack_b);
			}
			else
			{
				// printf("3 %d %d\n", a, b);
				if (a > (ft_lstsize(stack_a)/2))
					while (ft_lstsize(stack_a) - a++ >= 0)
					{
						rra(&stack_a);
						// a--;
					}
				else
					while (a-- > 0)
						ra(&stack_a);
				if (b > (ft_lstsize(stack_b)/2))
					while (ft_lstsize(stack_b) - b++ > 0)
					{
						// b--;
						rrb(&stack_b);
						// debug_print(&stack_a, &stack_b);
					}
				else
					while (b-- > 0)
						rb(&stack_b);
			}
			pa(&stack_a, &stack_b);
			calc_score(&stack_a, &stack_b);
			rotate_to_a(&stack_a, &stack_b);
			find_0_elem(&stack_a, ft_lstsize(stack_a), 0);
		// }
		// printf("\033[01;38;05;226m""--------------- stack_a ---------------""\033[m\n");
		// show_list(&stack_a);
		// printf("\033[01;38;05;46m""--------------- stack_b ---------------""\033[m\n");
		// show_list(&stack_b);
	}
	return (0);
}
