/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:52:36 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/24 18:51:37 by chly-huc         ###   ########.fr       */
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

int	atoi_result(int sign, int res)
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
	return (atoi_result(sign, res));
}
