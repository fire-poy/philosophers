/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:38 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:14:22 by mpons            ###   ########.fr       */
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

// colors
# define MAX_INT 2147483647
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

// utils
int		ft_check_and_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		err_m(char *e);

typedef struct s_table	t_table;

typedef struct s_philo
{
	t_table			*tab;
	pthread_t		th;
	pthread_mutex_t	fork;
	int				id;
	int				next;
	int				last_meal;
	int				meals;
	long			*t_ref;
	int				wait;
}	t_philo;

struct s_table
{
	int				q_philos;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				q_meals;
	t_philo			*philos;
	pthread_mutex_t	stylo;
	pthread_mutex_t	crayon;
	int				death;
	long			t_ref;
};

long	get_time(long *ref);
void	print_status(t_philo *philo, char *str);
int		philosophate(t_table *tab);
void	*philo_life(void *arg);
void	sleep_and_check(t_philo *philo, long t_action);
int		dead_checker(t_philo *philo);
int		satisfaction_check(t_table *tab);

#endif
