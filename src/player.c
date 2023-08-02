/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:03:07 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 20:06:23 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	wprint_bar(WINDOW *win, t_player player)
{
	int	i;

	i = -1;
	while (++i < BAR_LEN)
		mvwprintw(win, player.y + i, player.x, BAR);
	refresh();
	wrefresh(win);
}

void	move_player(int ch, t_player *p1, t_player *p2, t_screen gscr)
{
	if ((ch == 'q' || ch == 'Q') && p1->y > 1)
		p1->y--;
	else if ((ch == 'a' || ch == 'A') && p1->y < gscr.y - 3 - BAR_LEN)
		p1->y++;
	if ((ch == 'o' || ch == 'O') && p2->y > 1)
		p2->y--;
	else if ((ch == 'l' || ch == 'L') && p2->y < gscr.y - 3 - BAR_LEN)
		p2->y++;
}
