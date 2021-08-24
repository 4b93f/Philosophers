/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/08/24 18:46:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}

long    get_timestamp(long start_ts)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return (((tv.tv_sec * 1000) + tv.tv_usec / 1000) - start_ts);
}

void ft_usleep(int n)
{
    long start;
    long current;

    start = get_timestamp(0);
    current = start;
    while (n > current - start)
    {
        usleep(100);
        current = get_timestamp(0);
    }
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	philo->is_eating = 1;
	print(philo, " is eating\n");
	pthread_mutex_unlock(philo->display);
	philo->start_eat = ft_time();
	philo->past_time = ft_time();
	while (1)
	{
		usleep(500);
		if ((ft_time() - philo->start_eat) >= philo->eat)
		{
			philo->meal_count++;
			pthread_mutex_unlock(philo->fork1);
			pthread_mutex_unlock(philo->fork2);
			return ;
		}
	}
}

void	forking(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	print(philo, " has taken a fork\n");
	print(philo, " has taken a fork\n");
	pthread_mutex_unlock(philo->display);
}

void	sleeping(t_philo *philo)
{
	philo->is_eating = 0;
	pthread_mutex_lock(philo->display);
	print(philo, " is sleeping\n");
	pthread_mutex_unlock(philo->display);
	philo->start_sleep = ft_time();
	while (1)
	{
		usleep(500);
		if (ft_time() - philo->start_sleep >= philo->sleep)
			return ;
	}
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	print(philo, " is thinking\n");
	pthread_mutex_unlock(philo->display);
}

void	dying(t_philo *philo, int i)
{
	philo->id = i;
	print(philo, " is dead\n");
	ft_exit(philo);
}
