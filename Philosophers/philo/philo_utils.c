/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:53:05 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/04 13:03:03 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int	time_ms)
{
	long	time;

	time = current_time();
	while (current_time() < time + time_ms)
		usleep(100);
}

void	ft_print(int num, char *str, t_data *data)
{
	pthread_mutex_lock(&data->writing);
	printf("%ld ", current_time() - data->start);
	printf("%d ", num);
	printf("%s", str);
	if (enough_dinner(data->philos) == 0)
		pthread_mutex_unlock(&data->writing);
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

