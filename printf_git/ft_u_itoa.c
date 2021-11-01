/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:07:11 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:07:13 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (2);
	while (n > 10)
	{
		n /= 10;
		size++;
	}
	size += 1;
	return (size);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*str;
	size_t	length;
	int		size;

	size = ft_size(n);
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	ft_strrev(str);
	return (str);
}
