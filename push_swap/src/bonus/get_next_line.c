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

#include "../../include/get_next_line.h"

char	*fnd_n(char **savedtext)
{
	char	*tmp1;
	char	*tmp2;

	if (pos(*savedtext, '\n') > 0)
	{
		tmp1 = ft_substr(*savedtext, 0, pos(*savedtext, '\n'));
		tmp2 = ft_substr(*savedtext, pos(*savedtext, '\n'),
				ft_strlen(*savedtext));
		free(*savedtext);
		if (ft_strlen(tmp2) == 0)
		{
			*savedtext = NULL;
			free(tmp2);
		}
		else
			*savedtext = tmp2;
		return (tmp1);
	}
	return (*savedtext);
}

int	start_read(char **savedtext, char *buffer, int fd)
{
	int		read_bytes;
	char	*tmp;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	if (read_bytes > 0)
	{
		if (*savedtext)
		{
			tmp = ft_strjoin(*savedtext, buffer);
			free(*savedtext);
			*savedtext = ft_strdup(tmp);
			free(tmp);
		}
		else
			*savedtext = ft_strdup(buffer);
	}
	return (read_bytes);
}

char	*clean_mem(char **savedtext, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*savedtext, buffer);
	free(*savedtext);
	*savedtext = ft_strdup(tmp);
	free(tmp);
	return (*savedtext);
}

char	*end_file(char **savedtext)
{
	char	*tmp;

	if (pos(*savedtext, '\n') > 0)
		return (fnd_n(savedtext));
	tmp = ft_strdup(*savedtext);
	free(*savedtext);
	*savedtext = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*savedtext;
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = start_read(&savedtext, buffer, fd);
	if (savedtext)
	{
		while (read_bytes > 0)
		{
			if (pos(savedtext, '\n') > 0)
				return (fnd_n(&savedtext));
			else
			{
				read_bytes = read(fd, buffer, BUFFER_SIZE);
				if (read_bytes > 0)
				{
					buffer[read_bytes] = '\0';
					savedtext = clean_mem(&savedtext, buffer);
				}
			}
		}
		return (end_file(&savedtext));
	}
	else
		return (NULL);
}
