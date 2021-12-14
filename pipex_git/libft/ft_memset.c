/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:09:16 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/05 13:09:18 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = (unsigned char)c;
		i++;
	}
	return (dest);
}
