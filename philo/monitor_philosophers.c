/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:06:14 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:51 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philosophers(void *arg)
{
	t_table	*table;
	t_philo	philosopher;
	int		i;

	table = (t_table *)arg;
	table->monitor_running = 1;
	while (table->monitor_running)
	{
		i = -1;
		while (++i < table->number_of_philosophers)
		{
			philosopher = table->philosophers[i];
			if ((get_timestamp_ms() - table->last_meals_time[i])
				> table->time_to_die + 1)
			{
				printf("%d %d died\n", get_timestamp_ms(), i + 1);
				table->is_running = 0;
				return (NULL);
			}
		}
		usleep(500);
	}
	return (NULL);
}
