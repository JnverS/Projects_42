#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

typedef struct	s_display {
	void	*mlx;
	void	*win;
}				t_display;

typedef struct  s_obj {
    char	frames[3];
    int     current_frame;
	int		x;
	int		y;
}               t_player, *t_coins, *t_enemy;

char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);

#endif