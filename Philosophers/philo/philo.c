/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:25:35 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 15:55:16 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taken_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	if (philo->stop != 1)
		ft_print(philo->num_ph, "has taken a fork\n", philo);
	pthread_mutex_lock(philo->r_fork);
	if (philo->stop != 1)
		ft_print(philo->num_ph, "has taken a fork\n", philo);
}

void	eating(t_philo *philo)
{
	ft_print(philo->num_ph, "is eating\n", philo);
	philo->numb_eat++;
	ft_usleep(philo->data->time_to_eat);
	philo->t_last_eat = current_time();
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	ft_print(philo->num_ph, "is sleeping\n", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	*start_game(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->t_last_eat = philo->data->start;
	philo->data->all_create++;
	if (philo->num_ph % 2 == 0)
		ft_usleep(50);
	while (!philo->data->died)
	{
		if (philo->data->died || philo->stop || enough_dinner(&philo))
			return (NULL);
		taken_forks(philo);
		if (philo->data->died || philo->stop || enough_dinner(&philo))
			return (NULL);
		eating(philo);
		if (philo->data->died || philo->stop || enough_dinner(&philo))
			return (NULL);
		sleeping(philo);
		if (philo->data->died || philo->stop || enough_dinner(&philo))
			return (NULL);
		ft_print(philo->num_ph, "is thinking\n", philo);
		if (philo->data->died || philo->stop || enough_dinner(&philo))
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	monitor;
	t_data		data;
	t_philo		*philo;
	int			i;

	if (!init_data(argv, &data, argc))
		return (write(1, "Error args\n", 11));
	philo = malloc(sizeof(t_philo) * data.count_ph);
	if (!philo)
		return (write(1, "Error malloc\n", 13));
	init_philo(philo, &data);
	data.start = current_time();
	i = 0;
	while (i < data.count_ph)
	{
		pthread_create(&philo[i].pthread_num, NULL, start_game, &philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitoring, (void *)philo);
	pthread_join(monitor, NULL);
	ft_end_threads(philo);
	return (0);
}
