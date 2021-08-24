/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:04:36 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/22 20:17:22 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	result_atoli(int sign, long res)
{
	if (sign > 0)
		return (res);
	else
		return (-res);
}

long	ft_atoli(const char *str)
{
	long		i;
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
	return (result_atoli(sign, res));
}

int	right_format(char *argv)
{
	int	i;

	i = 0;
	if ((ft_atoli(argv)) > INT32_MAX || (ft_atoli(argv) < 0))
		return (0);
	return (1);
}

int	verif(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	while (++i < argc)
	{
		if ((str_isnum(argv[i]) == 0) || (right_format(argv[i]) == 0))
			return (0);
	}
	return (1);
}

char	*ft_strjoinfree(const char *s1, const char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup((char *)s2));
	tab = malloc(sizeof(char) * ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1);
	if (!tab)
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[++j])
		tab[j + i] = s2[j];
	tab[i + j] = '\0';
	free((char*)s1);
	return (tab);
}