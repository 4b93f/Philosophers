/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/08/27 18:12:09 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
