/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:36:49 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/04 12:25:47 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	long	time;
	struct timeval	current;

	gettimeofday(&current, NULL);
	time = (size_t)current.tv_sec * 1000 + (size_t)current.tv_usec / 1000;
	return (time);
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

int	init_philo(t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	while (i < data->count_ph)
	{
		philo[i].num_ph = i + 1;
		philo[i].numb_eat = 0;
		philo[i].t_last_eat = 0;
		philo[i].r_fork = NULL;
		philo[i].stop = 0;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].l_fork, NULL);
		i++;
	}
	i =  0;
	while (i < data->count_ph)
	{
		if (i == data->count_ph - 1 || data->count_ph == 1)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
		i++;
	}
	data->philos = philo;
	return (1);
}

int	init_data(char **argv, t_data *data, int argc)
{
	if ((argc == 5 || argc == 6) && is_digit(argv))
	{
		data->count_ph = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->num_eat = -1;
		data->dead = 0;
		data->all_create = 0;
		pthread_mutex_init(&data->writing, NULL);
		if (argc == 6)
			data->num_eat = ft_atoi(argv[5]);
		if (data->count_ph <= 0 || data->time_to_die <= 0 || data->time_to_eat
			<= 0 || data->time_to_sleep <= 0)
			return (0);
		if (argc == 6 && data->num_eat < 0)
			return (0);
		return (1);
	}
	return (0);
}