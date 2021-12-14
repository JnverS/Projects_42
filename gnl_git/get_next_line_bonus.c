/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:15:52 by kdominic          #+#    #+#             */
/*   Updated: 2021/11/10 15:15:52 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*savedText[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = start_read(&savedText[fd], buffer, fd);
	if (savedText[fd])
	{
		while (read_bytes > 0)
		{
			if (pos(savedText[fd], '\n') > 0)
				return (fnd_n(&savedText[fd]));
			else
			{
				read_bytes = read(fd, buffer, BUFFER_SIZE);
				if (read_bytes > 0)
				{
					buffer[read_bytes] = '\0';
					savedText[fd] = clean_mem(&savedText[fd], buffer);
				}
			}
		}
		return (end_file(&savedText[fd]));
	}
	else
		return (NULL);
}
