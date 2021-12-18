/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:27:18 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 11:27:19 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (ch > 256)
		ch -= 256;
	while (str[i])
	{
		if (str[i] == ch)
		{
			tmp = (char *)&str[i];
		}
		i++;
	}
	if ((ch == '\0' && str[i] == '\0'))
		tmp = (char *)&str[i];
	return (tmp);
}
