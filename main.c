/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:57:06 by mpons             #+#    #+#             */
/*   Updated: 2022/03/02 20:39:15 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 number_of_philosophers 
// 2 time_to_die 
// 3 time_to_eat 
// 4 time_to_sleep 
// 5 [number_of_times_each_philosopher_must_eat]

// tv = time_value
unsigned int	get_time(t_time *t)
{
	gettimeofday((struct timeval *) t, NULL);
	if (t->ref == 0)
		t->ref = (t->in_ms = t->tv_sec * 1000 + t->tv_usec / 1000); 	
	t->in_ms = (t->tv_sec * 1000 + t->tv_usec / 1000) - t->ref; 	
	return (t->in_ms);
}

// - [] run program
// - [] philo seul, philos pair, philos impair
// - [] if death => stop ,free , return.

void	print_status(t_philo *philo, t_time *t)
{
	if (philo->status == 0)
		printf("%d %s philo %d is dead\n", get_time(t), RED, philo->id);
	if (philo->status == 1)
		printf("%d %s philo %d is thinking\n", get_time(t), CYAN, philo->id);
	if (philo->status == 2)
		printf("%d %s philo %d is eating\n", get_time(t), YELLOW, philo->id);
	if (philo->status == 3)
		printf("%d %s philo %d is sleeping\n", get_time(t), MAGENTA, philo->id);
}

t_philo *create_philos(int n, t_time *time)
{
	t_philo *philos;
	int		i;
	
	philos = malloc(n * sizeof(t_philo));
	i = -1;
	while (++i < n)
	{
		philos[i].id = i + 1;
		pthread_mutex_init (&philos[i].mutex, NULL); 
		philos[i].last_meal = get_time(time);
		philos[i].meals = 0;
		philos[i].status = THINKING;
		print_status(&philos[i], time);
	} 	
	return (philos);
}
void	get_args(int ac, char **av, t_av *args)
{
		args->q_philos = ft_check_and_atoi(av[1]);
		args->time_to_die = ft_check_and_atoi(av[2]);
		args->time_to_eat = ft_check_and_atoi(av[3]);
		args->time_to_sleep = ft_check_and_atoi(av[4]);
		if (ac == 6)
			args->q_meals = ft_check_and_atoi(av[5]);
		else
			args->q_meals = 0;		
}

void	philosophate(t_philo philos, t_time *t);
{
	if philos

	
}

int main(int ac, char** av)
{
	t_av	args;
	t_table table;
	
	if (ac == 5 || ac == 6)
		get_args(ac, av, &args);
	else 
		err_m("usage");
	table.time.ref = 0;
	printf("%sLa vie est belle, n'est pas?\n", GREEN);
	table.philos = create_philos(args.q_philos, &table.time);
	philosophate(&table);
	return (0); 
}
	// get_time(&t);

// -----------------------------------

	// while (t.in_ms < 10000)
	// {
	// 	get_time(&t);
	// 	printf("%s is thinking\n now %d\n", MAGENTA, t.in_ms);
	// 	usleep(1000000);
	// 	get_time(&t);
	// 	printf("%s is thinking\n now %d\n",  BLUE , t.in_ms);
	// }
