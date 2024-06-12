/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:01:49 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 14:50:01 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	if (table->philosophers)
		free(table->philosophers);
	if (table->forks)
		free(table->forks);
	if (table->last_meals_time)
		free(table->last_meals_time);
	free(table);
}
