#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h>

# define BUFFER_SIZE 4096
# define PLAYER "./img/witch.xpm"
# define BOT "./img/grass.xpm"
# define WALL "./img/wall.xpm"
# define COIN "./img/coin.xpm"
# define EXIT "./img/boiler.xpm"

typedef struct	s_map {
	char	**arr;
	int		column;
	int		lines;
	int		coins;
	int 	coins_number;
	int 	collect;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_display {
	void	*mlx;
	void	*win;
	char 	**grass;
	char	**player_img;
	char	**coin;
	char	**wall;
	char	**exit;
}				t_display;

typedef struct  s_obj {
	char	frames[3];
	int		current_frame;
	int		x;
	int		y;
	int disabled;
}				t_player, t_coins, t_enemy;

typedef struct	s_render {
	t_display	*display;
	t_map		*map;
	t_player	*player;
	t_coins		*coins;
}				t_render;

size_t	ft_strlen(const char *s);
void	error(int num);
void	valid_map(char *argv, t_render *render);
void	init_struct(t_render *render);
void	read_to_arr(char *argv, t_map *map);

char	**ft_split(const char *str, char c, t_map *map);
void	*ft_memcpy(void *dest, const void *s, size_t n);
void	*ft_calloc(unsigned numelem, size_t sizelem);
void	ft_bzero(void *s, size_t n);

#endif
