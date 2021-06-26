/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:08:29 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/26 18:10:48 by shyrno           ###   ########.fr       */
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
    unsigned long sleep;
    int id;
    int status;
    unsigned long past_time;
    unsigned long start_time;
}              t_philo;

void eating(t_philo *philo);
void sleeping(t_philo *philo);
void forking(t_philo *philo);
void thinking(t_philo *philo);
void dying(t_philo *philo);
unsigned long ft_time(void);


#endif