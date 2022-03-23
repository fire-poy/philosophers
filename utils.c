/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:48:05 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:15:38 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->tab->crayon);
	if (philo->tab->death == 0 && satisfaction_check(philo->tab) == 0)
		printf("%ld %d %s\n", get_time(philo->t_ref), philo->id, str);
	pthread_mutex_unlock(&philo->tab->crayon);
}

long	get_time(long *ref)
{
	struct timeval	t;
	long			t_in_ms;

	gettimeofday(&t, NULL);
	if (*ref == 0)
		*ref = (t.tv_sec * 1000 + t.tv_usec / 1000);
	t_in_ms = (t.tv_sec * 1000 + t.tv_usec / 1000) - *ref;
	return (t_in_ms);
}
