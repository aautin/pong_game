/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 00:17:00 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	start_game(int max_y, int max_x)
{
	WINDOW	*game_win;
	char	wall_c;
	int		ch;

	game_win = newwin(max_y, max_x, 0, 0);
	refresh();
	wall_c = WALL[0];
	wborder(game_win, ' ', ' ', wall_c, wall_c, wall_c, wall_c, wall_c, wall_c);
	mvwprintw(game_win, max_y / 2, 0, "Use your imagination for now :)");
	wrefresh(game_win);
	ch = getch();
	clear();
	if (ch)
		delwin(game_win);
}
