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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	tmp1;
	unsigned char	tmp2;

	i = 0;
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
		{
			tmp1 = (unsigned char) str1[i];
			tmp2 = (unsigned char) str2[i];
			return (tmp1 - tmp2);
		}
		i++;
	}
	if (i < n)
	{
		if (str1[i] != str2[i])
		{
			tmp1 = (unsigned char) str1[i];
			tmp2 = (unsigned char) str2[i];
			return (tmp1 - tmp2);
		}
	}
	return (0);
}
