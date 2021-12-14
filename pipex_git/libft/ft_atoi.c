/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:52:30 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 12:52:31 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	int				z;
	unsigned long	res;

	res = 0;
	i = 0;
	z = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		z = -1;
	if (str[i] == '+' || z == -1)
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (z == 0 && res > 9223372036854775807)
		return (-1);
	if (z == 0 && res <= 9223372036854775807)
		return ((int)res);
	if (z < 0 && res <= 9223372036854775807)
		return ((int)res * -1);
	else
		return (0);
}
