/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:53:05 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 15:55:20 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time_ms)
{
	long	time;

	time = current_time();
	while (current_time() < time + time_ms)
		usleep(100);
}

void	ft_print(int num, char *str, t_philo *philo)
{
	if (philo->stop != 1)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%ld ", current_time() - philo->data->start);
		printf("%d ", num);
		printf("%s", str);
		if (enough_dinner(&philo) == 0)
			pthread_mutex_unlock(&philo->data->write);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	res;

	res = 0;
	i = 0;
	z = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		z = -1;
	if (str[i] == '+' || z == -1)
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (z < 0 && res > 2147483647)
		return (-1);
	return (res);
}

void	ft_end_threads(t_philo *philo)
{
	int	nbr_ph;

	nbr_ph = philo->data->count_ph;
	if (nbr_ph == 1)
		pthread_mutex_unlock(&philo[0].l_fork);
	while (nbr_ph)
	{
		nbr_ph--;
		pthread_join(philo[nbr_ph].pthread_num, NULL);
	}
	nbr_ph = philo->data->count_ph;
	while (nbr_ph--)
	{
		pthread_mutex_unlock(&philo[nbr_ph].l_fork);
		pthread_mutex_destroy(&philo[nbr_ph].l_fork);
	}
	pthread_mutex_unlock(&(*philo->data).write);
	pthread_mutex_destroy(&(*philo->data).write);
	free(philo);
}
