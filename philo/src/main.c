/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <zrdouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:11 by zrdouane          #+#    #+#             */
/*   Updated: 2022/06/02 02:31:11 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_free_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philos[i].thread, NULL);
		pthread_mutex_destroy(&info->philos[i++].check_mutex);
	}
	free(info->philos);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	free(info->forks);
}

static void	create_philosophers(t_info *info)
{
	int	i;
	pthread_t
		thread;

	gettimeofday(&info->create_at, NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->create_at;
		pthread_create(&info->philos[i].thread, NULL, philo, &info->philos[i]);
		pthread_create(&thread, NULL, monitoreee, &info->philos[i]);
		pthread_detach(thread);
		++i;
	}
	if (info->num_of_must_eat != 0)
	{
		pthread_create(&thread, NULL, ft_monitor_eat_philo, info);
		pthread_detach(thread);
	}
}

int	func(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) < 0)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.die = 1;
	memset(&info, 0, sizeof(info));
	if (argc != 5 && argc != 6)
		return (ft_puterror("Wrong argc"));
	if (func(argc, argv))
		return (printf("error\n"));
	if (init(&info, argc, argv))
		return (1);
	create_philosophers(&info);
	join_free_philo(&info);
	return (0);
}
