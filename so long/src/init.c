#include "../include/so_long.h"

void	init_struct(t_render *render)
{
	render->map->collect = 0;
	render->map->coins_number = 0;
}

void	read_to_arr(char *argv, t_map *map)
{
	char	*line;
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	int		r_b;
	int i = 0;
	int j;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error(0);
	r_b = read(fd, buff, BUFFER_SIZE);
	if(r_b < 0)
		error(0);	
	buff[r_b] = 0;
	map->arr = ft_split(buff, '\n', map);
	close(fd);
}
