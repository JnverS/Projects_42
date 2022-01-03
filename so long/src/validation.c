/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:39 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 19:01:33 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *argv)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = ft_strlen(argv) - 1;
	j = ft_strlen(ext) - 1;
	if (j > i)
		error(3);
	while (j >= 0)
	{
		if (argv[i--] != ext[j--])
			error(3);
	}
}

void	check_first_last(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error(1);
		i++;
	}
}

void	check_elem(char *line, t_game *game, int curr_line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' )
	{
		if (line[i] == 'P')
			game->map->player++;
		else if (line[i] == 'C')
			game->map->coins++;
		else if (line[i] == 'E')
			game->map->exit++;
		else if (line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != '0' && line[i] != '1')
			error(1);
		i++;
	}
}

void	valid_map(char *argv, t_game *game)
{
	int	i;

	i = 0;
	game->map->column = ft_strlen(game->map->arr[0]) - 1;
	while (game->map->arr[i])
	{
		if (i == 0)
			check_first_last(game->map->arr[i], game);
		else if (i == game->map->lines - 1)
			check_first_last(game->map->arr[i], game);
		else
		{
			if (game->map->arr[i][0] != '1'
				|| game->map->arr[i][game->map->column] != '1')
				error(1);
		}
		check_elem(game->map->arr[i], game, i);
		i++;
	}
	if (game->map->column == game->map->lines)
		error(2);
	if (game->map->player != 1 || game->map->exit == 0 || game->map->coins == 0)
		error(1);
	return ;
}

void	read_to_arr(char *argv, t_map *map)
{
	char	*line;
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	int		r_b;

	check_extension(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error(0);
	r_b = read(fd, buff, BUFFER_SIZE);
	if (r_b < 0)
		error(0);
	buff[r_b] = 0;
	check_len_str(buff);
	map->arr = ft_split(buff, '\n', map);
	close(fd);
}
