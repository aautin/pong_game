/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:42:01 by yahan             #+#    #+#             */
/*   Updated: 2023/07/31 23:55:34 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong_game.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	wprint_line_board(WINDOW *win, int y, int max_x, char *str)
{
	int		i;

	i = -1;
	while (++i < max_x)
		mvwprintw(win, y, i, str);
}
