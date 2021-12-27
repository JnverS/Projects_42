#include "../include/so_long.h"

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


void	check_elem(char *line, t_render *render, int curr_line)
{
	int i;

	i = 0;
	while (line[i] != '\0' )
	{
		if (line[i] == 'P')
		{
			render->map->player++;
			render->player->x = i;
			render->player->y = curr_line;
			render->map->arr[curr_line][i] = '0';
		}
		else if (line[i] == 'C')
		{
			render->map->coins++;
			render->coins[render->map->coins_number].disabled = 0;
			render->coins[render->map->coins_number].x = i;
			render->coins[render->map->coins_number++].y = curr_line;
			render->map->arr[curr_line][i] = '0';
		}
		else if (line[i] == 'E')
			render->map->exit++;
		else if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '0' && line[i] != '1')
			error(1);
		i++;
	}
}

void	valid_map(char *argv, t_render *render)
{
	int i;

	check_extension(argv);
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
	if (render->map->player == 0 || render->map->exit == 0 || render->map->coins == 0)
		error(1);
}