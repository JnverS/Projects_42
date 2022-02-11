/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:53:05 by kdominic          #+#    #+#             */
/*   Updated: 2022/02/10 16:08:06 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	current_time(void)
{
	long			time;
	struct timeval	current;

	gettimeofday(&current, NULL);
	time = (size_t)current.tv_sec * 1000 + (size_t)current.tv_usec / 1000;
	return (time);
}

void	ft_usleep(int time_ms, t_philo *philo)
{
	long	time;

	time = current_time();
	check_dead(philo);
	while (philo->data->dead == 0)
	{
		if (current_time() - time > philo->data->time_to_die - 1)
			ft_print("is died\n", philo);
		if (current_time() - time >= time_ms)
			break ;
		usleep(50);
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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	tmp1;
	unsigned char	tmp2;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			tmp1 = (unsigned char) str1[i];
			tmp2 = (unsigned char) str2[i];
			return (tmp1 - tmp2);
		}
		i++;
	}
	return (0);
}

void	ft_print(char *str, t_philo *philo)
{
	sem_wait(philo->data->write);
	printf("%ld ", current_time() - philo->data->start);
	printf("%d ", philo->num_ph);
	printf("%s", str);
	if (!strcmp(str, "is dead\n"))
		sem_post(philo->data->stop);
	else
		sem_post(philo->data->write);
}
