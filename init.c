/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:00:25 by chly-huc          #+#    #+#             */
/*   Updated: 2021/07/02 18:03:14 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_info(t_philo *philo, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].nbr = ft_atoi(argv[1]);
		philo[i].die = ft_atoi(argv[2]);
		philo[i].eat = ft_atoi(argv[3]);
		philo[i].sleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].max_eat = ft_atoi(argv[5]);
		else
			philo[i].max_eat = -1;
		philo[i].id = i + 1;
		philo[i].past_time = 0;
		philo[i].start_sleep = 0;
		philo[i].start_eat = 0;
		philo[i].meal_count = 0;
		philo[i].is_eating = 0;
	}
}

void	ft_init_fork(t_philo *philo, char **argv)
{
	int				i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].fork1 = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].fork1)
			ft_exit(philo);
	}
}

void	ft_init_mutex(t_philo *philo, char **argv)
{
	int				i;
	pthread_mutex_t	*display;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(philo[i].fork1, NULL);
		if (i == (ft_atoi(argv[1]) - 1))
			philo[i].fork2 = philo[0].fork1;
		else
			philo[i].fork2 = philo[i + 1].fork1;
	}
	i = -1;
	display = malloc(sizeof(pthread_mutex_t));
	if (!display)
		ft_exit(philo);
	pthread_mutex_init(display, NULL);
	while (++i < ft_atoi(argv[1]))
		philo[i].display = display;
}
