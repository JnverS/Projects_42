/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:06:04 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:13:33 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrev(char *str)
{
	int		length;
	int		j;
	int		i;
	char	temp;

	length = 0;
	while (str[length] != '\0')
		length++;
	i = 0;
	j = length - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static void	ft_to_hex(unsigned long dec, char *hexadecimal, char type)
{
	int	rest;
	int	i;

	i = 0;
	if (dec == 0)
		hexadecimal[i++] = '0';
	while (dec != 0)
	{
		rest = (dec % 16);
		if (rest < 10)
			hexadecimal[i] = rest + 48;
		else if (type == 'X')
			hexadecimal[i] = rest + 55;
		else if (type == 'x' || type == 'p')
			hexadecimal[i] = rest + 87;
		dec = dec / 16;
		i++;
	}
	if (type == 'p')
	{
		hexadecimal[i++] = 'x';
		hexadecimal[i++] = '0';
	}
	hexadecimal[i] = '\0';
}

int	ft_puthex(unsigned long dec, char type)
{
	char	*hexadecimal;
	int		i;

	hexadecimal = (char *)malloc(sizeof(char) * 17);
	ft_to_hex(dec, hexadecimal, type);
	ft_strrev(hexadecimal);
	i = ft_putstr_fd(hexadecimal, 1);
	free(hexadecimal);
	return (i);
}
