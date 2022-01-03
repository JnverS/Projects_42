/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:16:04 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 16:07:01 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	move(int x, int y, t_game*game)
{
	if (game->map->arr[game->player->y + y][game->player->x + x] == '1' ||
		(game->map->arr[game->player->y + y][game->player->x + x] == 'E'
		&& game->map->coins != game->map->collect))
		return ;
	else
	{
		game->player->x += x;
		game->player->y += y;
		game->map->count_iter++;
		printf("moves: %d\n", game->map->count_iter);
	}
}

void	check_collision(t_game *game, int i)
{
	int	img_width;
	int	img_height;

	while (i < game->map->coins)
	{
		if (game->coins[i].x == game->player->x && game->coins[i].y
			== game->player->y && game->coins[i].disabled == 0)
		{
			game->map->collect++;
			game->coins[i].disabled = 1;
			if (game->map->collect == game->map->coins)
				game->display->exit = mlx_xpm_file_to_image
					(game->display->mlx, EXIT_WIN, &img_width, &img_height);
		}
		i++;
	}
	i = 0;
	while (i < game->map->foe_number)
	{
		if (game->player->x == game->foe[i].x
			&& game->player->y == game->foe[i].y)
			game_over(game->display);
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 124 || keycode == 2)
	{
		game->player->isleft = 0;
		move(1, 0, game);
	}
	else if (keycode == 126 || keycode == 13)
		move(0, -1, game);
	else if (keycode == 123 || keycode == 0)
	{
		game->player->isleft = 1;
		move(-1, 0, game);
	}
	else if (keycode == 125 || keycode == 1)
		move(0, 1, game);
	check_collision(game, i);
	if (game->map->arr[game->player->y][game->player->x] == 'E'
			&& (game->map->coins == game->map->collect))
		end_game(game->display);
	return (0);
}

void	game_start(t_game *game, char *argv)
{
	game->map->coins = 0;
	game->map->foe = 0;
	game->map->player = 0;
	read_to_arr(argv, game->map);
	valid_map(argv, game);
	arr_to_struct(game);
	display_init(game);
	mlx_hook(game->display->win, 17, 1L << 0, expose_hook, game);
	mlx_hook(game->display->win, 2, 0, key_hook, game);
	mlx_loop_hook(game->display->mlx, render_next_frame, game);
	mlx_loop(game->display->mlx);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	t_display	display;
	t_player	player;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("game ");
		clear_all(game);
		exit(EXIT_FAILURE);
	}
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		perror("map ");
		clear_all(game);
		exit(EXIT_FAILURE);
	}
	game->display = &display;
	game->player = &player;
	game->map->collect = 0;
	game->map->coins_number = 0;
	game->map->foe_number = 0;
	game->map->count_iter = 0;
	game_start(game, argv[1]);
}
