/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <zrdouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:06 by zrdouane          #+#    #+#             */
/*   Updated: 2022/05/19 13:39:12 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pars_arg(t_info *info, int argc, char *argv[])
{
		info->num_of_philo = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
}

static int	check_info(t_info *info, int argc)
{
	if (argc == 6 && info->num_of_must_eat <= 0)
		return (ft_puterror("Error : wrong num of eat\n"));
	if (info->num_of_philo < 0)
		return (ft_puterror("Error : wrong num of philosophers\n"));
	if (info->time_to_die < 0)
		return (ft_puterror("Error : wrong time to die\n"));
	if (info->time_to_eat < 0)
		return (ft_puterror("Error : wrong time to eat\n"));
	if (info->time_to_sleep < 0)
		return (ft_puterror("Error : wrong time to sleep"));
	return (FT_SUCCESS);
}

static int	init_philo(t_info *info)
{
	int	i;

	pthread_mutex_init(&info->finish_mutex, NULL);
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) || \
		ft_malloc(&info->forks, sizeof(pthread_mutex_t) * info->num_of_philo))
		return (ft_puterror("Error : you might have error in allocation"));
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].n = i;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philos[i].check_mutex, NULL);
		if (i == 0)
			info->philos[i].left = &info->forks[info->num_of_philo - 1];
		else
		info->philos[i].left = &info->forks[i - 1];
		info->philos[i].right = &info->forks[i];
		info->philos[i].info = info;
		++i;
	}
	return (FT_SUCCESS);
}

int	init(t_info *info, int argc, char *argv[])
{
	pars_arg(info, argc, argv);
	if (check_info(info, argc))
		return (FT_ERROR);
	if (init_philo(info))
		return (FT_ERROR);
	return (FT_SUCCESS);
}
