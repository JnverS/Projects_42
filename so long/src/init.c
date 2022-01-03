/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:23 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 15:12:59 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_init(t_game *game, int i, int j)
{
	game->player->x = j;
	game->player->y = i;
	game->map->arr[i][j] = '0';
	game->player->isleft = 0;
}

void	coins_init(t_game *game, int i, int j)
{
	game->coins[game->map->coins_number].disabled = 0;
	game->coins[game->map->coins_number].x = j;
	game->coins[game->map->coins_number++].y = i;
	game->map->arr[i][j] = '0';
}

void	arr_to_struct(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coins = malloc (sizeof(t_coins) * game->map->coins);
	if (!game->coins)
	{
		perror("coins ");
		clear_all(game);
		exit(EXIT_FAILURE);
	}
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->column)
		{
			if (game->map->arr[i][j] == 'P')
				player_init(game, i, j);
			else if (game->map->arr[i][j] == 'C')
				coins_init(game, i, j);
			j++;
		}
		i++;
	}
}

void	display_init(t_game *game)
{
	int		img_width;
	int		img_height;

	game->display->mlx = mlx_init();
	game->display->win = mlx_new_window(game->display->mlx,
			(game->map->column + 1) * 51, game->map->lines * 51, "So Long");
	game->display->grass = mlx_xpm_file_to_image(game->display->mlx,
			BOT, &img_width, &img_height);
	game->display->player_img[0] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_L1, &img_width, &img_height);
	game->display->player_img[1] = mlx_xpm_file_to_image(game->display->mlx,
			PLAYER_R1, &img_width, &img_height);
	game->display->coin = mlx_xpm_file_to_image(game->display->mlx,
			COIN, &img_width, &img_height);
	game->display->wall = mlx_xpm_file_to_image(game->display->mlx,
			WALL, &img_width, &img_height);
	game->display->exit = mlx_xpm_file_to_image(game->display->mlx,
			EXIT, &img_width, &img_height);
}
