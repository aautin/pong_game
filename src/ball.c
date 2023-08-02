/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:04:59 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 22:25:02 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	wprint_ball(WINDOW *win, t_ball ball)
{
	mvwprintw(win, ball.y, ball.x, BALL);
	refresh();
	wrefresh(win);
}
