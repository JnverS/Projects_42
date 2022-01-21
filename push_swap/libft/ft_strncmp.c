/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:39:46 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/21 15:07:52 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	tmp1;
	unsigned char	tmp2;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			tmp1 = (unsigned char) str1[i];
			tmp2 = (unsigned char) str2[i];
			return (tmp1 - tmp2);
		}
		i++;
	}
	return (0);
}
