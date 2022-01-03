/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:06 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 15:12:59 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	render_foe(t_game *game)
{
	int		i;
	void	*img_foe;

	i = 0;
	while (i < game->map->foe)
	{
		img_foe = game->display->foe_img[
			0 + (game->display->tick++ / 100) % 3];
		mlx_put_image_to_window(game->display->mlx, game->display->win,
			img_foe, game->foe[i].x * 51, game->foe[i].y * 51);
		i++;
	}
	if ((game->display->tick) % 100 == 0)
		move_foe(game);
}

void	count_moves(char *str, t_game *game)
{
	mlx_string_put(game->display->mlx, game->display->win,
		(game->map->column + 1) * 51 - 100, 21, 16777215, "MOVES: ");
	mlx_string_put(game->display->mlx, game->display->win,
		(game->map->column + 1) * 51 - 50, 21, 16777215, str);
	free(str);
}

void	render_item(t_game *game)
{
	int		i;
	void	*img;
	char	*str;

	i = 0;
	str = ft_itoa(game->map->count_iter);
	while (i < game->map->coins)
	{
		if (game->coins[i].disabled == 0)
			mlx_put_image_to_window(game->display->mlx, game->display->win,
				game->display->coin, game->coins[i].x * 51,
				game->coins[i].y * 51);
		i++;
	}
	render_foe(game);
	img = game->display->player_img[game->player->isleft * 3
		+ (game->display->tick++ / 100) % 3];
	mlx_put_image_to_window(game->display->mlx, game->display->win,
		img, game->player->x * 51, game->player->y * 51);
	if (game->display->tick > 600)
		game->display->tick = 0;
	count_moves(str, game);
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
