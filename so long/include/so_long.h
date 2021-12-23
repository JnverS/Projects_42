#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h>

typedef struct	s_map {
	char	**arr;
	int		column;
	int		lines;
	int		coins;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_display {
	void	*mlx;
	void	*win;
	char 	**fon;
	char	**player_img;
}				t_display;

typedef struct  s_obj {
	char	frames[3];
	int		current_frame;
	int		x;
	int		y;
}				t_player, *t_coins, *t_enemy;

char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*get_next_line(int fd);
void	error(int num);
void	open_map(char *argv, t_map *map);
void	init_map_struct(t_map *map);
void	map_to_arr(char *argv, t_map *map);

#endif
