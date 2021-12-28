#include "../include/so_long.h"

void error(int num)
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

// void	clear_all(t_render *render)
// {
// 	int	i;
	
// 	if (render)
// 	{
// 		if (render->map)
// 		{
// 			if (render->map->arr)
// 			{
// 				i = 0;
// 				while (render->map->arr[i])
// 				{
// 					free(render->map->arr[i]);
// 					render->map->arr[i] = NULL;
// 					i++;
// 				}
// 				free (render->map->arr);
// 			}
// 			free(render->map);
// 		}
// 		if (render->coins)
// 			free(render->coins);
// 	free(render);
// 	}
// }