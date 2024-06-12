/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:00:53 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 14:51:37 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philosophers(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->number_of_philosophers)
	{
		table->philosophers[i].id = i;
		table->philosophers[i].meal_count = 0;
		table->philosophers[i].left_fork = &table->forks[i];
		table->philosophers[i].right_fork = &table->forks[(i + 1)
			% table->number_of_philosophers];
		table->last_meals_time[i] = 0;
	}
}
