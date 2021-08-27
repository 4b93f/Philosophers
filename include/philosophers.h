/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:08:29 by shyrno            #+#    #+#             */
/*   Updated: 2021/08/27 18:17:39 by chly-huc         ###   ########.fr       */
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
	pthread_mutex_t	*fork2;
	int				max_eat;
	char			*output;
	pthread_mutex_t	*display;
	int				is_eating;
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
int				verif(int argc, char **argv);
void			dying(t_philo *philo, int i);
void			ft_init_fork(t_philo *philo, char **argv);
void			ft_init_info(t_philo *philo, char **argv);
void			ft_init_mutex(t_philo *philo, char **argv);
int				str_isnum(char *str);
void			print(t_philo *philo, char *s1);
char			*ft_strjoinfree(const char *s1, const char *s2);
char			*ft_itoa(int n);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *s);
long			ft_atoli(const char *str);
void			*philo_check(void *tmp);
static void		philo_dead(t_philo *philo, int tm, int i);

#endif