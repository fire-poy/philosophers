/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:38 by mpons             #+#    #+#             */
/*   Updated: 2022/03/02 20:38:28 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h> 
# include <stdlib.h> 
# include <unistd.h> 
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647

// terminal colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define DEFAULT "\033[0m"

// utils
int		ft_check_and_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	err_m(char *e);

// ARGS
typedef struct s_av
{
	int				q_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	q_meals;
}	t_av;

// TIME
typedef struct s_time
{
	long int		tv_sec;
	int				tv_usec;
	unsigned int	in_ms;
	unsigned int	ref;
}	t_time;

// philo avec son fork
typedef struct s_philo
{
	int	id;
	int status;//if status = what he's doing.
	int last_meal;
	int	meals;
	int fork; //true is available to use , 
	pthread_mutex_t mutex;
	// int	taken_forks;
}	t_philo;

// philo status
# define DEAD 0
# define THINKING 1
# define EATING 2
# define SLEEPING 3

typedef	struct s_table
{
	t_philo *philos;
	t_time	time;
	int		n_ph;
}	t_table;

unsigned int	get_time(t_time *time);
#endif

// 	pthread_mutex_t mutex;
// 	int	forkId;
// 	int status;//if status = true is availeble to use , 
// }	t_fork;
// void		smart_sleep(long long time, t_rules *rules)
// {
// 	long long i;

// 	i = timestamp();
// 	while (!(rules->dieded))
// 	{
// 		if (time_diff(i, timestamp()) >= time)
// 			break ;
// 		usleep(50);
// 	}
// }

/*
typedef struct s_mail
{
	pthread_mutex_t mutex;
	int mail;
}	t_mail;
*/
/*
int	gettimeofday(struct timeval *restrict tp, void *restrict tzp);

void	get_time_in_ms(t_time *time, unsigned int prog_start)
{
	gettimeofday((struct timeval *)time, NULL);
	time->timestamp_in_ms = (time->tv_sec * 1000 + time->tv_usec / 1000)
		- prog_start;
}
//PHILOS
int pthread_create
	(pthread_t *thread, //garde info du th,
	const pthread_attr_t *attr, //customisation if (NULL = default),
	void *(*start_routine)(void *), //routine, 
	void *arg); //arg passe au routine)

*/

//pthread_create(&th[i], NULL, function_ptr, table)
//
//int	pthread_mutex_init(pthread_mutex_t *mutex,const pthread_mutexattr_t *attr);
//int	pthread_mutex_destroy(pthread_mutex_t *mutex);

//FORKS
//int	pthread_mutex_lock(pthread_mutex_t *mutex);
//int	pthread_mutex_unlock(pthread_mutex_t *mutex);

	
//int	pthread_detach(pthread_t thread);
//
//int	pthread_join(pthread_t thread, void **value_ptr);
//t1, pointer that get the result, y
//"wait for threads"
