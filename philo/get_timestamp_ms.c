/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_ms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:26:25 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/15 14:56:46 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp_ms(void)
{
	struct timeval	tv;
	static int		initial_timestamp_ms = -1;
	int				current_timestamp_ms;

	if (initial_timestamp_ms == -1)
	{
		gettimeofday(&tv, NULL);
		initial_timestamp_ms = (int)((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	}
	gettimeofday(&tv, NULL);
	current_timestamp_ms = (int)((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (current_timestamp_ms - initial_timestamp_ms);
}
