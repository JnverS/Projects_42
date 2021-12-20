#include "../include/so_long.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("key: %d!\n", keycode);
// 	if (keycode == 124 || keycode == 2)
// 		vars->x+=150;
// 	else if (keycode == 126 || keycode == 13)
// 		vars->y-=150;
// 	else if (keycode == 123 || keycode == 0)
// 		vars->x-=150;
// 	else if (keycode == 125 || keycode == 1)
// 		vars->y+=150;
// 	return 0;
// }

int	render_next_frame(void *vars);

void open_map(char *argv)
{
	int fd;
	int read_byte;
	char buffer[2];
	char **map = NULL;
	char *tmp;
	int i = 0;
	

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error open file\n", 16);
		exit(EXIT_FAILURE);
	}
	read_byte = read(fd, buffer, 1);
	buffer[read_byte] = 0;
	while(read_byte > 0)
	{
		if (buffer[0] == '\n')
			i++;
		if (map)
		{
			tmp = ft_strjoin(map[i], buffer);
			free(map[i]);
			map[i] = ft_strdup(tmp);
			free(tmp);
		}
		else
		{
			map[i] = ft_strdup(buffer);
		}
		read_byte = read(fd, buffer, 1);
	}
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}



int	main(int argc, char **argv)
{
	//init
	t_display display;
	char	*relative_path = "./witchcraft.xpm";
	char	*relative_fon = "./fon.xpm";
	int		img_width = 1280;
	int		img_height = 720;
	
	open_map(argv[1]);

	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, 1280, 720, "So Long");
	// vars.fon = mlx_xpm_file_to_image(vars.mlx, relative_fon, &img_width, &img_height);
	// vars.player = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	//mlx_key_hook(display.win, key_hook, &display);
	//mlx_loop_hook(display.mlx, render_next_frame, &display);
	mlx_loop(display.mlx);
}

// int	render_next_frame(void *vars)
// {
// 	t_vars *var;
// 	int		img_width = 1280;
// 	int		img_height = 720;
// 	var = (t_vars*)vars;
// 	for (int i = 0;i < img_width; i+=150)
// 		for (int j = 0; j < img_height; j+=150)
// 		{
// 			mlx_put_image_to_window(var->mlx, var->win, var->fon, i, j);
// 		}
	
// 	mlx_put_image_to_window(var->mlx, var->win, var->player, var->x, var->y);
// 	return 0;
// }