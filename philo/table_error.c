/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:35 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 16:40:36 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	table_error(t_table *table, int last_arg)
{
	if (table->number_of_philosophers < 1)
		return (1);
	if (table->time_to_die < 0)
		return (1);
	if (table->time_to_eat < 0)
		return (1);
	if (table->time_to_sleep < 0)
		return (1);
	if (last_arg && table->number_of_times_each_philosopher_must_eat < 0)
		return (1);
	if (table->number_of_philosophers < 2)
	{
		usleep(table->time_to_die * 1000);
		printf("%d 1 died\n", table->time_to_die);
		return (1);
	}
	if (!table->philosophers)
		return (1);
	if (!table->forks)
		return (1);
	if (!table->last_meals_time)
		return (1);
	return (0);
}
