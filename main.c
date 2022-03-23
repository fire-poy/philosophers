/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:57:06 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:33:06 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(void)
{
	char	*m1;
	char	*m2;

	m1 = "args: number_of_philosophers time_to_die time_to_eat";
	m2 = "time_to_sleep [number_of_times_each_philosopher_must_eat]";
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(m1, 2);
	ft_putendl_fd(m2, 2);
	ft_putstr_fd("number_of_times_each_philosopher_must_eat is ", 2);
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd("optional\n", 2);
	return (-1);
}

int	get_args(int ac, char **av, t_table *tab)
{
	tab->q_philos = ft_check_and_atoi(av[1]);
	if (tab->q_philos == -1)
		return (-1);
	tab->time_to_die = ft_check_and_atoi(av[2]);
	if (tab->time_to_die == -1)
		return (-1);
	tab->time_to_eat = ft_check_and_atoi(av[3]);
	if (tab->time_to_eat == -1)
		return (-1);
	tab->time_to_sleep = ft_check_and_atoi(av[4]);
	if (tab->time_to_sleep == -1)
		return (-1);
	if (ac == 6)
		tab->q_meals = ft_check_and_atoi(av[5]);
	else
		tab->q_meals = -2;
	printf("coco");
	if (tab->q_meals == -1)
		return (-1);
	else
		return (1);
}

t_philo	*create_philos(t_table *tab)
{
	t_philo	*philos;
	int		i;

	philos = malloc(tab->q_philos * sizeof(t_philo));
	i = -1;
	while (++i < tab->q_philos)
	{
		philos[i].id = i + 1;
		if (i == tab->q_philos - 1)
			philos[i].next = 0;
		else
			philos[i].next = i + 1;
		philos[i].last_meal = 0;
		philos[i].meals = 0;
		philos[i].wait = 0;
		philos[i].tab = tab;
		philos[i].t_ref = &tab->t_ref;
		pthread_mutex_init (&philos[i].fork, NULL);
		printf("%d %d is thinking\n", 0, philos[i].id);
	}
	pthread_mutex_init(&tab->stylo, NULL);
	pthread_mutex_init(&tab->crayon, NULL);
	return (philos);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (get_args(ac, av, &table) == -1)
			return (-1);
	}
	else
	{
		usage();
		return (1);
	}
	table.t_ref = 0;
	table.death = 0;
	printf("%sLa vie est belle, n'est pas?\n", GREEN);
	table.philos = create_philos(&table);
	philosophate(&table);
	return (0);
}
