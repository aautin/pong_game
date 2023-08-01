/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:42:01 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 21:20:27 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int	ft_strlen(char *str)
{
	int	i;

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
