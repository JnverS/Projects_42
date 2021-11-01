/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:07:01 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:07:05 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int nb)
{
	char	*str;
	int		res;

	res = 0;
	if (nb == 0)
	{
		res = ft_putchar_fd('0', 1);
		return (res);
	}
	nb = (unsigned int)(4294967295 + 1 + nb);
	str = ft_u_itoa(nb);
	res = ft_putstr_fd(str, 1);
	free(str);
	return (res);
}
