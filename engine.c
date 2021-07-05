/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/07/05 22:34:27 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	philo->is_eating = 1;
	printf("%ld ms : Philo %d is eating\n", ft_time(), philo->id);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(philo->id, 0);
	//write(1, " is eating\n", 11);
	pthread_mutex_unlock(philo->display);
	philo->start_eat = ft_time();
	philo->past_time = ft_time();
	while (1)
	{
		usleep(500);
		if ((ft_time() - philo->start_eat) >= philo->eat)
		{
			philo->past_time = ft_time();
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
	printf("%ld ms : Philo %d has taken a fork\n", ft_time(), philo->id);
	printf("%ld ms : Philo %d has taken a fork\n", ft_time(), philo->id);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(philo->id, 0);
	//write(1, " has taken a fork\n", 18);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(philo->id, 0);
	//write(1, " has taken a fork\n", 18);
	pthread_mutex_unlock(philo->display);
}

void	sleeping(t_philo *philo)
{
	philo->is_eating = 0;
	pthread_mutex_lock(philo->display);
	printf("%ld ms : Philo %d is sleeping\n", ft_time(), philo->id);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(philo->id, 0);
	//write(1, " is sleeping\n", 13);
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
	printf("%ld ms : Philo %d is thinking\n", ft_time(), philo->id);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(philo->id, 0);
	//write(1, " is thinking\n", 13);
	pthread_mutex_unlock(philo->display);
}

void	dying(t_philo *philo, int i)
{
	printf("%ld ms : Philo %d is dying\n", ft_time(), i);
	//(ft_time(), 0);
	//write(1, " : Philo ", 9);
	//(i, 0);
	//write(1, " is died\n", 9);
	ft_exit(philo);
}
