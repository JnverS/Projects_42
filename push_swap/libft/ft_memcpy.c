/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:17:05 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/05 13:17:06 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
