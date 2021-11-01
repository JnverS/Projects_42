/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:06:35 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:06:38 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	*str;
	int		res;

	res = 0;
	if (nb == 0)
	{
		res += ft_putchar_fd('0', 1);
		return (res);
	}
	str = ft_itoa(nb);
	res = ft_putstr_fd(str, 1);
	free(str);
	return (res);
}
