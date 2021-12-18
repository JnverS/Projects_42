/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:05:59 by kdominic          #+#    #+#             */
/*   Updated: 2021/12/17 18:42:30 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"

char	*fnd_path(char *cmd, char **envp);
void	err(char *str);
void	ft_wrong_arg(void);
int		ft_open_file(char *argv, int i);
void	err(char *str);

#endif
