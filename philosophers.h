/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:08:29 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/30 16:53:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>
#include <unistd.h>


typedef struct s_philo
{
    int nbr;
    unsigned long die;
    unsigned long eat;
    int max_eat;
	int meal_count;
    unsigned long sleep;
    int id;
    int status;
    unsigned long past_time;
    unsigned long start_time;
	unsigned long start_sleep;
	unsigned long start_eat;
	pthread_mutex_t *fork1;
	pthread_mutex_t *fork2;
	pthread_mutex_t *display;
}              t_philo;

void eating(t_philo *philo);
void sleeping(t_philo *philo);
void forking(t_philo *philo);
void thinking(t_philo *philo);
void dying(t_philo *philo, int i);
unsigned long ft_time(void);
void ft_exit(t_philo *philo);


#endif