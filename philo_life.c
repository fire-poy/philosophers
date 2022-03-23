/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:31:46 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 14:57:54 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drope_forks(t_philo *philo);

int	take_forks(t_philo *philo)
{
	while (philo->wait == 1)
	{
		dead_checker(philo);
		usleep(50);
	}
	philo->wait = 1;
	while (philo->tab->philos[philo->next].wait == 1)
	{
		dead_checker(philo);
		usleep(50);
	}
	philo->tab->philos[philo->next].wait = 1;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&(philo->tab->philos[philo->next].fork));
	if (dead_checker(philo) == 1)
	{
		drope_forks(philo);
		return (1);
	}
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	return (0);
}

int	drope_forks(t_philo *philo)
{
	philo->wait = 0;
	philo->tab->philos[philo->next].wait = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&(philo->tab->philos[philo->next].fork));
	return (0);
}

int	start_to_eat(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->last_meal = get_time(philo->t_ref);
	philo->meals++;
	sleep_and_check(philo, philo->tab->time_to_eat);
	drope_forks(philo);
	if (satisfaction_check(philo->tab) == 1)
		return (1);
	return (0);
}

void	go_to_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_and_check(philo, philo->tab->time_to_sleep);
}

void	*philo_life(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (philo->tab->death == 0)
	{
		if (take_forks(philo))
			break ;
		if (start_to_eat(philo))
			break ;
		go_to_sleep(philo);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
