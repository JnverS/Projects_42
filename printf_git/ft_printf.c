/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:05:21 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/23 13:10:09 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whatformat(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (format == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format == 'u')
		count += ft_putu(va_arg(ap, unsigned int));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (format == 'x')
		count += ft_puthex(va_arg(ap, unsigned int), 'x');
	else if (format == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), 'X');
	else if (format == 'p')
		count += ft_puthex(va_arg(ap, unsigned long), 'p');
	else if (format == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			count += ft_putchar_fd(format[i], 1);
			i++;
		}
		if (format[i] == '%')
		{
			count += ft_whatformat(format[i + 1], ap);
			i += 2;
		}
	}
	va_end(ap);
	return (count);
}
