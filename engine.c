/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/07/02 18:06:35 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	philo->is_eating = 1;
	printf("%ld : Philo %d is eating\n", ft_time(), philo->id);
	pthread_mutex_unlock(philo->display);
	philo->start_eat = ft_time();
	philo->past_time = ft_time();
	while (1)
	{
		usleep(500);
		if (ft_time() - philo->start_eat >= philo->eat)
			break ;
	}
	philo->meal_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	forking(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	printf("%ld : Philo %d has taken a fork\n", ft_time(), philo->id);
	printf("%ld : Philo %d has taken a fork\n", ft_time(), philo->id);
	pthread_mutex_unlock(philo->display);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	printf("%ld : Philo %d is sleeping\n", ft_time(), philo->id);
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
	printf("%ld : Philo %d is thinking\n", ft_time(), philo->id);
	pthread_mutex_unlock(philo->display);
}

void	dying(t_philo *philo, int i)
{
	pthread_mutex_lock(philo->display);
	printf("%ld : Philo %d died\n", ft_time(), i);
	ft_exit(philo);
}
