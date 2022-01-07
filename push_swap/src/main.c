#include "../include/push_swap.h"

void	show_list(t_list **stack)
{
	t_list	*current;

	current = *stack;
	int k = 0;
	while (current != NULL)
	{
		printf("list: %d %d\n", k++, (int)(current->content));
		current = current->next;

	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list 	*new = NULL;
	long	content;
	int	status = 0;

	validation(argc, argv);
	i = argc - 1;
	while (i > 0)
	{
		content = ft_long_atoi(argv[i], &status);
		if (status)
			return(write(2, "Arg more that int!\n", 19));
		new = ft_lstnew((int *)content);
		ft_lstadd_front(&stack_a, new);
		i--;
	}
	show_list(&stack_a);
	printf("-------\n");
	// sa(&stack_a);
	pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// ra(&stack_a);
	// rb(&stack_b);
	// rr(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	show_list(&stack_a);
	printf("-------\n");
	show_list(&stack_b);

	return (0);
}