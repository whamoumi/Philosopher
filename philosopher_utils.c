/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:28:51 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 16:35:28 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleep_routine_philo(t_philosopher *philo, unsigned long long start)
{
	pthread_mutex_lock(philo->screen);
	if (philo->status == 0 && philo->number_of_philo != 1)
		printf("%llu %d is sleeping\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(philo->screen);
	ft_usleep(philo->time_to_sleep);
}

void	thinking_routine_philo(t_philosopher *philo, unsigned long long start)
{
	pthread_mutex_lock(philo->screen);
	if (philo->status == 0 && philo->number_of_philo != 1)
		printf("%llu %d is thinking\n", actual_time() - start, philo->id);
	pthread_mutex_unlock(philo->screen);
}

int	check_philo_eat(t_philosopher *philo)
{
	int	i;
	int	somme;
	int	res;

	somme = philo[0].time_must_eat * philo[0].number_of_philo;
	i = 0;
	res = 0;
	while (i < philo[0].number_of_philo)
	{
		res += philo[i].time_eat;
		i++;
	}
	if (somme > res)
		return (0);
	else
		return (1);
}

int	str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
