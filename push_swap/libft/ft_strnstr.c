/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:29:04 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 12:29:05 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	lensrc;
	size_t	i;

	if (!src[0])
		return ((char *)dest);
	i = 0;
	lensrc = ft_strlen((char *)src);
	while (dest[i] && n-- >= lensrc)
	{
		if (dest[i] == src[0] && ft_memcmp(&dest[i], src, lensrc) == 0)
			return ((char *)&dest[i]);
		i++;
	}
	return (NULL);
}
