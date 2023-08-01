/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 22:40:05 by yahan            ###   ########.fr       */
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

void	wprint_ball(WINDOW *win, t_ball ball)
{
	mvwprintw(win, ball.y, ball.x, BALL);
	refresh();
	wrefresh(win);
}

void	update_window(t_screen gscr, t_ball ball, t_player p1, t_player p2)
{
	wprint_ball(gscr.win, ball);
	wprint_bar(gscr.win, p1);
	wprint_bar(gscr.win, p2);
	wprint_wall_board(gscr.win, gscr.y, gscr.x);
	refresh();
	wrefresh(gscr.win);
}

void	init_game(t_screen gscr, t_ball *ball, t_player *p1, t_player *p2)
{
	ball->x = gscr.x / 2;
	ball->y = (gscr.y - 2) / 2;
	p1->x = 1;
	p1->y = (gscr.y - 2) / 2 - BAR_LEN / 2;
	p2->x = gscr.x - 2;
	p2->y = (gscr.y - 2) / 2 - BAR_LEN / 2;
	update_window(gscr, *ball, *p1, *p2);
	mvwprintw(gscr.win, gscr.y - 2, 0, "Press any key to start...");
	refresh();
	wrefresh(gscr.win);
}

void	start_game(t_screen stsc)
{
	int			ch;
	t_ball		ball;
	t_player	player1;
	t_player	player2;
	t_screen	gscr;

	gscr.x = stsc.x;
	gscr.y = stsc.y;
	gscr.win = newwin(stsc.y, stsc.x, 0, 0);
	init_game(gscr, &ball, &player1, &player2);
	while (1)
	{
		ch = getch();
		clear();
		if ((ch == 'q' || ch == 'Q') && player1.y > 1)
			player1.y--;
		else if ((ch == 'a' || ch == 'A') && player1.y < gscr.y - 3 - BAR_LEN)
			player1.y++;
		if ((ch == 'o' || ch == 'O') && player2.y > 1)
			player2.y--;
		else if ((ch == 'l' || ch == 'L') && player2.y < gscr.y - 3 - BAR_LEN)
			player2.y++;
		update_window(gscr, ball, player1, player2);
	}
	delwin(gscr.win);
}
