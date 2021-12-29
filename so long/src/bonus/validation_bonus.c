#include "../../include/so_long_bonus.h"

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

void	check_first_last(char *line)
{
	int i;

	i = 0;
	while(line[i] != '\0')
	{
		if (line[i] != '1')
			error(1);
		i++;
	}
}

void	check_elem(char *line, t_render *render, int curr_line)
{
	int i;

	i = 0;
	while (line[i] != '\0' )
	{
		if (line[i] == 'P')
			render->map->player++;
		else if (line[i] == 'C')
			render->map->coins++;
		else if (line[i] == 'E')
			render->map->exit++;
		else if (line[i] == 'F')
			render->map->foe++;
		else if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '0' && line[i] != '1' && line[i] != 'F')
			error(1);
		i++;
	}
}

void	valid_map(char *argv, t_render *render)
{
	int i;

	i = 0;
	render->map->column = ft_strlen(render->map->arr[0]) - 1;
	while(render->map->arr[i])
	{
		if (i == 0)
			check_first_last(render->map->arr[i]);
		else if (i == render->map->lines)
			check_first_last(render->map->arr[i]);
		else
		{
			if (render->map->arr[i][0] != '1' || render->map->arr[i][render->map->column] != '1')
				error(1);
		}
		check_elem(render->map->arr[i], render, i);
		i++;
	}
	if (render->map->column == render->map->lines)
		error(2);
	if (render->map->player != 1 || render->map->exit == 0 || render->map->coins == 0 || render->map->foe == 0)
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
	if(r_b < 0)
		error(0);	
		
	buff[r_b] = 0;
	map->arr = ft_split(buff, '\n', map);
	close(fd);
}