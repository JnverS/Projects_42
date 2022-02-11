/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:25:51 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 15:35:41 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_dead(t_philo *philo)
{
	long	time;

	time = current_time();
	if (philo->t_last_eat == 0)
		philo->t_last_eat = current_time() - 1;
	if (philo->data->dead == 1)
		return ;
	if (time - philo->t_last_eat > philo->data->time_to_die)
	{
		ft_print("is dead\n", philo);
		philo->data->dead = 1;
	}
}

void	*philo_died(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
		check_dead(philo);
}

void	*enough_eating(void *arg)
{
	t_philo	*philo;
	int		max;

	philo = arg;
	max = 0;
	while (max < philo->data->num_eat * philo->data->count_ph)
	{
		sem_wait(philo->data->eat);
		if (philo->data->dead == 1)
			return (NULL);
		max++;
	}
	sem_post(philo->data->stop);
	return (0);
}
