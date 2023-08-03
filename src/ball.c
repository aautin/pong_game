/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:04:59 by yahan             #+#    #+#             */
/*   Updated: 2023/08/03 16:14:33 by yahan            ###   ########.fr       */
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
	if (b->y == 1 || b->y == game_scr.y)
		b->vy *= -1;
	if ((b->x == ps->x1 + 1 && b->y >= ps->y1 && b->y <= ps->y1 + BAR_LEN)
		|| (b->x == ps->x2 - 1 && b->y >= ps->y2 && b->y <= ps->y2 + BAR_LEN))
	{
		b->vy = (rand() % 3 - 1);
		b->vx *= -1;
	}
	b->x += b->vx;
	b->y += b->vy;
}
