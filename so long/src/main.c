#include "../include/so_long.h"

int	key_hook(int keycode, t_display *display)
{
	printf("key: %d!\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	// if (keycode == 124 || keycode == 2)
	// 	vars->x+=150;
	// else if (keycode == 126 || keycode == 13)
	// 	vars->y-=150;
	// else if (keycode == 123 || keycode == 0)
	// 	vars->x-=150;
	// else if (keycode == 125 || keycode == 1)
	// 	vars->y+=150;
	return 0;
}

int	render_next_frame(void *t_display);

int	main(int argc, char **argv)
{
	//init
	t_display	display;
	t_map		map;
	char	*relative_path = "./witchcraft.xpm";
	char	*relative_fon = "./fon.xpm";
	int		img_width = 1280;
	int		img_height = 720;

	// map = (t_map *)malloc(sizeof(t_map));
	// if (!map)
	// 	perror("Map: ");
	init_map_struct(&map);
	open_map(argv[1], &map);
	map_to_arr(argv[1], &map);
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, map.column * 150, map.lines * 150, "So Long");
	display.fon = mlx_xpm_file_to_image(display.mlx, relative_fon, &img_width, &img_height);
	// vars.player = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_key_hook(display.win, key_hook, &display);
	mlx_loop_hook(display.mlx, render_next_frame, &display);
	mlx_loop(display.mlx);
}

int	render_next_frame(void *vars)
{
	t_display *display;

	display = (t_display*)vars;
	for (int i = 0;i < 13*150; i+=150)
		for (int j = 0; j < 5*150; j+=150)
		{
			mlx_put_image_to_window(display->mlx, display->win, display->fon, i, j);
		}
	// mlx_put_image_to_window(display->mlx, display->win, display->player, var->x, var->y);
	return 0;
}
