/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:27:38 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:54:57 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philosopher_eating(t_table *table, t_philo philosopher)
{
	pthread_mutex_lock(philosopher.left_fork);
	if (!table->is_running)
		return ;
	pthread_mutex_lock(philosopher.right_fork);
	if (!table->is_running)
		return ;
	printf("%d %d has taken fork\n", get_timestamp_ms(), philosopher.id + 1);
	printf("%d %d has taken fork\n", get_timestamp_ms(), philosopher.id + 1);
	printf("%d %d is eating\n", get_timestamp_ms(), philosopher.id + 1);
	table->last_meals_time[philosopher.id] = get_timestamp_ms();
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher.left_fork);
	pthread_mutex_unlock(philosopher.right_fork);
}

void	*philosopher_life(void *arg)
{
	t_table	*table;
	t_philo	philosopher;

	table = (t_table *)arg;
	philosopher = table->philosophers[table->current_id++];
	while (table->is_running)
	{
		philosopher_eating(table, philosopher);
		if (!table->is_running || ++philosopher.meal_count
			== table->number_of_times_each_philosopher_must_eat)
			break ;
		printf("%d %d is sleeping\n", get_timestamp_ms(), philosopher.id + 1);
		usleep(table->time_to_sleep * 1000);
		if (!table->is_running)
			break ;
		printf("%d %d is thinking\n", get_timestamp_ms(), philosopher.id + 1);
	}
	table->monitor_running = 0;
	return (NULL);
}
