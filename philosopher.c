/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:04:06 by whamoumi          #+#    #+#             */
/*   Updated: 2021/12/18 16:59:52 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_parser		parsing;
	t_philosopher	*les_philos;
	pthread_t		*philo_thread;
	pthread_t		checker;
	int				i;

	if (pre_fill_struct(&parsing, argv, argc) == 1)
	{
		les_philos = fill_struct(&parsing);
		philo_thread = malloc(sizeof(*philo_thread) * parsing.number_of_philo);
		i = -1;
		while (++i < parsing.number_of_philo)
			pthread_create(&philo_thread[i], NULL, routine, (les_philos + i));
		if (argc == 5)
			pthread_create(&checker, NULL, check_status, les_philos);
		if (argc == 6)
			pthread_create(&checker, NULL, check_status2, les_philos);
		pthread_join(checker, NULL);
	}
	else
		printf("Une erreur est survenue\n");
}
