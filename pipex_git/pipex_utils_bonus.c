/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:34:55 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/14 17:08:17 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_wrong_arg(void)
{
	write(2, "Not enough arguments\n", 21);
	exit(EXIT_SUCCESS);
}

int ft_open_file(char *argv, int i)
{
	int fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (i == 1)
		fd = open(argv, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(argv, O_RDONLY);
	if (fd < 0)
		err("Can't open file\n");
	return(fd);
}

int	get_next_line(char **line)
{
	int	l;
	int	read_byte;
	int	i;
	char 	*temp;
	char	c;

	i = -1;
	read_byte = 0;
	l = 1;
	if (!(*line = malloc(l)))
		return (-1);
	(*line)[0] = 0;
	while ((read_byte = read(0, &c, 1)) && l++ && c != '\n')
	{
		if (!(temp = malloc(l)))
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < l - 2)
			temp[i] = (*line)[i];
		temp[i] = c;
		temp[i + 1] = 0;
		free(*line);
		*line = temp;
	}
	return (read_byte);
}
