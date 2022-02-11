/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:47:08 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 16:04:49 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->start = current_time();
	while (i < philo->data->count_ph)
	{
		philo[i].pid_ph = fork();
		if (philo[i].pid_ph == -1)
		{
			while (--i >= 0)
				kill(philo[i].pid_ph, SIGKILL);
			exit (EXIT_FAILURE);
		}
		else if (philo[i].pid_ph == 0)
			life_philo(&(philo[i]));
		usleep(100);
		i++;
	}
	sem_wait(philo->data->stop);
}

static void	ft_kill_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->count_ph)
	{
		kill(philo[i].pid_ph, SIGKILL);
		i++;
	}
}

void	free_memory(t_philo *philo)
{
	sem_close(philo->data->fork_sem);
	sem_unlink("fork_sem");
	sem_close(philo->data->write);
	sem_unlink("write");
	sem_close(philo->data->stop);
	sem_unlink("stop");
	sem_close(philo->data->eat);
	sem_unlink("eat");
	free(philo);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philo;

	if (!check_arg(argc, argv))
		return (write(1, "Error args\n", 11));
	init_data(argv, &data, argc);
	philo = malloc(sizeof(t_philo) * data.count_ph);
	if (!philo)
		return (write(1, "Error malloc\n", 13));
	init_philo(philo, &data);
	if (argv[5])
	{
		if (pthread_create(&data.stalker, NULL, &enough_eating, philo))
			return (write(1, "Error pthread\n", 14));
	}
	start_philo(philo);
	philo->data->dead = 1;
	sem_post(philo->data->eat);
	ft_kill_philosophers(philo);
	if (argv[5])
		pthread_join(data.stalker, NULL);
	free_memory(philo);
	return (0);
}
