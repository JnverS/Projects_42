/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:41:11 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 16:00:30 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	enough_dinner(t_philo **philo)
{
	int	i;

	if ((*philo)->numb_eat != -1 && (*philo)->data->num_eat > 0)
	{
		i = 0;
		while (i < (*philo)->data->count_ph)
		{
			if ((*philo)[i].numb_eat < (*philo)->data->num_eat)
				return (0);
			i++;
		}
		i = 0;
		while (i < (*philo)->data->count_ph)
		{
			(*philo)[i].stop = 1;
			i++;
		}
		return (1);
	}
	return (0);
}

void	philo_died(t_philo *philo, int i)
{
	philo->data->died = 1;
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d %s\n", current_time() - philo->data->start, i, "died");
	i = 0;
	while (i < philo->data->count_ph)
	{
		philo[i].stop = 1;
		i++;
	}
}

void	*monitoring(void *arg)
{
	t_philo	*philo;
	long	time;
	int		i;

	philo = (t_philo *)arg;
	while (philo->data->all_create < philo->data->count_ph)
		usleep(50);
	while (philo[i].stop == 0)
	{
		i = 0;
		while (i < philo->data->count_ph)
		{
			time = current_time();
			if (philo[i].data->time_to_die < time - philo[i].t_last_eat)
			{
				philo_died(philo, philo[i].num_ph);
				pthread_mutex_unlock(&philo->data->write);
				return (NULL);
			}
			if (enough_dinner(&philo) || philo->stop)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
