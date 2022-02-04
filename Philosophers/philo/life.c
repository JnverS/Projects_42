#include "philo.h"

void    taking_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->l_fork);
    if (philo->stop != 1)
	    ft_print(philo->num_ph, "has taken a fork\n", philo->data);
	pthread_mutex_lock(philo->r_fork);
    if (philo->stop != 1)
	    ft_print(philo->num_ph, "has taken a fork\n", philo->data);
}

void	eating(t_philo *philo)
{
	ft_print(philo->num_ph, "is eating\n", philo->data);
	philo->numb_eat++;
	philo->t_last_eat = current_time();
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	ft_print(philo->num_ph, "is sleeping\n", philo->data);
		ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	ft_print(philo->num_ph, "is thinking\n", philo->data);
}