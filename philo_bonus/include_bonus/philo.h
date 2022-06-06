/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrdouane <zrdouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 03:15:28 by zrdouane          #+#    #+#             */
/*   Updated: 2022/06/02 03:17:16 by zrdouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_thread
{
	pthread_t		philo;
	long long		time;
	int				i;
	int				n_eat;
	struct s_philo	*all;
}	t_pthread;

typedef struct s_philo
{
	long long			time;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	t_pthread			*philos;
	sem_t				*printf;
	sem_t				*zack;
}	t_philo;

int			ft_atoi(const char *str);
int			check_in(int ac, char **av);
int			ft_allocation(t_philo *philo, char **av);
int			*ft_thread(t_philo *philo);
void		*ft_procces(void *ph);
long long	get_time(void);
void		out(t_pthread *philo, char *s, int lamp);
void		ft_exit(t_philo *philo, int *pid, int size);
void		ft_sem_init(t_philo *philo);
void		ft_free(t_philo *philo, int l);
int			func(t_pthread *philo);
void		ft_usleep(unsigned long time);

#endif
