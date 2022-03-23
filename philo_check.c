/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:17:12 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:17:23 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_checker(t_philo *philo)
{
	unsigned int	t;

	if (philo->tab->death != 0)
		return (1);
	t = get_time(philo->t_ref);
	if (t - philo->last_meal > philo->tab->time_to_die)
	{
		pthread_mutex_lock(&philo->tab->crayon);
		philo->tab->death++;
		if (philo->tab->death == 1)
			printf("%s%d %d died\n", RED, t, philo->id);
		pthread_mutex_unlock(&philo->tab->crayon);
		return (1);
	}
	else
		return (0);
}
		// i = 0;
		// while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
		// 	i++;
		// if (i == r->nb_philo)
		// 	r->all_ate = 1;

int	satisfaction_check(t_table *tab)
{
	int	i;

	i = 0;
	if (tab->q_meals != -2 && tab->philos[i].meals >= tab->q_meals - 1)
	{
		while (i < tab->q_philos)
		{
			if (tab->philos[i].meals < tab->q_meals)
				return (0);
			else
				i++;
		}
	}
	else
		return (0);
	pthread_mutex_lock(&tab->stylo);
	tab->death++;
	if (tab->death == 1)
		printf ("%sAll philosophers have eaten enough\n", YELLOW);
	usleep(100);
	pthread_mutex_unlock(&tab->stylo);
	return (1);
}

void	sleep_and_check(t_philo *philo, long t_action)
{
	unsigned int	t;

	t = get_time(philo->t_ref);
	while (dead_checker(philo) == 0)
	{
		if ((get_time(philo->t_ref) - t) >= t_action)
			break ;
		usleep(50);
	}
}
