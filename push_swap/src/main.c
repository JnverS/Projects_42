#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a = NULL;

	i = argc - 1;
	while (i > 0)
	{
		void *c = argv[i];
		// printf("%s\n", argv[i]);
		if (!stack_a) {
			stack_a = ft_lstnew(c);//printf("hello\n");
			}
		else {
			t_list *new = ft_lstnew(c);
			ft_lstadd_front(&stack_a, new);
			printf("elem was added successfully : %s\n", new->content);
			}
		i--;
		// printf("%d :\n", i);
	}
	// printf("hello4\n");
	t_list* current = stack_a;
	int k = 0;
	while (current != NULL)
	{
		printf("%d %s\n", k++, (char *)(current->content));
		current = current->next;

	}
	return (0);
}