/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:40:57 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/05 13:40:58 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *s, size_t n)
{
	char		*bufd;
	const char	*bufs;
	char		*lastd;
	const char	*lasts;

	if (!dest && !s)
		return (NULL);
	bufd = (char *)dest;
	bufs = (const char *)s;
	if (bufd < bufs)
	{
		while (n--)
			*bufd++ = *bufs++;
	}
	else
	{
		lasts = bufs + (n - 1);
		lastd = bufd + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
