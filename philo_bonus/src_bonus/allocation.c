/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 03:17:43 by zrdouane          #+#    #+#             */
/*   Updated: 2022/06/02 03:17:44 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_allocation(t_philo *philo, char **av)
{
	int	i;

	i = -1;
	philo->n_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]);
	philo->philos = malloc(sizeof(t_pthread) * (philo->n_philo));
	if (!philo->philos)
		return (0);
	philo->time = get_time();
	while (++i < philo->n_philo)
	{
		philo->philos[i].i = i + 1;
		philo->philos[i].time = philo->time;
		philo->philos[i].n_eat = 0;
		philo->philos[i].all = philo;
	}
	return (1);
}

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1e3) + (current_time.tv_usec / 1e3));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	curr;

	curr = get_time();
	while (get_time() - curr < time)
		usleep(50);
}

void	ft_free(t_philo *philo, int l)
{
	free(philo->philos);
	exit(l);
}

void	ft_sem_init(t_philo *philo)
{
	sem_unlink("zack");
	sem_unlink("printf");
	philo->zack = sem_open("zack", O_CREAT, 0644, philo->n_philo);
	philo->printf = sem_open("printf", O_CREAT, 0644, 1);
	if (philo->zack == SEM_FAILED || philo->zack == SEM_FAILED)
		return (free(philo->philos), exit(0));
}
