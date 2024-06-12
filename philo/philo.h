/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:48:22 by tchalaou          #+#    #+#             */
/*   Updated: 2024/06/10 17:52:25 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				meal_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}		t_philo;

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	int				*last_meals_time;
	int				current_id;
	int				is_running;
	int				monitor_running;
}		t_table;

int		ft_atoi(const char *nptr);
t_table	*fill_table(char **value);
void	fill_philosophers(t_table *table);
int		table_error(t_table *table, int last_param);
void	free_table(t_table *table);
void	philo(t_table *table);
void	*philosopher_life(void *arg);
void	*monitor_philosophers(void *arg);
int		get_timestamp_ms(void);

#endif
