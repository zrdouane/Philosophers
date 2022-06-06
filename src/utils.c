/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <zrdouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:28 by zrdouane          #+#    #+#             */
/*   Updated: 2022/06/02 03:05:44 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to_ms(struct timeval now)
{
	long long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

void	print_philo_msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	now;

	pthread_mutex_lock(&philo->info->finish_mutex);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) - time_to_ms(philo->info->create_at);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}

int	ft_puterror(char *str)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(2, str, i);
	return (FT_ERROR);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		r *= 10;
		r += str[i] - 48;
		i++;
	}
	return (r * s);
}

int	ft_malloc(void *dst, size_t size)
{
	*(void **)dst = malloc(size);
	if (*(void **)dst == NULL)
		return (FT_ERROR);
	memset(*(void **)dst, 0, size);
	return (FT_SUCCESS);
}
