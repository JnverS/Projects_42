/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:28 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 15:12:59 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_item(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->coins)
	{
		if (game->coins[i].disabled == 0)
			mlx_put_image_to_window(game->display->mlx, game->display->win,
				game->display->coin,
				game->coins[i].x * 51, game->coins[i].y * 51);
		i++;
	}
	if (game->player->isleft)
		mlx_put_image_to_window(game->display->mlx, game->display->win,
			game->display->player_img[1],
			game->player->x * 51, game->player->y * 51);
	else
		mlx_put_image_to_window(game->display->mlx, game->display->win,
			game->display->player_img[0],
			game->player->x * 51, game->player->y * 51);
}

void	render_map(t_game *game, int i, int j)
{
	if (game->map->arr[i][j] == '1')
		mlx_put_image_to_window(game->display->mlx,
			game->display->win, game->display->wall, j * 51, i * 51);
	else if (game->map->arr[i][j] == '0' || game->map->arr[i][j] == 'E')
		mlx_put_image_to_window(game->display->mlx,
			game->display->win, game->display->grass, j * 51, i * 51);
	if (game->map->arr[i][j] == 'E')
		mlx_put_image_to_window(game->display->mlx,
			game->display->win, game->display->exit, j * 51, i * 51);
}

int	render_next_frame(void *rend)
{
	int		i;
	int		j;
	t_game	*game;

	game = (t_game *)rend;
	i = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (j <= game->map->column)
		{
			render_map(game, i, j);
			j++;
		}
		i++;
	}
	render_item(game);
	return (0);
}
