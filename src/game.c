/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 23:56:32 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	update_window(t_screen gscr, t_ball ball, t_players players)
{
	wclear(gscr.win);
	wprint_ball(gscr.win, ball);
	wprint_bar(gscr.win, players);
	refresh();
	wrefresh(gscr.win);
}

void	init_screens(t_screen *gscr, t_screen *scscr, t_screen *stsc)
{
	gscr->x = stsc->x;
	gscr->y = stsc->y - 4;
	gscr->win = newwin(gscr->y, gscr->x, 1, 0);
	scscr->x = stsc->x;
	scscr->y = 1;
	scscr->win = newwin(scscr->y, scscr->x, stsc->y - 2, 0);
}

void	init_game(t_screen gscr, t_screen scscr, t_ball *ball, t_players *ps)
{
	srand(time(NULL));
	ball->x = gscr.x / 2;
	ball->y = gscr.y / 2;
	ball->vx = 1 + (rand() % 2) * (-2);
	ball->vy = 0;
	ps->x1 = 1;
	ps->y1 = gscr.y / 2 - BAR_LEN / 2;
	ps->score1 = 0;
	ps->x2 = gscr.x - 2;
	ps->y2 = gscr.y / 2 - BAR_LEN / 2;
	ps->score2 = 0;
	update_window(gscr, *ball, *ps);
	mvwprintw(scscr.win, 0, 0, "Press any key to start...");
	refresh();
	wrefresh(gscr.win);
	wrefresh(scscr.win);
	getch();
	wclear(scscr.win); // to be move to score_update()
	refresh(); // to be move to score_update()
	wrefresh(scscr.win); // to be move to score_update()
}

void	start_game(t_screen stsc)
{
	int			ch;
	t_ball		ball;
	t_players	players;
	t_screen	game_scr;
	t_screen	score_scr;

	init_screens(&game_scr, &score_scr, &stsc);
	init_game(game_scr, score_scr, &ball, &players);
	nodelay(game_scr.win, TRUE);
	nodelay(score_scr.win, TRUE);
	nodelay(stsc.win, TRUE);
	while (1)
	{
		ch = getch();
		if (ch)
			move_players(ch, &players, game_scr);
		move_ball(&ball, &players, game_scr);
		update_window(game_scr, ball, players);
		usleep(DELAY);
	}
	nodelay(game_scr.win, FALSE);
	nodelay(score_scr.win, FALSE);
	nodelay(stsc.win, FALSE);
	delwin(score_scr.win);
	delwin(game_scr.win);
}
