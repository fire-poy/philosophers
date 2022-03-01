/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:38 by mpons             #+#    #+#             */
/*   Updated: 2022/03/01 16:31:48 by mpons            ###   ########.fr       */
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

//terminal colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define DEFAULT "\033[0m"

//TIME
typedef struct s_time
{
	long int		tv_sec;
	int				tv_usec;
	unsigned int	timestamp_in_ms;
	unsigned int	prog_start;
}	t_time;

typedef struct s_mail
{
	pthread_mutex_t mutex;
	int mail;
}	t_mail;


typedef struct s_philo
{
	pthread_mutex_t mutex;
	int	philoId;
	int	fork_left;
	int	fork_right;
	int status;//if status = true is available to use , 
/*
0	dead
1	thinking
2	eating
3	sleeping
*/
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t mutex;
	int	forkId;
	int status;//if status = true is availeble to use , 
}	t_fork;
void	get_time_in_ms(t_time *time);
#endif
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
