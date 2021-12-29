#include "../../include/so_long_bonus.h"

void error(int num)
{
	if (num == 0)
		write(2, "Error: unable to open map\n", 27);
	if (num == 1)
		write(2, "Error: incorrect map\n", 21);
	if (num == 2)
		write(2, "Error: map should be rectangular!\n", 34);
	if (num == 3)
		write(2, "Error: wrong map extension!\n", 28);
	exit(EXIT_FAILURE);
}

void	clear_all(t_render *render)
{
	int	i;
	
	if (render)
	{
		if (render->map)
		{
			if (render->map->arr)
			{
				i = 0;
				while (render->map->arr[i])
				{
					free(render->map->arr[i]);
					render->map->arr[i] = NULL;
					i++;
				}
				free (render->map->arr);
			}
			free(render->map);
		}
		if (render->coins)
			free(render->coins);
		if (render->foe)
			free(render->foe);
	free(render);
	}
}

void end_game(t_display *display)
{
	write(1, "You WIN!\n", 9);
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
}

void game_over(t_display *display)
{
	write(1, "You LOOOOOOOSE :P\n", 18);
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
}

int	expose_hook(void *param)
{
	t_render *render;

	render = (t_render *) param;
	clear_all(render);
	exit(EXIT_SUCCESS);
}