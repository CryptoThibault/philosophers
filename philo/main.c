/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:24:26 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:20:38 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac != 5 && ac != 6)
	{
		printf("Arguments count wrong");
		return (1);
	}
	table = fill_table(av + 1);
	if (!table || table_error(table, !!av[5]))
	{
		free_table(table);
		return (1);
	}
	philo(table);
	free_table(table);
	return (0);
}
