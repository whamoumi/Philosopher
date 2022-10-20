/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:09:05 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 17:04:45 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_parser{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_philo;
	int				time_must_eat;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	screen1;
}				t_parser;

typedef struct s_philosopher{
	int					id;
	int					number_of_philo;
	int					i;
	int					status;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	unsigned int		time_eat;
	unsigned long long	start;
	unsigned long long	time_last_eat;
	int					philo_life;
	unsigned int		time_must_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*screen;
}				t_philosopher;

void				take_right_fork(t_philosopher *philo,
						unsigned long long start);
void				take_left_fork(t_philosopher *philo,
						unsigned long long start);
void				philo_eating(t_philosopher *philo,
						unsigned long long start);
void				eat_routine_of_philo(t_philosopher *philo,
						unsigned long long start);
void				pre_fill_struct2(t_parser *parser, char **argv, int argc);
int					pre_fill_struct(t_parser *par, char **argv, int argc);
void				fill_struct2(t_parser *parser, int i,
						t_philosopher *les_philos);
t_philosopher		*fill_struct(t_parser *par);
void				*check_status2(void *arg);
void				fill_philo_status(t_philosopher *phi, int status, int u);
void				*check_status(void *arg);
void				*routine(void *arg);
void				ft_usleep(int ms);
long int			actual_time(void);
unsigned long long	timee(void);
int					str_is_alpha(char *str);
int					check_philo_eat(t_philosopher *philo);
void				thinking_routine_philo(t_philosopher *philo,
						unsigned long long start);
void				sleep_routine_philo(t_philosopher *philo,
						unsigned long long start);
#endif
