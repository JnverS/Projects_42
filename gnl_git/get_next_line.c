/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:08 by kdominic          #+#    #+#             */
/*   Updated: 2021/11/10 15:16:08 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fnd_n(char **savedText)
{
	char	*tmp1;
	char	*tmp2;

	if (pos(*savedText, '\n') > 0)
	{
		tmp1 = ft_substr(*savedText, 0, pos(*savedText, '\n'));
		tmp2 = ft_substr(*savedText, pos(*savedText, '\n'),
				ft_strlen(*savedText));
		free(*savedText);
		if (ft_strlen(tmp2) == 0)
		{
			*savedText = NULL;
			free(tmp2);
		}
		else
			*savedText = tmp2;
		return (tmp1);
	}
	return (*savedText);
}

int	start_read(char **savedText, char *buffer, int fd)
{
	int		read_bytes;
	char	*tmp;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	if (read_bytes > 0)
	{
		if (*savedText)
		{
			tmp = ft_strjoin(*savedText, buffer);
			free(*savedText);
			*savedText = ft_strdup(tmp);
			free(tmp);
		}
		else
			*savedText = ft_strdup(buffer);
	}
	return (read_bytes);
}

char	*clean_mem(char **savedText, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*savedText, buffer);
	free(*savedText);
	*savedText = ft_strdup(tmp);
	free(tmp);
	return (*savedText);
}

char	*end_file(char **savedText)
{
	char	*tmp;

	if (pos(*savedText, '\n') > 0)
		return (fnd_n(savedText));
	tmp = ft_strdup(*savedText);
	free(*savedText);
	*savedText = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*savedText;
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = start_read(&savedText, buffer, fd);
	if (savedText)
	{
		while (read_bytes > 0)
		{
			if (pos(savedText, '\n') > 0)
				return (fnd_n(&savedText));
			else
			{
				read_bytes = read(fd, buffer, BUFFER_SIZE);
				if (read_bytes > 0)
				{
					buffer[read_bytes] = '\0';
					savedText = clean_mem(&savedText, buffer);
				}
			}
		}
		return (end_file(&savedText));
	}
	else
		return (NULL);
}
