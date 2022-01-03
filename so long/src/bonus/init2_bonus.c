/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:54:57 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 15:23:23 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	player_img(t_game *game)
{
	int		img_width;
	int		img_height;

	game->display->player_img[0] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_L0, &img_width, &img_height);
	game->display->player_img[1] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_L1, &img_width, &img_height);
	game->display->player_img[2] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_L2, &img_width, &img_height);
	game->display->player_img[3] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_R0, &img_width, &img_height);
	game->display->player_img[4] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_R1, &img_width, &img_height);
	game->display->player_img[5] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_R2, &img_width, &img_height);
}

void	display_init(t_game *game)
{
	int		img_width;
	int		img_height;

	game->display->mlx = mlx_init();
	game->display->win = mlx_new_window(game->display->mlx,
			(game->map->column + 1) * 51, game->map->lines * 51, "So Long");
	game->display->tick = 0;
	game->display->grass = mlx_xpm_file_to_image(game->display->mlx,
			BOT, &img_width, &img_height);
	game->display->foe_img[0] = mlx_xpm_file_to_image(game->display->mlx,
			FOE0, &img_width, &img_height);
	game->display->foe_img[1] = mlx_xpm_file_to_image(game->display->mlx,
			FOE1, &img_width, &img_height);
	game->display->foe_img[2] = mlx_xpm_file_to_image(game->display->mlx,
			FOE2, &img_width, &img_height);
	game->display->coin = mlx_xpm_file_to_image(game->display->mlx,
			COIN, &img_width, &img_height);
	game->display->wall = mlx_xpm_file_to_image(game->display->mlx,
			WALL, &img_width, &img_height);
	game->display->exit = mlx_xpm_file_to_image(game->display->mlx,
			EXIT, &img_width, &img_height);
	player_img(game);
}

void	move_foe(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->map->foe_number)
	{
		if (game->foe[i].isleft == 1)
		{
			if (game->map->arr[game->foe[i].y][game->foe[i].x - 1] == '1')
				game->foe[i].isleft = 0;
		}
		else
		{
			if (game->map->arr[game->foe[i].y][game->foe[i].x + 1] == '1')
				game->foe[i].isleft = 1;
		}
		if (game->foe[i].isleft)
			game->foe[i].x--;
		else
			game->foe[i].x++;
		check_collision(game, j);
		i++;
	}
}

void	check_len_str(char *buff)
{
	int	i;
	int	count;
	int	count2;

	i = 0;
	while (buff[i] != '\n')
		i++;
	count = i;
	while (buff[i])
	{
		count2 = 0;
		i++;
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			count2++;
			i++;
		}
		if (count2 != count)
			error(1);
	}
}
