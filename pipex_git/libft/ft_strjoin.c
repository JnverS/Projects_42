/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:10:20 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/06 16:10:21 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc((lens1 + lens2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	lens2 = 0;
	while (s2[lens2])
		str[i++] = s2[lens2++];
	str[i] = '\0';
	return (str);
}
