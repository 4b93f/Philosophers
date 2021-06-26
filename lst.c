/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:44:28 by shyrno            #+#    #+#             */
/*   Updated: 2021/06/23 01:45:32 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosophers.h"

// t_philo_info	*ft_create_philo_info(int nbr)
// {
// 	t_philo_info	*list;
    
// 	int			i;

// 	i = 0;
//     list = ft_stacknew(i + 1);
// 	while (++i < nbr)
//     {
// 		ft_philoadd_back(&list, ft_stacknew(i + 1));
//     }
// 	return (list);
// }

// t_philo_info	*ft_stacknew(int content)
// {
// 	t_philo_info	*newcontent;

// 	newcontent = malloc(sizeof(t_philo_info *));
// 	if (!newcontent)
// 		return (NULL);
// 	newcontent->id = content;
//     newcontent->status = 0;
// 	newcontent->next = NULL;
// 	return (newcontent);
// }

// void	ft_philoadd_back(t_philo_info **alst, t_philo_info *new)
// {
// 	if (!alst || !new)
// 		return ;
// 	if (alst && *alst)
// 		ft_philolast(*alst)->next = new;
//     else if (alst)
// 		*alst = new;
// }

// t_philo_info	*ft_philolast(t_philo_info *lst)
// {
// 	if (!lst)
// 		return (0);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_philoadd_front(t_philo_info **alst, t_philo_info *new)
// {
// 	if (!alst || !new)
// 		return ;
// 	new->next = *alst;
// 	*alst = new;
// }
