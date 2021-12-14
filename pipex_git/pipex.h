#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*fnd_path(char *cmd, char **envp);

void	ft_wrong_arg(void);
int ft_open_file(char *argv, int i);
int	get_next_line(char **line);
void err(char *str);

#endif