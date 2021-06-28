/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/28 02:40:11 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eating(t_philo *philo)
{
    philo->past_time = ft_time();
	printf("%ld ms : Philo %d is eating\n", philo->past_time , philo->id);
	usleep(philo->eat * 1000);
}

void forking(t_philo *philo)
{
    philo->past_time = ft_time();
    printf("%ld ms : Philo %d has taken a fork\n", philo->past_time , philo->id);
}

void sleeping(t_philo *philo)
{
    philo->past_time = ft_time();
    printf("%ld ms : Philo %d is sleeping\n", philo->past_time , philo->id);
	usleep(philo->sleep * 1000);
}

void thinking(t_philo *philo)
{
    philo->past_time = ft_time();
    printf("%ld ms : Philo %d is thinking\n", philo->past_time , philo->id);
}

void dying(t_philo *philo)
{
    philo->past_time = ft_time();
    printf("%ld ms : Philo %d died\n", philo->past_time , philo->id);
}