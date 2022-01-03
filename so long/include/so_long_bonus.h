/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:10:03 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/03 19:08:18 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 4096
# define PLAYER_L0 "./img/witch_l0.xpm"
# define PLAYER_L1 "./img/witch_l1.xpm"
# define PLAYER_L2 "./img/witch_l2.xpm"
# define PLAYER_R0 "./img/witch_r0.xpm"
# define PLAYER_R1 "./img/witch_r1.xpm"
# define PLAYER_R2 "./img/witch_r2.xpm"
# define FOE0 "./img/foe0.xpm"
# define FOE1 "./img/foe1.xpm"
# define FOE2 "./img/foe2.xpm"
# define BOT "./img/grass.xpm"
# define WALL "./img/wall.xpm"
# define COIN "./img/coin.xpm"
# define EXIT "./img/boiler.xpm"
# define EXIT_WIN "./img/exit.xpm"

typedef struct s_map {
	char	**arr;
	int		column;
	int		lines;
	int		coins;
	int		coins_number;
	int		foe_number;
	int		count_iter;
	int		collect;
	int		exit;
	int		player;
	int		foe;
}				t_map;

typedef struct s_display {
	void	*mlx;
	void	*win;
	char	*grass;
	void	*player_img[6];
	void	*foe_img[3];
	char	*coin;
	char	*wall;
	char	*exit;
	int		tick;
}				t_display;

typedef struct s_obj {
	int	x;
	int	y;
	int	disabled;
	int	isleft;
}				t_player;

typedef struct s_coin {
	int	x;
	int	y;
	int	disabled;
	int	isleft;
}				t_coins;

typedef struct s_foe {
	int	x;
	int	y;
	int	disabled;
	int	isleft;
}				t_foe;

typedef struct s_game {
	t_display	*display;
	t_map		*map;
	t_player	*player;
	t_coins		*coins;
	t_foe		*foe;
}				t_game;

size_t	ft_strlen(const char *s);
void	error(int num);
void	valid_map(char *argv, t_game *game);
void	init_struct(t_game *game);
void	read_to_arr(char *argv, t_map *map);
void	arr_to_struct(t_game *game);
void	display_init(t_game *game);
void	check_extension(char *argv);
void	end_game(t_display *display);
void	game_over(t_display *display);
int		expose_hook(void *param);
void	render_item(t_game *game);
int		render_next_frame(void *rend);
void	check_collision(t_game *game, int i);
void	check_allocate(t_game *game);
void	move_foe(t_game *game);
void	check_len_str(char *buff);

char	**ft_split(const char *str, char c, t_map *map);
void	*ft_memcpy(void *dest, const void *s, size_t n);
void	*ft_calloc(unsigned numelem, size_t sizelem);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
void	clear_all(t_game *game);

#endif
