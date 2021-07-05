/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:26:08 by shyrno            #+#    #+#             */
/*   Updated: 2021/07/05 16:36:12 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static void	init(int argc, char **argv, t_philo *philo)
{
	ft_init_info(philo, argv);
	ft_init_fork(philo, argv);
	ft_init_mutex(philo, argv);
	if (philo->max_eat == 0)
		ft_exit(0);
}

static void	*philo_check(void *tmp)
{
	int		i;
	int		j;
	int scan;
	int tm;
	t_philo	*philo;

	philo = tmp;
	i = 0;
	scan = philo[i].nbr;
	while (i < scan)
	{
		j = 0;
		tm = ft_time() - philo[i].past_time;
		if (tm > 0 && tm >= philo[i].die && !philo->is_eating)
		{
			//printf(" --- (%ld) --- #%lu# --- ~%d~ \n", ft_time(), philo[i].past_time, i);
			pthread_mutex_lock(philo->display);
			//printf("{%lu}\n", tm);
			//printf("{%ld}\n", philo[i].die);
			dying(philo, i + 1);
		}
		while (j <= scan && philo->max_eat > -1 && philo[i].meal_count
			>= philo[i].max_eat)
			j++;
		if (j >= scan)
			ft_exit(philo);
		if (i + 1 == scan)
			i = -1;
		i++;
	}
	return (NULL);
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
	i = -1;
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[1])));
	if (!philo)
		return (0);
	init(argc, argv, philo);
	ft_time();
	while (++i < philo->nbr)
		pthread_create(&philo_th, NULL, philo_engine, (void *)&philo[i]);
	pthread_create(&philo_state_th, NULL, philo_check, (void *)philo);
	pthread_join(philo_state_th, NULL);
	ft_exit(philo);
	return (0);
}
