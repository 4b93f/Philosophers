/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:52:36 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/27 18:14:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned long	ft_time(void)
{
	unsigned long			time;
	static unsigned long	tm;
	struct timeval			ct;

	gettimeofday(&ct, NULL);
	time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
	if (!tm)
		tm = time;
	return (time - tm);
}

int	str_isnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0') && !(str[i] <= '9'))
			return (0);
	}
	return (1);
}

void	print(t_philo *philo, char *s1)
{
	char	*id;

	id = ft_itoa(philo->id);
	philo->output = ft_strjoinfree(ft_itoa(ft_time()), " ");
	philo->output = ft_strjoinfree(philo->output, id);
	philo->output = ft_strjoinfree(philo->output, s1);
	write(1, philo->output, ft_strlen(philo->output));
	free(philo->output);
	philo->output = NULL;
	free(id);
}

static void	philo_dead(t_philo *philo, int tm, int i)
{
	tm = ft_time() - philo[i].past_time;
	if (tm > 0 && tm >= philo[i].die && philo[i].is_eating == 0)
	{
		pthread_mutex_lock(philo->display);
		dying(philo, i + 1);
	}
}

void	*philo_check(void *tmp)
{
	int		i;
	int		j;
	int		scan;
	int		tm;
	t_philo	*philo;

	philo = tmp;
	i = 0;
	scan = philo[i].nbr;
	while (i < scan)
	{
		j = 0;
		philo_dead(philo, tm, i);
		while (j <= scan && philo->max_eat > -1 && philo[j].meal_count
			>= philo[j].max_eat)
			j++;
		if (j >= scan)
			ft_exit(philo);
		if (i + 1 == scan)
			i = -1;
		i++;
	}
	return (NULL);
}
