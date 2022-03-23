/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_and_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:53:13 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:14:48 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroyer(t_table *tab)
{
	int	i;

	i = -1;
	while (++i < tab->q_philos)
		pthread_mutex_destroy(&tab->philos[i].fork);
	pthread_mutex_destroy(&tab->stylo);
	pthread_mutex_destroy(&tab->crayon);
}

void	free_table(t_table *tab)
{
	free (tab->philos);
	tab->philos = NULL;
}

void	lonely_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (get_time(philo->t_ref) > philo->tab->time_to_die)
		{
			philo->tab->death++;
			printf("%s %ld %d died\n", RED, get_time(philo->t_ref), philo->id);
			return ;
		}
	}
}

int	philosophate(t_table *tab)
{
	int	i;

	if (tab->q_philos == 1)
		lonely_philo(tab->philos);
	i = -1;
	while (++i < tab->q_philos)
	{
		if (pthread_create(&tab->philos[i].th, NULL,
				philo_life, &tab->philos[i]))
			return (err_m("thread error"));
	}
	i = -1;
	while (++i < tab->q_philos)
	{
		if (pthread_join(tab->philos[i].th, NULL) != 0)
			return (err_m("pthread_join error"));
	}
	mutex_destroyer(tab);
	free_table(tab);
	return (0);
}
