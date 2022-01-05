#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;

	i = argc - 1;
	while (i > 0)
	{
		void *c = &argv[i];
		// printf("%s\n", argv[i]);
		if (!stack_a) {
			stack_a = ft_lstnew(c);//printf("hello\n");
			}
		else {
			ft_lstadd_front(&stack_a, c);
			// printf("hello2\n");
			}
		i--;
		// printf("%d hello3\n", i);
	}
	// printf("hello4\n");
	while (stack_a != NULL)
	{
		char *f = (char *)stack_a->content;
		printf("%c\n", *f);
		stack_a = stack_a->next;
	}
	return (0);
}