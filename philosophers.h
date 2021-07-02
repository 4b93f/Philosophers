/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:08:29 by shyrno            #+#    #+#             */
/*   Updated: 2021/07/02 18:24:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include "stdio.h"
# include "stdlib.h"
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				nbr;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	pthread_mutex_t	*fork1;
	int				is_eating;
	pthread_mutex_t	*fork2;
	int				max_eat;
	pthread_mutex_t	*display;
	unsigned long	past_time;
	unsigned long	start_eat;
	int				meal_count;
	unsigned long	start_sleep;
}				t_philo;

unsigned long	ft_time(void);
void			eating(t_philo *philo);
void			forking(t_philo *philo);
void			ft_exit(t_philo *philo);
void			thinking(t_philo *philo);
void			sleeping(t_philo *philo);
int				ft_atoi(const char *str);
int				verif(int argc, char **argv);
void			dying(t_philo *philo, int i);
int				atoi_result(int sign, int res);
void			ft_init_fork(t_philo *philo, char **argv);
void			ft_init_info(t_philo *philo, char **argv);
void			ft_init_mutex(t_philo *philo, char **argv);
int	str_isnum(char *str);

#endif
