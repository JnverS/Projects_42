/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:11 by kdominic          #+#    #+#             */
/*   Updated: 2021/11/10 15:16:11 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	pos(const char *source, char fnd)
{
	int	i;

	i = 0;
	while (source[i])
	{
		if (source[i++] == fnd)
			return (i);
	}
	return (-1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = NULL;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*snew;
	unsigned int	i;
	size_t			lens;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (len > lens - start)
		len = lens - start;
	snew = NULL;
	snew = (char *)malloc((len + 1) * sizeof(char));
	if (!snew)
		return (NULL);
	*snew = '\0';
	if ((size_t)start >= lens)
		return (snew);
	while (i < len)
	{
		snew[i] = s[start];
		i++;
		start++;
	}
	snew[i] = '\0';
	return (snew);
}
