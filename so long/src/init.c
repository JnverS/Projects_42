#include "../include/so_long.h"

void	init_map_struct(t_map *map)
{
	map->column = 0;
	map->lines = 0;
	map->arr = NULL;
	map->coins = 0;
	map->player = 0;
	map->exit = 0;
}

void	map_to_arr(char *argv, t_map *map)
{
	char	*line;
	int		fd;
	int i;
	int j;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error(0);
	map->arr = (char **)malloc(map->column * map->lines * sizeof(char));
	if(!map)
		perror("Map: ");
	line = get_next_line(fd);
	i = 0;
	while(line)
	{
		map->arr[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->arr[i] = 0;
	close(fd);
}
