/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:04:59 by yahan             #+#    #+#             */
/*   Updated: 2023/08/05 22:17:44 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	wprint_ball(WINDOW *win, t_ball ball)
{
	mvwprintw(win, ball.y, ball.x, BALL);
	refresh();
	wrefresh(win);
}

void	move_ball(t_ball *b, t_players *ps, t_screen game_scr)
{
	float	ny;
	float	nx;

	ny = b->y + b->vy;
	nx = b->x + b->vx;
	if (ny <= 1.0 || ny >= game_scr.y)
		b->vy *= -1.0;
	if ((nx <= ps->x1 + 1 && ny >= ps->y1 && ny <= ps->y1 + BAR_LEN)
		|| (nx >= ps->x2 - 1 && ny >= ps->y2 && ny <= ps->y2 + BAR_LEN))
	{
		b->vy = rand_float(1);
		b->vx *= -1.0;
		ps->returns_nb++;
		mvwprintw(game_scr.win, game_scr.y - 1, 0, "%d", ps->returns_nb);
	}
	b->x += b->vx;
	b->y += b->vy;
}
