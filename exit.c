/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:52 by chly-huc          #+#    #+#             */
/*   Updated: 2021/06/30 22:11:11 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo)
	{
		while (i < philo[i].nbr)
		{
			if (philo[i].fork1)
			{
				free(philo[i].fork1);
				pthread_mutex_destroy(philo[i].fork1);
			}
			if (philo[i].display)
			{
				pthread_mutex_destroy(philo[i].display);
				free(philo[i].display);
			}
			i++;
		}
	}
	free(philo);
	exit(0);
}
