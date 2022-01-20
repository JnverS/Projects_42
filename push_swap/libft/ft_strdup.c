/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:35 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 15:03:37 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	int		len;

	len = 0;
	while (str[len])
		len++;
	s = (char *)malloc(len + 1 * sizeof(char));
	len = 0;
	if (!s)
		return (NULL);
	while (str[len])
	{
		s[len] = str[len];
		len++;
	}
	s[len] = '\0';
	return (s);
}
