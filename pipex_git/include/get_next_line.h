/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:06 by kdominic          #+#    #+#             */
/*   Updated: 2021/11/10 15:16:06 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

int		pos(const char *source, char fnd);
char	*get_next_line(int fd);

#endif
