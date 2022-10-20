/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:58:59 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 16:34:22 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	take_right_fork(t_philosopher *philo, unsigned long long start)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->screen);
	printf("%llu %d taken a fork\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(philo->screen);
}

void	take_left_fork(t_philosopher *philo, unsigned long long start)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->screen);
	printf("%llu %d taken a fork\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(philo->screen);
}

void	philo_eating(t_philosopher *philo, unsigned long long start)
{
	pthread_mutex_lock(philo->screen);
	printf("%llu %d is eating\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(philo->screen);
	philo->time_eat++;
}

void	eat_routine_of_philo(t_philosopher *philo, unsigned long long start)
{
	if (philo->number_of_philo == 1)
	{
		printf("%llu %d taken a fork\n", actual_time() - start, philo->id);
		philo->time_to_die = -1000;
	}
	if (philo->status == 0 && philo->number_of_philo != 1)
		take_right_fork(philo, start);
	if (philo->status == 0 && philo->number_of_philo != 1)
		take_left_fork(philo, start);
	philo->time_to_die = philo->philo_life;
	if (philo->status == 0 && philo->number_of_philo != 1)
		philo_eating(philo, start);
	philo->time_last_eat = actual_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
