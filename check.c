/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:10:56 by mpons             #+#    #+#             */
/*   Updated: 2022/03/18 15:32:31 by mpons            ###   ########.fr       */
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

int	err_m(char *e)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(e, 2);
	return (-1);
}

int	ft_check_and_atoi(const char *str)
{
	int		i;
	long	value;

	value = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			return (err_m("arguments must be >= 0"));
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (err_m("some arguments aren’t integers"));
		value *= 10;
		value += str[i] - '0';
		if (value >= MAX_INT)
			return (err_m("some arguments are out of range of integers"));
		i++;
	}
	return (value);
}
