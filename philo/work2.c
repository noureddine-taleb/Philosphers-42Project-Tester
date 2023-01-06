/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noureddine <noureddine@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:12:44 by ntaleb            #+#    #+#             */
/*   Updated: 2023/01/06 11:33:02 by noureddine       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "../philo_bonus/philo_bonus.h"
#else
# include "philo.h"
#endif

void	__philo_eat(t_philo *philo, int max)
{
	philo_log_eat(philo);
	msleep(min(philo->state->time_to_eat, max));
}

void	__philo_sleep(t_philo *philo, int max)
{
	philo_log_sleep(philo);
	msleep(min(philo->state->time_to_sleep, max));
}

/**
 * TODO: time to think need a closer investigation
*/
#ifdef BONUS

// void	__philo_think(t_philo *philo, int max)
// {
// 	philo_log_think(philo);
// 	msleep(min(1, max));
// }
void	__philo_think(t_philo *philo, int max)
{
	int	time_to_think;

	time_to_think = philo->state->time_to_die - philo->state->time_to_eat
		- philo->state->time_to_sleep - 3;
	philo_log_think(philo);
	if (time_to_think > 0)
		msleep(min(time_to_think, max));
}

#else

void	__philo_think(t_philo *philo, int max)
{
	int	time_to_think;

	time_to_think = philo->state->time_to_die - philo->state->time_to_eat
		- philo->state->time_to_sleep - 3;
	philo_log_think(philo);
	if (time_to_think > 0)
		msleep(min(time_to_think, max));
}

// void	__philo_think(t_philo *philo, int max)
// {
// 	philo_log_think(philo);
// 	msleep(min(2, max));
// }

#endif
