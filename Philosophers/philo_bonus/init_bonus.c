/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:28:06 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 15:33:21 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_ph)
	{
		philo[i].num_ph = i + 1;
		philo[i].data = data;
		philo[i].t_last_eat = 0;
		philo[i].numb_eat = 0;
		i++;
	}
}

int	init_semaphore(t_data *data)
{
	sem_unlink("write");
	sem_unlink("fork_sem");
	sem_unlink("stop");
	sem_unlink("eat");
	data->fork_sem = sem_open("fork_sem", O_CREAT | \
		O_EXCL, S_IRWXU, data->count_ph);
	data->write = sem_open("write", O_CREAT | O_EXCL, S_IRWXU, 1);
	data->stop = sem_open("stop", O_CREAT | O_EXCL, S_IRWXU, 0);
	data->eat = sem_open("eat", O_CREAT | O_EXCL, S_IRWXU, 0);
	return (0);
}

void	init_data(char **argv, t_data *data, int argc)
{
	data->count_ph = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start = current_time();
	data->num_eat = -1;
	data->dead = 0;
	if (argc == 6)
		data->num_eat = ft_atoi(argv[5]);
	init_semaphore(data);
}

int	is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	if ((argc == 5 || argc == 6) && is_digit(argv))
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3])
			<= 0 || ft_atoi(argv[4]) <= 0)
			return (0);
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			return (0);
		return (1);
	}
	return (0);
}
