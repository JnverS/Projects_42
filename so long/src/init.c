#include "../include/so_long.h"

void	player_init(t_render *render, int i, int j)
{
	render->player->x = j;
	render->player->y = i;
	render->map->arr[i][j] = '0';
	render->player->isLeft = 0;
}

void	coins_init(t_render *render, int i, int j)
{
	render->coins[render->map->coins_number].disabled = 0;
	render->coins[render->map->coins_number].x = j;
	render->coins[render->map->coins_number++].y = i;
	render->map->arr[i][j] = '0';
}

void arr_to_struct(t_render *render)
{
	int i;
	int j; 
	
	i = 0;
	render->coins = malloc (sizeof(t_coins) * render->map->coins);
	if (!render->coins)
	{
		perror("coins ");
		clear_all(render);
		exit(EXIT_FAILURE);
	}
	while(i < render->map->lines)
	{
		j = 0;
		while(j < render->map->column)
		{
			if (render->map->arr[i][j] == 'P')
				player_init(render, i, j);
			else if (render->map->arr[i][j] == 'C')
				coins_init(render, i, j);
			j++;
		}
		i++;
	}
}

void	display_init(t_render *render)
{
	int		img_width;
	int		img_height;

	render->display->mlx = mlx_init();
	render->display->win = mlx_new_window(render->display->mlx, (render->map->column + 1) * 51, render->map->lines * 51, "So Long");
	render->display->grass = mlx_xpm_file_to_image(render->display->mlx, BOT, &img_width, &img_height);
	render->display->player_img[0] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_L1, &img_width, &img_height);
	render->display->player_img[1] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_R1, &img_width, &img_height);
	render->display->coin = mlx_xpm_file_to_image(render->display->mlx, COIN, &img_width, &img_height);
	render->display->wall = mlx_xpm_file_to_image(render->display->mlx, WALL, &img_width, &img_height);
	render->display->exit = mlx_xpm_file_to_image(render->display->mlx, EXIT, &img_width, &img_height);
}