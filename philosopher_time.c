/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:37:37 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 16:35:02 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned long long	timee(void)
{
	struct timeval		timer;
	unsigned long long	time;

	gettimeofday(&timer, NULL);
	time = ((unsigned long long)timer.tv_sec) * 1000
		+ ((unsigned long long)(timer.tv_usec)) / 1000;
	return (time);
}

long int	actual_time(void)
{
	long int		time;
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	time = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (time);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = actual_time();
	while ((actual_time() - time) < ms)
		usleep(ms);
}
