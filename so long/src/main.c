#include "../include/so_long.h"

void end_game(t_display *display)
{
	printf("You WIN!\n");
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
}

int	expose_hook(void *param)
{
	// t_render *render;

	// render = (t_render *) param;
	// clear_all(render);
	exit(0);
}

void move(int x, int y, t_render* render)
{
	if (render->map->arr[render->player->y+y][render->player->x+x] == '1' ||
	 (render->map->arr[render->player->y+y][render->player->x+x] == 'E' && render->map->coins != render->map->collect))
		return;
	else
	{
		render->player->x+=x;
		render->player->y+=y;
		render->map->count_iter++;
	}
}

void	check_collision(t_render *render)
{
	int img_width;
	int img_height;
	int i;

	i = 0;
	while(i < render->map->coins)
	{
		if (render->coins[i].x == render->player->x && render->coins[i].y == render->player->y && render->coins[i].disabled == 0)
		{
			render->map->collect++;
			render->coins[i].disabled = 1;
			if (render->map->collect == render->map->coins)
				render->display->exit = mlx_xpm_file_to_image(render->display->mlx, EXIT_WIN, &img_width, &img_height);
		}
		i++;
	}
	if (render->map->arr[render->player->y][render->player->x] == 'E' && (render->map->coins == render->map->collect))
		end_game(render->display);
}

int	key_hook(int keycode, t_render *render)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 124 || keycode == 2)
	{
		render->player->isLeft = 0;
		move(1,0,render);
	}
	else if (keycode == 126 || keycode == 13)
		move(0,-1,render);
	else if (keycode == 123 || keycode == 0)
	{
		render->player->isLeft = 1;
		move(-1,0,render);
	}
	else if (keycode == 125 || keycode == 1)
		move(0,1,render);
	check_collision(render);
	return 0;
}

void	render_item(t_render *render)
{
	int 	i;
	void	*img;
	// char 	*str;

	i = 0;
	// str = ft_itoa(render->map->count_iter);
	while (i < render->map->coins)
	{
		if(render->coins[i].disabled == 0)
			mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->coin, render->coins[i].x * 51, render->coins[i].y * 51);
		i++;
	}
	img = render->display->player_img[ render->player->isLeft * 3 + (render->display->tick++ / 100 ) % 3 ];
	mlx_put_image_to_window(render->display->mlx, render->display->win, img, render->player->x * 51, render->player->y * 51);
	if(render->display->tick>600) 
		render->display->tick = 0;	
	mlx_string_put(render->display->mlx, render->display->win, (render->map->column + 1) * 51 - 100, 21, 16777215, "MOVES: ");
	mlx_string_put(render->display->mlx, render->display->win, (render->map->column + 1)* 51 - 50, 21, 16777215, ft_itoa(render->map->count_iter));
	//free(str);
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
			else if (render->map->arr[i][j] == '0' || render->map->arr[i][j] == 'E')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->grass, j * 51, i * 51);
			if (render->map->arr[i][j] == 'E')
			 	mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->exit, j * 51, i * 51);
			j++;
		}
		i++;
	}
	render_item(render);
	return 0;
}

// void	render_init(t_render *render)
// {
// 	t_display	display;
// 	t_player	player;

// 	render->map = malloc(sizeof(t_map));
// 	if (!render->map)
// 	{
// 		perror("map ");
// 		//clear_all(render);
// 		exit(EXIT_FAILURE);
// 	}
// 	render->display = &display;
// 	render->player = &player;
// 	render->map->collect = 0;
// 	render->map->coins_number = 0;
// 	render->map->count_iter = 0;
// }

int	main(int argc, char **argv)
{
	printf("shit0");
	t_render	*render;
	t_display	display;
	t_player	player;
	printf("shit");
	render = malloc(sizeof(t_render));
	// if (!render)
	// {
	// 	perror("render ");
	// 	//clear_all(render);
	// 	exit(EXIT_FAILURE);
	// }
	printf("shit1");
	render->map = malloc(sizeof(t_map));
	// if (!render->map)
	// {
	// 	perror("map ");
	// 	//clear_all(render);
	// 	exit(EXIT_FAILURE);
	// }
	printf("shit2");
	render->display = &display;
	render->player = &player;
	render->map->collect = 0;
	render->map->coins_number = 0;
	render->map->count_iter = 0;
	// render_init(render);
	printf("shit3");
	read_to_arr(argv[1], render->map);
	printf("shit4");
	valid_map(argv[1], render);
	printf("shit5");
	arr_to_struct(render); 
	printf("shit6");
	display_init(render);
	printf("shit7");
	mlx_hook(render->display->win, 17, 1L<<0, expose_hook, render);
	printf("shit8");
	mlx_key_hook(render->display->win, key_hook, render);
	printf("shit9");
	mlx_loop_hook(render->display->win, render_next_frame, render);
	mlx_loop(render->display->win);
}
