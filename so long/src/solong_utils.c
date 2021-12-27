#include "../include/so_long.h"

void error(int num)
{
	if (num == 0)
		write(2, "Error: unable to open map\n", 27);
	if (num == 1)
		write(2, "Error: incorrect map\n", 21);
	if (num == 2)
		write(2, "Error: map should be rectangular!\n", 34);
	if (num == 3)
		write(2, "Error: wrong map extension!\n", 28);
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
