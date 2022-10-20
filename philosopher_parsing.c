/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:36:10 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 16:46:45 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	pre_fill_struct2(t_parser *parser, char **argv, int argc)
{
	parser->number_of_philo = atoi(argv[1]);
	parser->time_to_die = atoi(argv[2]);
	parser->time_to_eat = atoi(argv[3]);
	parser->time_to_sleep = atoi(argv[4]);
	parser->time_must_eat = -1;
	if (argc == 6)
		parser->time_must_eat = atoi(argv[5]);
}

int	pre_fill_struct(t_parser *par, char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		while (argv[++i])
		{
			if (str_is_alpha(argv[i]) == 0)
				return (0);
		}
		pre_fill_struct2(par, argv, argc);
		par->mutex = malloc(sizeof(pthread_mutex_t) * par->number_of_philo);
		i = -1;
		while (++i < par->number_of_philo)
			pthread_mutex_init(&par->mutex[i], NULL);
		pthread_mutex_init(&par->screen1, NULL);
		return (1);
	}
	return (0);
}

void	fill_struct2(t_parser *parser, int i, t_philosopher *les_philos)
{
	les_philos->id = i + 1;
	les_philos->number_of_philo = parser->number_of_philo;
	les_philos->i = 0;
	les_philos->status = 0;
	les_philos->time_eat = 0;
	les_philos->time_to_eat = parser->time_to_eat;
	les_philos->time_to_die = parser->time_to_die;
	les_philos->philo_life = parser->time_to_die;
	les_philos->time_to_sleep = parser->time_to_sleep;
	les_philos->time_must_eat = parser->time_must_eat;
}

t_philosopher	*fill_struct(t_parser *par)
{
	t_philosopher	*les_philos;
	int				i;

	i = 0;
	les_philos = malloc(sizeof(*les_philos) * par->number_of_philo);
	while (i < par->number_of_philo)
	{
		fill_struct2(par, i, &les_philos[i]);
		if (i == 0)
			les_philos[i].left_fork = &par->mutex[par->number_of_philo - 1];
		else
			les_philos[i].left_fork = &par->mutex[i - 1];
		les_philos[i].right_fork = &par->mutex[i];
		les_philos[i].screen = &par->screen1;
		i++;
	}
	return (les_philos);
}
