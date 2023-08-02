/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:03:07 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 22:45:17 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	wprint_bar(WINDOW *gwin, t_players players)
{
	int	i;

	i = -1;
	while (++i < BAR_LEN)
	{
		mvwprintw(gwin, players.y1 + i, players.x1, BAR);
	}
	refresh();
	wrefresh(gwin);
	i = -1;
	while (++i < BAR_LEN)
	{
		mvwprintw(gwin, players.y2 + i, players.x2, BAR);
	}
	refresh();
	wrefresh(gwin);
}

void	move_players(int ch, t_players *players, t_screen gscr)
{
	if ((ch == 'q' || ch == 'Q') && players->y1 > 1)
		players->y1--;
	else if ((ch == 'a' || ch == 'A') && players->y1 < gscr.y - 3 - BAR_LEN)
		players->y1++;
	if ((ch == 'o' || ch == 'O') && players->y2 > 1)
		players->y2--;
	else if ((ch == 'l' || ch == 'L') && players->y2 < gscr.y - 3 - BAR_LEN)
		players->y2++;
}
