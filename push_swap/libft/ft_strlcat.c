/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:26:11 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/05 17:26:12 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	size_t	start;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	start = lendst;
	if (n == 0)
		return (lensrc);
	while (i + lendst < n - 1 && src[i])
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	dst[start] = '\0';
	if (lendst > n)
		lendst = n;
	return (lendst + lensrc);
}
