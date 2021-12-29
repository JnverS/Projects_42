#include "../include/so_long.h"

void	render_item(t_render *render)
{
	int 	i;

	i = 0;
	while (i < render->map->coins)
	{
		if(render->coins[i].disabled == 0)
			mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->coin, render->coins[i].x * 51, render->coins[i].y * 51);
		i++;
	}
	if (render->player->isLeft)
		mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->player_img[1], render->player->x * 51, render->player->y * 51);
	else
		mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->player_img[0], render->player->x * 51, render->player->y * 51);
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