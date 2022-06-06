/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <zrdouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:23:51 by zrdouane          #+#    #+#             */
/*   Updated: 2022/06/02 03:10:25 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# define FT_ERROR       1
# define FT_SUCCESS     0

typedef struct s_philo
{
	int				n;
	int				num_of_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	check_mutex;
	pthread_t		thread;
	struct s_info	*info;
	struct timeval	last_time_to_eat;

}					t_philo;
typedef struct s_info
{
	int				num_of_philo;
	int				num_of_times_each_philosopher_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finish;
	pthread_mutex_t	finish_mutex;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	struct timeval	create_at;
	int				die;
}			t_info;

long long	time_to_ms(struct timeval now);
void		print_philo_msg(t_philo *philo, char *str);
int			ft_puterror(char *str);
int			ft_atoi(const char *str);
int			ft_malloc(void *dst, size_t size);
long long	time_to_ms(struct timeval now);
int			ft_puterror(char *str);
int			ft_atoi(const char *str);
int			ft_malloc(void *dst, size_t size);
void		*ft_monitor_eat_philo(void *argv);
int			init(t_info *info, int argc, char *argv[]);
void		*monitoreee(void *argv);
void		*philo(void *argv);

#endif
