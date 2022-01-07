#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int	arr_a[argc - 1];
	int	arr_b[argc - 1];

	i = 0;
	while (i < argc - 1)
	{
		arr_a[i] = ft_atoi(argv[i + 1]);
		printf("arr: %d %d\n", i, arr_a[i]);
		i++;
	}
	return (0);
}