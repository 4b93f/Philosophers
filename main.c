/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:26:08 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/29 22:33:30 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	result(int sign, int res)
{
	if (sign > 0)
		return (res);
	else
		return (-res);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = sign * (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res < 0)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
	}
	return (result(sign, res));
}

unsigned long ft_time(void)
{
	unsigned long time;
	static unsigned long tm;
	struct timeval ct;
	
	gettimeofday(&ct, NULL);
	time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
	if (!tm)
		tm = time;
	return (time - tm);
}

static void *testage(void *tmp)
{
 	t_philo *philo;
	
	philo = tmp;
	philo->start_time = ft_time();
	struct timeval ct;
	while (1)
	{
		forking(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

static void init(int argc, char **argv, t_philo *philo)
{
	int i;

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
		philo[i].status = 1;
		philo[i].past_time = 0;
		philo[i].start_time = 0;
		philo[i].start_sleep = 0;
		philo[i].start_eat = 0;
		philo[i].meal_count = 0;
	}
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].fork1 = malloc(sizeof(pthread_mutex_t));
		philo[i].fork2 = malloc(sizeof(pthread_mutex_t));
	}
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(philo[i].fork1, NULL);
		pthread_mutex_init(philo[i].fork2, NULL);
		if (i == (ft_atoi(argv[1]) - 1))
			philo[i].fork2 = philo[0].fork1;
		else
			philo[i].fork2 = philo[i + 1].fork1;
	}
	i = -1;
	pthread_mutex_t *display;
	
	display = malloc(sizeof(pthread_t));
	pthread_mutex_init(display, NULL);
	while (++i < ft_atoi(argv[1]))
		philo[i].display = display;
}

static void *temp(void *tmp)
{
	int i;
	int scan;
	unsigned long pt;
	unsigned long tm;
	t_philo *philo;

	philo = tmp;
	i = -1;
	scan = philo->nbr;
	while (++i <= scan)
	{
		//printf("%lu\ndie =%lu\n", ft_time() - philo[i].past_time, philo[i].die);
		if (ft_time() - philo[i].past_time != 0 && (ft_time() - philo[i].past_time) >= philo[i].die)
		{
			//printf("Ft_time = {%lu}, philo[i].past_time = {%lu}\n", ft_time(), philo[i].past_time);
			//printf("Le temps passer entre les deux repas == {%lu}, max temps = {%lu} et l'id et {%d}\n", ft_time() - philo[i].past_time, philo[i].die, i);
			dying(philo, i + 1);
			exit(0);
		}
		//if (tm - philo[i].past_time >= philo[i].die)
		//{
		//	printf("tm == %ld , time to die == %ld, and id = %d\n", tm - philo[i].past_time, philo[i].die, i);
		//	philo[i].status = 0;
		//}
		//if (philo[i].status == 0)
		//{
		//	printf("philo DEAD\n");
		//	exit(0);
		//}
		if (i + 1 == scan)
			i = -1;	
	}
	return (NULL);
}

int main(int argc, char **argv)
{
    int i;
	void *tmp;
    pthread_t test;
	pthread_t michel;
    t_philo *philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[1])));
    init(argc, argv, philo);
	ft_time();
	while(++i < philo->nbr)
	{
		pthread_create(&test, NULL, testage, (void*)&philo[i]);
	}
	pthread_create(&michel, NULL, temp, (void*)philo);
	pthread_join(michel, NULL);
	return(0);
}