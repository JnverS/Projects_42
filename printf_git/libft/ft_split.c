/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:47:23 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/07 15:47:25 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_tab(char **result)
{
	int	i;

	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free (result);
	return (NULL);
}

static int	get_word_end(const char *str, char c, int i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	fill_result(char **result, const char *str, char c)
{
	int	i;
	int	word_end;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word_end = get_word_end(str, c, i);
			*result = ft_calloc(sizeof(**result), word_end - i + 1);
			if (!*result)
				return (0);
			ft_memcpy(*result, str + i, word_end - i);
			result++;
			i = word_end - 1;
		}
		i++;
	}
	return (1);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			nb_words++;
			while (str[i] && str[i] != c)
				i++;
		}
		i++;
	}
	return (nb_words);
}

char	**ft_split(const char *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	result = ft_calloc(sizeof(*result), count_words(str, c) + 1);
	if (!result)
		return (NULL);
	if (!fill_result(result, str, c))
		return (free_tab(result));
	return (result);
}
