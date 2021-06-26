/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:26:08 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/26 18:12:12 by shyrno           ###   ########.fr       */
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
	struct timeval ct;

	gettimeofday(&ct, NULL);
	time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
	return(time);
}

static void *testage(void *tmp)
{
 	t_philo *philo;
	
	philo = tmp;
	philo->start_time = ft_time();
	unsigned long start_time;
	unsigned long current_time;
	unsigned long time;
	struct timeval ct;
	while (1)
	{
		gettimeofday(&ct, NULL);
		forking(philo);
		// start_time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
		eating(philo);
		sleeping(philo);
		thinking(philo);
		
		gettimeofday(&ct, NULL);
		// current_time = ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));		
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
	}
}

static void *temp(void *tmp)
{
	int i;
	int scan;
	t_philo *philo;


	unsigned long A;
	unsigned long B;
	unsigned long C;

	philo = tmp;
	i = -1;
	scan = philo->nbr;
	while (++i < scan)
	{
		if (ft_time() - philo[i].past_time >= philo[i].die)
		{
			printf("past time == %ld , time to die == %ld\n", ft_time() - philo[i].past_time, philo[i].die);
			philo[i].status = 0;
		}
		if (philo[i].status == 0)
		{
			printf("philo DEAD\n");
			exit(0);
		}
		if (i + 1 == scan)
			i = -1;	
	}
}

int main(int argc, char **argv)
{
    int i;
	void *tmp;
    pthread_t test;
	pthread_t michel;
    t_philo *philo;
	t_philo *philo_info;

	i = -1;
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[1])));
    init(argc, argv, philo);
	while(++i < philo->nbr)
	{
		pthread_create(&test, NULL, testage, (void*)&philo[i]);
	}
	pthread_create(&michel, NULL, temp, (void*)philo);
	pthread_join(test, NULL);
	//pthread_exit();
	return(0);
}