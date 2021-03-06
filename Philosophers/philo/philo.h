/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:21:20 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 16:01:08 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				num_ph;
	int				numb_eat;
	long int		t_last_eat;
	int				stop;
	pthread_t		pthread_num;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;
}						t_philo;

typedef struct s_data
{
	int				count_ph;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	int				died;
	int				all_create;
	long int		start;
	pthread_mutex_t	write;
	t_philo			*philos;
}						t_data;

int			ft_atoi(const char *str);
int			init_data(char **argv, t_data *data, int argc);
int			init_philo(t_philo *philo, t_data *data);
long int	current_time(void);
void		ft_print(int num, char *str, t_philo *philo);
void		ft_usleep(int time_ms);
int			enough_dinner(t_philo **philo);
void		philo_died(t_philo *philo, int i);
void		*monitoring(void *arg);
void		ft_end_threads(t_philo *philo);
#endif
