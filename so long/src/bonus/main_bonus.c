#include "../../include/so_long_bonus.h"

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
	i = 0;
	while (i < render->map->foe_number)
    {
        if (render->player->x == render->foe[i].x && render->player->y == render->foe[i].y)
            game_over(render->display);
        i++;
    }
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
	printf("moves: %d\n", render->map->count_iter);
	if (render->map->arr[render->player->y][render->player->x] == 'E' && (render->map->coins == render->map->collect))
		end_game(render->display);
	return 0;
}

void	game_start(t_render *render, char *argv)
{
	read_to_arr(argv, render->map);
	valid_map(argv, render);
	arr_to_struct(render); 
	display_init(render);
	mlx_hook(render->display->win, 17, 1L<<0, expose_hook, render);
	mlx_key_hook(render->display->win, key_hook, render);
	mlx_loop_hook(render->display->mlx, render_next_frame, render);
	mlx_loop(render->display->mlx);
}

int	main(int argc, char **argv)
{
	t_render	*render;
	t_display	display;
	t_player	player;

	render = malloc(sizeof(t_render));
	if (!render)
	{
		perror("render ");
		clear_all(render);
		exit(EXIT_FAILURE);
	}
	render->map = malloc(sizeof(t_map));
	if (!render->map)
	{
		perror("map ");
		clear_all(render);
		exit(EXIT_FAILURE);
	}
	render->display = &display;
	render->player = &player;
	render->map->collect = 0;
	render->map->coins_number = 0;
	render->map->foe_number = 0;
	render->map->count_iter = 0;
	game_start(render, argv[1]);
}
