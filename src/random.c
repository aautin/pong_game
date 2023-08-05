/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:47:12 by yahan             #+#    #+#             */
/*   Updated: 2023/08/05 22:18:46 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int	rand_int(int max) // to be removed
{
	int				random_number;
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	random_number = (int)(((double)ts.tv_nsec / 1000000000.0) * max);
	return (random_number);
}

float	rand_float(int max)
{
	float			random_number;
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	printf("%ld\n", ts.tv_nsec);
	random_number = (float)(((float)ts.tv_nsec / 1000000000.0) * max);
	return (random_number);
}

float	rand_negative(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	printf("%ld\n", ts.tv_nsec);
	if ((((double)ts.tv_nsec / 1000000000.0) * 10) >= 5.0)
		return (1.0);
	else
		return (-1.0);
}
