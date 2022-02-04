/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:25:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/04 13:04:51 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	enough_dinner(t_philo *philo)
{
	int i;

	if (philo->numb_eat != -1 && philo->data->num_eat > 0)
	{
		i = 0;
		while (i < philo->data->count_ph)
		{
			if (philo[i].numb_eat < philo->data->num_eat)
				return (0);
			i++;
		}
		i = 0;
		while (i < philo->data->count_ph)
		{
			philo[i].stop = 1;
			i++;
		}
		return (1);
	}
	return (0);
}

void	philo_died(t_philo *philo, int i)
{
	philo->data->dead = 1;
	pthread_mutex_lock(&philo->data->writing);
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
	int 	i;

	philo = (t_philo *)arg;
	i = 0;
	while(philo->data->all_create < philo->data->count_ph)
		usleep(50);
	while (philo[i].stop == 0)
	{
		while (i < philo->data->count_ph)
		{
			time = current_time();
			if (philo[i].data->time_to_die < time - philo[i].t_last_eat)
			{
				philo_died(philo, philo[i].num_ph);
				pthread_mutex_unlock(&philo->data->writing);
				return (NULL);
			}
			if (enough_dinner(philo) || philo->stop)
				return (NULL);
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	*start_game(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->t_last_eat = philo->data->start;
	philo->data->all_create++;
	if (philo->num_ph % 2 == 0)
		ft_usleep(50);
	while (!philo->data->dead)
	{
		if (philo->data->dead || philo->stop || enough_dinner(philo))
			return (NULL);
		pthread_mutex_lock(&philo->l_fork);
		ft_print(philo->num_ph, "has taken a fork\n", philo->data);
		pthread_mutex_lock(philo->r_fork);
		ft_print(philo->num_ph, "has taken a fork\n", philo->data);
		if (philo->data->dead || philo->stop || enough_dinner(philo))
			return (NULL);
		ft_print(philo->num_ph, "is eating\n", philo->data);
		philo->numb_eat++;
		philo->t_last_eat = current_time();
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (philo->data->dead || philo->stop || enough_dinner(philo))
			return (NULL);
		ft_print(philo->num_ph, "is sleeping\n", philo->data);
		ft_usleep(philo->data->time_to_sleep);
		if (philo->data->dead || philo->stop || enough_dinner(philo))
			return (NULL);
		ft_print(philo->num_ph, "is thinking\n", philo->data);
		if (philo->data->dead || philo->stop || enough_dinner(philo))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	monitor;
	t_data data;
	t_philo *philo;
	int i;

	if (!init_data(argv, &data, argc))
		return(write(1, "Error args\n", 11));
	philo = malloc(sizeof(t_philo) * data.count_ph);
	if (!philo)
		return(write(1, "Error malloc\n", 13));
	init_philo(philo, &data);
	i = 0;
	philo->data->start = current_time();
	while (i < data.count_ph)
	{
		pthread_create(&philo[i].pthread_num, NULL, start_game, &philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitoring, (void *)philo);
	pthread_join(monitor, NULL);
	return (0);
}