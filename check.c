/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:10:56 by mpons             #+#    #+#             */
/*   Updated: 2022/03/01 18:16:28 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (c);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
	write(fd, "\n", 1);
}

void	err_m(char *e)
{
	char	*m1;

	m1 = "args: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]";
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(e, 2);
	ft_putendl_fd(m1, 2);
	ft_putstr_fd("number_of_times_each_philosopher_must_eat is ", 2);
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd("optional\n", 2);

	exit (1);
}

int ft_check_and_atoi(const char *str)
{
    int i;
    long value;

    value = 0;
    i = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i++] == '-')
			err_m("arguments must be >= 0");
    }
    while (str[i])
    {
		if (ft_isdigit(str[i]) == 0)
			err_m("some arguments aren’t integers");
        value *= 10;
        value += str[i] - '0';
		if (value >= MAX_INT)
			err_m("some arguments are out of range of integers");
        i++;
    }
    return (value);
}