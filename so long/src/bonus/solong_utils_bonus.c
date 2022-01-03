/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:09 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/30 14:12:17 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	error(int num)
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

void	clear_all(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->map)
		{
			if (game->map->arr)
			{
				i = 0;
				while (game->map->arr[i])
				{
					free(game->map->arr[i]);
					game->map->arr[i] = NULL;
					i++;
				}
				free (game->map->arr);
			}
			free(game->map);
		}
		if (game->coins)
			free(game->coins);
		if (game->foe)
			free(game->foe);
		free(game);
	}
}

void	end_game(t_display *display)
{
	write(1, "You WIN!\n", 9);
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
}

void	game_over(t_display *display)
{
	write(1, "You LOOOOOOOSE :P\n", 18);
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
}

int	expose_hook(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	clear_all(game);
	exit(EXIT_SUCCESS);
}
