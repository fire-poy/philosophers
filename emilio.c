/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:57:06 by mpons             #+#    #+#             */
/*   Updated: 2022/03/01 16:59:55 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	get_time_in_ms(t_time *time) 
{
	gettimeofday((struct timeval *)time, NULL);
	time->timestamp_in_ms = (time->tv_sec * 1000 + time->tv_usec / 1000);
    return ;
}
/*
*/
void	*routine(void *arg)
{
	t_mail	*Emilio;

	Emilio = (t_mail *)arg;
    for (int i = 0; i < 1000000; i++)
   	{
        pthread_mutex_lock(&Emilio->mutex);
        Emilio->mail++;
        pthread_mutex_unlock(&Emilio->mutex);
    }
	return (0);
}

// av = should take the following arguments: 
// number_of_philosophers 
// time_to_die 
// time_to_eat 
// time_to_sleep 
// [number_of_times_each_philosopher_must_eat]

int main()//int ac, char** av)
{
	t_mail Emilio;
    pthread_t th[8];
	t_time	time;
    int i;

	Emilio.mail = 0;
    pthread_mutex_init(&Emilio.mutex, NULL);
	i = -1;
	while (++i < 8)
   	{
        if (pthread_create(th + i, NULL, &routine, &Emilio) != 0)
	   	{
            perror("Failed to create thread");
            return 1;
        }
        printf("%s Thread %d has started\n", GREEN, i);
    }
	i = -1;
    while (++i < 8)
   	{
        if (pthread_join(th[i], NULL) != 0)
	   	{
            return 2;
        }
        printf("%s Thread %d has finished execution\n", RED, i);
    }
    pthread_mutex_destroy(&Emilio.mutex);
    printf("Number of mails: %d\n", Emilio.mail);
	get_time_in_ms(&time);
	time.prog_start = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (1)
	{
		get_time_in_ms(&time);
		printf("%s is thinking\n now %d\n", MAGENTA, time.timestamp_in_ms - time.prog_start);
		usleep(1000000);
		get_time_in_ms(&time);
		printf("%s is thinking\n now %d\n",  BLUE , time.timestamp_in_ms - time.prog_start);
	}
}

/*
int	main(int ac, char **av)
{
	t_args			args;
	t_time			time;
	t_philo			*philos;
	t_fork			*forks;
	t_table_infos	table;

	if (ac < 5 || ac > 6)
		return (usage());
	if (check_args(ac, av, &args) < 0)
		return (usage());
	gettimeofday((struct timeval *)&time, NULL);
	time.prog_start = time.tv_sec * 1000 + time.tv_usec / 1000;
	get_time_in_ms(&time, time.prog_start);
	printf("%d %sPROG START%s\n", time.timestamp_in_ms, GREEN, DEFAULT);
	philos = philos_create(args.n, &time);
	forks = forks_create(args.n);
	table.args = &args;
	table.time = &time;
	table.philos = philos;
	table.forks = forks;
	if (args.n == 1)
		return (one_philo_thread(&table));
	return (main_thread(&table, args.n));
}
*/
