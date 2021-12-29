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
		else if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '0' && line[i] != '1')
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
	if (render->map->player != 1 || render->map->exit == 0 || render->map->coins == 0)
		error(1);
	return ;
}

void arr_to_struct(t_render *render)
{
	int i;
	int j; 
	
	i = 0;
	render->coins = malloc (sizeof(t_coins) * render->map->coins);
	while(i < render->map->lines)
	{
		j = 0;
		while(j < render->map->column)
		{
			if (render->map->arr[i][j] == 'P')
			{
				render->player->x = j;
				render->player->y = i;
				render->map->arr[i][j] = '0';
				render->player->isLeft = 0;
			}
			else if (render->map->arr[i][j] == 'C')
			{
				render->coins[render->map->coins_number].disabled = 0;
				render->coins[render->map->coins_number].x = j;
				render->coins[render->map->coins_number++].y = i;
				render->map->arr[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}