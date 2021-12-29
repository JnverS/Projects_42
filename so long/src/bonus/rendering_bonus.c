#include "../../include/so_long_bonus.h"

void	display_init(t_render *render)
{
	int		img_width;
	int		img_height;

	render->display->mlx = mlx_init();
	render->display->win = mlx_new_window(render->display->mlx, (render->map->column + 1) * 51, render->map->lines * 51, "So Long");
	render->display->tick = 0;
	render->display->grass = mlx_xpm_file_to_image(render->display->mlx, BOT, &img_width, &img_height);
	render->display->player_img[0] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_L0, &img_width, &img_height);
	render->display->player_img[1] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_L1, &img_width, &img_height);
	render->display->player_img[2] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_L2, &img_width, &img_height);
	render->display->player_img[3] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_R0, &img_width, &img_height);
	render->display->player_img[4] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_R1, &img_width, &img_height);
	render->display->player_img[5] = mlx_xpm_file_to_image(render->display->mlx, PLAYER_R2, &img_width, &img_height);
	render->display->foe_img[0] = mlx_xpm_file_to_image(render->display->mlx, FOE0, &img_width, &img_height);
	render->display->foe_img[1] = mlx_xpm_file_to_image(render->display->mlx, FOE1, &img_width, &img_height);
	render->display->foe_img[2] = mlx_xpm_file_to_image(render->display->mlx, FOE2, &img_width, &img_height);
	render->display->coin = mlx_xpm_file_to_image(render->display->mlx, COIN, &img_width, &img_height);
	render->display->wall = mlx_xpm_file_to_image(render->display->mlx, WALL, &img_width, &img_height);
	render->display->exit = mlx_xpm_file_to_image(render->display->mlx, EXIT, &img_width, &img_height);
}

void    move_foe(t_render *render)
{
    int i;

    i = 0;
    while(i < render->map->foe_number)
    {
        if(render->foe[i].isLeft == 1)
        {
            if(render->map->arr[render->foe[i].y][render->foe[i].x-1] == '1')
                render->foe[i].isLeft = 0;
        }
        else
        {
            if(render->map->arr[render->foe[i].y][render->foe[i].x+1] == '1')
                render->foe[i].isLeft = 1;
        }
        if(render->foe[i].isLeft)
            render->foe[i].x--;
        else
            render->foe[i].x++;
        check_collision(render);
        i++;
    }
}

void	render_foe(t_render *render)
{
	int 	i;
	void	*img_foe;

    i = 0;
    while (i < render->map->foe)
	{
	    img_foe = render->display->foe_img[ 0 + (render->display->tick++ / 100 ) % 3 ];
	    mlx_put_image_to_window(render->display->mlx, render->display->win, img_foe, render->foe[i].x * 51, render->foe[i].y * 51);
        i++;
	}
	if((render->display->tick) % 100 == 0)
		move_foe(render);
}

void	render_item(t_render *render)
{
	int 	i;
	void	*img;
	char 	*str;

	i = 0;
	str = ft_itoa(render->map->count_iter);
	while (i < render->map->coins)
	{
		if(render->coins[i].disabled == 0)
			mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->coin, render->coins[i].x * 51, render->coins[i].y * 51);
		i++;
	}
	render_foe(render);
	img = render->display->player_img[ render->player->isLeft * 3 + (render->display->tick++ / 100 ) % 3 ];
	mlx_put_image_to_window(render->display->mlx, render->display->win, img, render->player->x * 51, render->player->y * 51);
	if(render->display->tick > 600)
	    render->display->tick = 0;
	mlx_string_put(render->display->mlx, render->display->win, (render->map->column + 1) * 51 - 100, 21, 16777215, "MOVES: ");
	mlx_string_put(render->display->mlx, render->display->win, (render->map->column + 1)* 51 - 50, 21, 16777215, str);
	free(str);
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