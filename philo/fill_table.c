/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:45:44 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:12 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*fill_table(char **value)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philosophers = ft_atoi(value[0]);
	table->time_to_die = ft_atoi(value[1]);
	table->time_to_eat = ft_atoi(value[2]);
	table->time_to_sleep = ft_atoi(value[3]);
	if (value[4])
		table->number_of_times_each_philosopher_must_eat = ft_atoi(value[4]);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
	if (table->number_of_philosophers < 0)
		table->number_of_philosophers = 0;
	table->philosophers = malloc(sizeof(t_philo)
			* table->number_of_philosophers);
	table->forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	table->last_meals_time = malloc(sizeof(int)
			* table->number_of_philosophers);
	fill_philosophers(table);
	table->current_id = 0;
	table->is_running = 1;
	return (table);
}
