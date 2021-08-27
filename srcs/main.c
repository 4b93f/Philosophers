/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:26:08 by shyrno            #+#    #+#             */
/*   Updated: 2021/08/27 18:13:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*philo_engine(void *tmp)
{
	t_philo			*philo;
	struct timeval	ct;

	philo = tmp;
	while (1)
	{
		forking(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

static void	launch_philo(t_philo *philo, int i, pthread_t philo_th)
{
	while (i < philo->nbr)
	{
		pthread_create(&philo_th, NULL, philo_engine, (void *)&philo[i]);
		i += 2;
	}
	i = 1;
	while (i < philo->nbr)
	{
		pthread_create(&philo_th, NULL, philo_engine, (void *)&philo[i]);
		i += 2;
	}
	ft_time();
}

static void	init(int argc, char **argv, t_philo *philo)
{
	ft_init_info(philo, argv);
	ft_init_fork(philo, argv);
	ft_init_mutex(philo, argv);
	if (philo->max_eat == 0)
		ft_exit(0);
}

int	main(int argc, char **argv)
{
	int			i;
	void		*tmp;
	pthread_t	philo_th;
	pthread_t	philo_state_th;
	t_philo		*philo;

	if (!verif(argc, argv))
		return (0);
	i = 0;
	philo = malloc(sizeof(t_philo) * (ft_atoli(argv[1])));
	if (!philo)
		return (0);
	init(argc, argv, philo);
	launch_philo(philo, i, philo_th);
	pthread_create(&philo_state_th, NULL, philo_check, (void *)philo);
	pthread_join(philo_state_th, NULL);
	return (0);
}
