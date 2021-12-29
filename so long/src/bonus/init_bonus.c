#include "../../include/so_long_bonus.h"

void	player_init(t_render *render, int i, int j)
{
	render->player->x = j;
	render->player->y = i;
	render->map->arr[i][j] = '0';
	render->player->isLeft = 0;
}

void	foe_init(t_render *render, int i, int j)
{
	render->foe[render->map->foe_number].isLeft = 0;
	render->foe[render->map->foe_number].disabled = 0;
	render->foe[render->map->foe_number].x = j;
	render->foe[render->map->foe_number++].y = i;
	render->map->arr[i][j] = '0';
}

void	coins_init(t_render *render, int i, int j)
{
	render->coins[render->map->coins_number].disabled = 0;
	render->coins[render->map->coins_number].x = j;
	render->coins[render->map->coins_number++].y = i;
	render->map->arr[i][j] = '0';
}

void	check_allocate(t_render *render)
{
	if (!render->coins)
	{
		perror("coins ");
		clear_all(render);
		exit(EXIT_FAILURE);
	}
	else if (!render->foe)
	{
		perror("foe ");
		clear_all(render);
		exit(EXIT_FAILURE);
	}
}

void arr_to_struct(t_render *render)
{
	int i;
	int j; 
	
	i = 0;
	render->coins = malloc (sizeof(t_coins) * render->map->coins);
	render->foe = malloc (sizeof(t_foe) * render->map->foe);
	check_allocate(render);
	while(i < render->map->lines)
	{
		j = 0;
		while(j < render->map->column)
		{
			if (render->map->arr[i][j] == 'P')
				player_init(render, i, j);
			else if (render->map->arr[i][j] == 'C')
				coins_init(render, i, j);
			else if (render->map->arr[i][j] == 'F')
				foe_init(render, i, j);
			j++;
		}
		i++;
	}
}

