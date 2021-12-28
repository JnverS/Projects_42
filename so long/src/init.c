#include "../include/so_long.h"

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
	render->display->coin = mlx_xpm_file_to_image(render->display->mlx, COIN, &img_width, &img_height);
	render->display->wall = mlx_xpm_file_to_image(render->display->mlx, WALL, &img_width, &img_height);
	render->display->exit = mlx_xpm_file_to_image(render->display->mlx, EXIT, &img_width, &img_height);
}

void	check_extension(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] != '.')
		i++;
	i++;
	if(!(argv[i] == 'b' && argv[i+1] == 'e' && argv[i+2] == 'r' && argv[i+3] == '\0'))
		error(3);
}

void	read_to_arr(char *argv, t_map *map)
{
	char	*line;
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	int		r_b;

	check_extension(argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error(0);
	r_b = read(fd, buff, BUFFER_SIZE);
	if(r_b < 0)
		error(0);	
		
	buff[r_b] = 0;
	map->arr = ft_split(buff, '\n', map);
	close(fd);
}
