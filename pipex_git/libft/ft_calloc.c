/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:45:37 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 14:45:38 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
