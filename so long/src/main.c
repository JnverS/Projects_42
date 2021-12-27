#include "../include/so_long.h"

void end_game()
{
	printf("You WIN!\n");
	exit(EXIT_SUCCESS);
}



int	key_hook(int keycode, t_render *render)
{
	printf("key: %d!\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 124 || keycode == 2)// right
	{
		if (render->map->arr[render->player->y][render->player->x+1] == '1' ||
		 (render->map->arr[render->player->y][render->player->x+1] == 'E' && render->map->coins != render->map->collect))
			return 0;
		else
			render->player->x++;
	}
	else if (keycode == 126 || keycode == 13)
	{
		if (render->map->arr[render->player->y-1][render->player->x] == '1' ||
		 (render->map->arr[render->player->y-1][render->player->x] == 'E' && render->map->coins != render->map->collect))
			return 0;
		else
			render->player->y-=1;
	}
	else if (keycode == 123 || keycode == 0)
	{
		if (render->map->arr[render->player->y][render->player->x-1] == '1' ||
		 (render->map->arr[render->player->y][render->player->x-1] == 'E' && render->map->coins != render->map->collect))
			return 0;
		else
			render->player->x-=1;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (render->map->arr[render->player->y+1][render->player->x] == '1' ||
		 (render->map->arr[render->player->y+1][render->player->x] == 'E' && render->map->coins != render->map->collect))
			return 0;
		else
			render->player->y+=1;
	}

	for(int i =0; i< render->map->coins; i++)
		if (render->coins[i].x == render->player->x && render->coins[i].y == render->player->y && render->coins[i].disabled == 0)
		{
			render->map->collect++;
			render->coins[i].disabled = 1;
		}
		
	if (render->map->arr[render->player->y][render->player->x] == 'E' && (render->map->coins == render->map->collect))
	{
		end_game();
	}

	return 0;
}

int	render_next_frame(void *t_display);

int	main(int argc, char **argv)
{
	//init
	t_display	display;
	t_render	*render;
	t_player	player;
	int		img_width;
	int		img_height;
	void 	*struc;

	render = malloc(sizeof(t_render));

	render->display = &display;
	render->map = malloc(sizeof(t_map));
	render->player = &player;
	render->coins = malloc (sizeof(t_coins) * render->map->coins);

	init_struct(render);
	read_to_arr(argv[1], render->map);
	valid_map(argv[1], render);
	

	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, (render->map->column + 1)* 51, render->map->lines * 51, "So Long");
	display.grass = mlx_xpm_file_to_image(display.mlx, BOT, &img_width, &img_height);
	display.player_img = mlx_xpm_file_to_image(display.mlx, PLAYER, &img_width, &img_height);
	display.coin = mlx_xpm_file_to_image(display.mlx, COIN, &img_width, &img_height);
	display.wall = mlx_xpm_file_to_image(display.mlx, WALL, &img_width, &img_height);
	display.exit = mlx_xpm_file_to_image(display.mlx, EXIT, &img_width, &img_height);

	mlx_key_hook(display.win, key_hook, render);
	mlx_loop_hook(display.mlx, render_next_frame, render);
	mlx_loop(display.mlx);
}

int	render_next_frame(void *rend)
{
	int i;
	int j;
	t_render *render;
	render = (t_render*)rend;

	i = 0;
	while (i < render->map->lines)
	{
		j = 0;
		while (j <= render->map->column)
		{
			if (render->map->arr[i][j] == '1')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->wall, j * 51, i * 51);
			else if (render->map->arr[i][j] == 'E')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->exit, j * 51, i * 51);
			else
			 	mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->grass, j * 51, i * 51);
			j++;
		}
		i++;
	}

	for (size_t i = 0; i < render->map->coins; i++)
	{
		if(render->coins[i].disabled == 0)
			mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->coin, render->coins[i].x * 51, render->coins[i].y * 51);
	}
	mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->player_img, render->player->x * 51, render->player->y * 51);
	
	return 0;
}
