/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:36:00 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:44:24 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(t_table *table)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * (table->number_of_philosophers + 1));
	if (!threads)
		return ;
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_create(&threads[i], NULL, philosopher_life,
			(void *)table);
	pthread_create(&threads[table->number_of_philosophers], NULL,
		monitor_philosophers, (void *)table);
	i = -1;
	while (++i <= table->number_of_philosophers)
		pthread_join(threads[i], NULL);
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_mutex_destroy(&table->forks[i]);
	free(threads);
}
