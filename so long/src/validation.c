#include "../include/so_long.h"

void	check_first_last(char *line)
{
	int i;

	i = 0;
	while(line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			error(1);
		i++;
	}
}

void	check_extension(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] != '.')
		i++;
	i++;
	if(!(argv[i] == 'b' && argv[i+1] == 'e' && argv[i+2] == 'r' && argv[i+3] == '\0'))
		error(3);
}

void	check_elem(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0' )
	{
		if (line[i] == 'P')
			map->player++;
		else if (line[i] == 'C')
			map->coins++;
		else if (line[i] == 'E')
			map->exit++;
		else if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '0' && line[i] != '1')
			error(1);
		i++;
	}
}

void	open_map(char *argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error(0);
	check_extension(argv);
	line = get_next_line(fd);
	map->column = ft_strlen(line) - 1;
	while(line)
	{
		map->lines++;
		if (map->lines == 1)
			check_first_last(line);
		else if (line[map->column] == '\0')
			check_first_last(line);
		else
		{
			if (line[0] != '1' || line[map->column - 1] != '1')
			error(1);
		}
		check_elem(line, map);
		free(line);
		line = get_next_line(fd);
	}
	if (map->column == map->lines)
		error(2);
	if (map->player == 0 || map->exit == 0 || map->coins == 0)
		error(1);
	close(fd);
}