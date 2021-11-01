/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:06:56 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:06:58 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	else
	{
		ft_putchar_fd('(', fd);
		ft_putchar_fd('n', fd);
		ft_putchar_fd('u', fd);
		ft_putchar_fd('l', fd);
		ft_putchar_fd('l', fd);
		ft_putchar_fd(')', fd);
		i = 6;
	}
	return (i);
}
