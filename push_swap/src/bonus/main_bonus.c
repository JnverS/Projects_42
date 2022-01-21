/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:25:03 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/21 20:09:09 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

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
		new = ft_lstnew((int *)ft_long_atoi(argv[count_elem], &status));
		ft_lstadd_front(stack_a, new);
		if (status)
		{
			clear_stack(stack_a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		count_elem--;
	}
	check_dub(*stack_a);
}

void	make_instr(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp("ra\n", line))
		ra(stack_a);
	else if (!ft_strcmp("rb\n", line))
		rb(stack_b);
	else if (!ft_strcmp("rr\n", line))
		rr(stack_a, stack_b);
	else if (!ft_strcmp("rra\n", line))
		rra(stack_a);
	else if (!ft_strcmp("rrb\n", line))
		rrb(stack_b);
	else if (!ft_strcmp("rrr\n", line))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp("sa\n", line))
		sa(stack_a);
	else if (!ft_strcmp("sb\n", line))
		sb(stack_b);
	else if (!ft_strcmp("ss\n", line))
		ss(stack_a, stack_b);
	else if (!ft_strcmp("pa\n", line))
		pa(stack_a, stack_b);
	else if (!ft_strcmp("pb\n", line))
		pb(stack_a, stack_b);
	else
		ft_error(stack_a, stack_b);
}

void	read_instr(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		make_instr(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	give_flags(t_list **stack_a)
{
	t_list	*current;
	t_list	*markup_head;
	int		i;

	if (!*stack_a)
		return (-1);
	i = 0;
	markup_head = *stack_a;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if ((int)current->content > (int)markup_head->content)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		validation(argc, argv);
		make_list(&stack_a, argc - 1, argv, argc - 2);
		read_instr(&stack_a, &stack_b);
		if (!give_flags(&stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clear_stack(&stack_a);
		clear_stack(&stack_b);
	}
	return (0);
}
