/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/05 22:09:09 by yahan            ###   ########.fr       */
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
	nodelay_switch(gscr.win, scscr.win, stdscr, 0);
	ball->x = gscr.x / 2;
	ball->y = gscr.y / 2;
	ball->vx = rand_negative();
	ball->vy = 0;
	ps->x1 = 1;
	ps->y1 = gscr.y / 2 - BAR_LEN / 2;
	ps->x2 = gscr.x - 2;
	ps->y2 = gscr.y / 2 - BAR_LEN / 2;
	ps->returns_nb = 0;
	update_window(gscr, *ball, *ps);
	mvwprintw(scscr.win, 0, 0, "Press any key to start...");
	refresh();
	wrefresh(gscr.win);
	wrefresh(scscr.win);
	getch();
	nodelay_switch(gscr.win, scscr.win, stdscr, 1);
	wclear(scscr.win);
	refresh();
	wrefresh(scscr.win);
}

void	start_game(t_screen stsc, t_players *ps)
{
	int			ch;
	t_ball		ball;
	t_players	players;
	t_screen	game_scr;
	t_screen	score_scr;

	players.score1 = 0;
	players.score2 = 0;
	init_screens(&game_scr, &score_scr, &stsc);
	init_game(game_scr, score_scr, &ball, &players);
	update_score(players, &score_scr, players.returns_nb);
	while (1)
	{
		ch = getch();
		if (ch)
			move_players(ch, &players, game_scr);
		if (compl_or_add(game_scr, &score_scr, &ball, &players))
			break ;
		move_ball(&ball, &players, game_scr);
		update_window(game_scr, ball, players);
		usleep(DELAY - (players.returns_nb) * 1000);
	}
	ps->score1 = players.score1;
	ps->score2 = players.score2;
	nodelay_switch(game_scr.win, score_scr.win, stsc.win, 0);
	delwin(score_scr.win);
	delwin(game_scr.win);
}
