/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:33 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/30 13:16:34 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(unsigned numelem, size_t sizelem)
{
	unsigned char	*p;

	p = NULL;
	p = malloc(numelem * sizelem);
	if (!p)
		return (NULL);
	ft_bzero(p, numelem * sizelem);
	return (p);
}

void	*ft_memcpy(void *dest, const void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !s)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(s + i);
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
