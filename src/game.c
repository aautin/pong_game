/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 21:18:46 by yahan            ###   ########.fr       */
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

void	update_window(int max_y, int max_x, t_ball ball, t_player p1, t_player p2, WINDOW *win)
{
	wprint_ball(win, ball);
	wprint_bar(win, p1);
	wprint_bar(win, p2);
	wprint_wall_board(win, max_y, max_x);
	refresh();
	wrefresh(win);
}

void	init_game(int max_y, int max_x, t_ball *ball_ptr, t_player *p1_ptr, t_player *p2_ptr)
{
	ball_ptr->x = max_x / 2;
	ball_ptr->y = max_y / 2;
	p1_ptr->x = 1;
	p1_ptr->y = max_y / 2 - BAR_LEN / 2;
	p2_ptr->x = max_x - 2;
	p2_ptr->y = max_y / 2 - BAR_LEN / 2;
}

void	start_game(int max_y, int max_x)
{
	WINDOW		*game_win;
	int			ch;
	t_ball		ball;
	t_player	player1;
	t_player	player2;

	game_win = newwin(max_y, max_x, 0, 0);
	init_game(max_y, max_x, &ball, &player1, &player2);
	update_window(max_y, max_x, ball, player1, player2, game_win);
	mvwprintw(game_win, max_y - 2, 0, "Press any key to start...");
	refresh();
	wrefresh(game_win);
	while (1)
	{
		ch = getch();
		clear();
		if (ch == 'q' || ch == 'Q')
			player1.y--;
		else if (ch == 'a' || ch == 'A')
			player1.y++;
		if (ch == 'o' || ch == 'O')
			player2.y--;
		else if (ch == 'l' || ch == 'L')
			player2.y++;
		update_window(max_y, max_x, ball, player1, player2, game_win);
	}
	delwin(game_win);
}
