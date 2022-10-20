/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:40:04 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 17:10:46 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	unsigned long long	start;
	t_philosopher		*philosopher;

	philosopher = (t_philosopher *)arg;
	start = timee();
	if (philosopher->id % 2 == 0)
		ft_usleep(100);
	philosopher->start = timee();
	while (1)
	{
		if (philosopher->status == 0)
		{
			eat_routine_of_philo(philosopher, start);
			sleep_routine_philo(philosopher, start);
			thinking_routine_philo(philosopher, start);
		}
		else
			return (NULL);
	}
	return (arg);
}

void	*check_status(void *arg)
{
	t_philosopher	*phi;
	int				i;
	int				u;

	phi = (t_philosopher *)arg;
	while (1)
	{
		i = -1;
		while (++i < phi[0].number_of_philo)
		{
			if (phi[i].time_to_die - (timee() - phi[i].time_last_eat) <= 0
				|| phi[0].number_of_philo == 1)
			{
				u = i;
				i = -1;
				while (++i < phi[0].number_of_philo)
					phi[i].status = 1;
				printf("%llu %d is dead\n", timee() - phi[u].start, phi[u].id);
				return (NULL);
			}
		}
	}
}

void	fill_philo_status(t_philosopher *phi, int status, int u)
{
	int	i;

	i = -1;
	while (++i < phi[0].number_of_philo)
		phi[i].status = 1;
	if (status == 1)
		printf("%llu %d is died\n", timee() - phi[u].start, phi[u].id);
}

void	*check_status2(void *arg)
{
	t_philosopher	*phi;
	int				i;
	int				u;

	phi = (t_philosopher *)arg;
	u = 0;
	while (1)
	{
		i = -1;
		while (++i < phi[0].number_of_philo)
		{
			if (phi[i].time_to_die - (timee() - phi[i].time_last_eat) <= 0
				|| phi[0].number_of_philo == 1)
			{
				u = i;
				fill_philo_status(phi, 1, u);
				return (NULL);
			}
			else if (check_philo_eat(phi) == 1)
			{
				fill_philo_status(phi, 0, u);
				return (NULL);
			}
		}
	}
}
