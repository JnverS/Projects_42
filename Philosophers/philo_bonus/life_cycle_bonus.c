/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:28:52 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 16:08:03 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	forks_and_eat(t_philo *philo)
{
	sem_wait(philo->data->fork_sem);
	ft_print("has taken a fork\n", philo);
	sem_wait(philo->data->fork_sem);
	ft_print("has taken a fork\n", philo);
	ft_print("is eating\n", philo);
	philo->t_last_eat = current_time();
	philo->numb_eat++;
	sem_post(philo->data->eat);
	ft_usleep(philo->data->time_to_eat, philo);
	sem_post(philo->data->fork_sem);
	sem_post(philo->data->fork_sem);
}

void	*life_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	stalker;

	philo = (t_philo *)arg;
	if (pthread_create(&stalker, NULL, &philo_died, philo))
	{
		printf("Error pthread");
		sem_post(philo->data->stop);
	}
	pthread_detach(stalker);
	while (philo->data->dead == 0)
	{
		if (philo->data->count_ph != 1)
		{
			forks_and_eat(philo);
			if (philo->data->num_eat > 0 && philo->numb_eat
				== philo->data->num_eat)
				break ;
			ft_print("is sleeping\n", philo);
			ft_usleep(philo->data->time_to_sleep, philo);
			ft_print("is thinking\n", philo);
		}
		check_dead(philo);
	}
	exit (EXIT_SUCCESS);
}
