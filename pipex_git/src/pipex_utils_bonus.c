/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:34:55 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/18 19:06:15 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	ft_wrong_arg(void)
{
	write(2, "Not enough arguments\n", 21);
	exit(EXIT_SUCCESS);
}

int	ft_open_file(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		fd = open(argv, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(argv, O_RDONLY);
	if (fd < 0)
		err("Can't open file\n");
	return (fd);
}
