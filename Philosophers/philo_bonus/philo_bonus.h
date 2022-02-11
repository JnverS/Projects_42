/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:59:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 15:28:19 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_data
{
	int			count_ph;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_eat;
	long int	start;
	int			dead;
	pthread_t	stalker;
	sem_t		*write;
	sem_t		*fork_sem;
	sem_t		*stop;
	sem_t		*eat;
}					t_data;

typedef struct s_philo
{
	int			num_ph;
	int			numb_eat;
	long int	t_last_eat;
	pid_t		pid_ph;
	t_data		*data;
}					t_philo;

int		check_arg(int argc, char **argv);
void	init_data(char **argv, t_data *data, int argc);
void	*philo_died(void *arg);
long	current_time(void);
void	init_philo(t_philo *philo, t_data *data);
void	*enough_eating(void *arg);
void	*life_philo(void *arg);
int		ft_atoi(const char *str);
void	ft_usleep(int time_ms, t_philo *philo);
void	check_dead(t_philo *philo);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_print(char *str, t_philo *philo);

#endif
