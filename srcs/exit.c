/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:49:52 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/22 18:22:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_exit(t_philo *philo)
{
	int	i;
	int	scan;

	i = 0;
	exit(0);
	scan = philo[i].nbr;
	if (philo)
	{
		free(philo[i].display);
		while (i < scan)
		{
			if (philo[i].fork1)
			{
				free(philo[i].fork1);
				pthread_mutex_destroy(philo[i].fork1);
			}
			if (philo[i].display)
				pthread_mutex_destroy(philo[i].display);
			i++;
		}
	}
	free(philo);
	exit(0);
}
