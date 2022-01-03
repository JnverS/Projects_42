/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:01 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 15:12:59 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	player_init(t_game *game, int i, int j)
{
	game->player->x = j;
	game->player->y = i;
	game->map->arr[i][j] = '0';
	game->player->isleft = 0;
}

void	foe_init(t_game *game, int i, int j)
{
	game->foe[game->map->foe_number].isleft = 0;
	game->foe[game->map->foe_number].disabled = 0;
	game->foe[game->map->foe_number].x = j;
	game->foe[game->map->foe_number++].y = i;
	game->map->arr[i][j] = '0';
}

void	coins_init(t_game *game, int i, int j)
{
	game->coins[game->map->coins_number].disabled = 0;
	game->coins[game->map->coins_number].x = j;
	game->coins[game->map->coins_number++].y = i;
	game->map->arr[i][j] = '0';
}

void	check_allocate(t_game *game)
{
	if (!game->coins)
	{
		perror("coins ");
		clear_all(game);
		exit(EXIT_FAILURE);
	}
	else if (!game->foe)
	{
		perror("foe ");
		clear_all(game);
		exit(EXIT_FAILURE);
	}
}

void	arr_to_struct(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coins = malloc (sizeof(t_coins) * game->map->coins);
	game->foe = malloc (sizeof(t_foe) * game->map->foe);
	check_allocate(game);
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->column)
		{
			if (game->map->arr[i][j] == 'P')
				player_init(game, i, j);
			else if (game->map->arr[i][j] == 'C')
				coins_init(game, i, j);
			else if (game->map->arr[i][j] == 'F')
				foe_init(game, i, j);
			j++;
		}
		i++;
	}
}
