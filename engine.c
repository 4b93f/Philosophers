/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:27:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/26 18:14:24 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eating(t_philo *philo)
{
    philo->past_time = ft_time() - philo->start_time;
	printf("%ld : Philo %d is eating\n", philo->past_time , philo->id);
	usleep(philo->eat * 1000);
}

void forking(t_philo *philo)
{
    printf("Philo %d has taken a fork\n", philo->id);
}

void sleeping(t_philo *philo)
{
    printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->sleep * 1000);
}

void thinking(t_philo *philo)
{
    printf("Philo %d is thinking\n", philo->id);
}

void dying(t_philo *philo)
{
    printf("Philo %d died\n", philo->id);
}