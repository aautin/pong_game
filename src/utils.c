/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:42:01 by yahan             #+#    #+#             */
/*   Updated: 2023/08/04 15:47:38 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	wprint_wall_board(WINDOW *win, int max_y, int max_x)
{
	int		i;

	i = -1;
	while (++i < max_x)
	{
		mvwprintw(win, 0, i, "%s", WALL);
		mvwprintw(win, max_y - 3, i, "%s", WALL);
		mvwprintw(win, max_y - 1, i, "%s", WALL);
	}
}

void	str_copy_print(t_strpart *str, char *src)
{
	int		i;

	str->str = (char *)malloc((str->to - str->from + 1) * sizeof(char));
	i = 0;
	while (str->from + i <= str->to)
	{
		str->str[i] = src[str->from + i];
		i++;
	}
	str->str[str->to - str->from] = '\0';
}


void	nodelay_switch(WINDOW *w1, WINDOW *w2, WINDOW *w3, int sw)
{
	if (sw == 1)
	{
		nodelay(w1, TRUE);
		nodelay(w2, TRUE);
		nodelay(w3, TRUE);
	}
	else if (sw == 0)
	{
		nodelay(w1, FALSE);
		nodelay(w2, FALSE);
		nodelay(w3, FALSE);
	}
}

int	rand_int(int max)
{
	int				random_number;
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	random_number = (int)(((double)ts.tv_nsec / 1000000000.0) * max);
	printf("%ld\n", ts.tv_nsec);
	return (random_number);
}
