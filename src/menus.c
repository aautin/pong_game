/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:46:26 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 00:13:24 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong_game.h"

void	main_menu(int max_y, int max_x)
{
	int		ch;

	while (1)
	{
		border(' ', ' ', WALL[0], WALL[0], WALL[0], WALL[0], WALL[0], WALL[0]);
		mvprintw(max_y / 2, (max_x - ft_strlen(ENTER_MESG)) / 2, ENTER_MESG);
		mvprintw(max_y / 2 + 1, (max_x - ft_strlen(ENTER_MESG)) / 2, I_MESG);
		mvprintw(max_y - 2, 0, ANY_QUIT_MESG);
		wprint_line_board(stdscr, max_y - 3, max_x, WALL);
		ch = getch();
		clear();
		if (ch == '\n')
			start_game(max_y, max_x);
		else if (ch == 'i' || ch == 'I')
			information_menu(max_y, max_x);
		else
			break ;
	}
	endwin();
}

void	information_menu(int max_y, int max_x)
{
	int		ch;
	int		middle_x;
	int		middle_y;
	WINDOW	*info_win;
	char	wall_c;

	wall_c = WALL[0];
	info_win = newwin(max_y, max_x, 0, 0);
	refresh();
	middle_y = max_y / 2;
	middle_x = (max_x - ft_strlen(INFO_MESG1)) / 2;
	wborder(info_win, ' ', ' ', wall_c, wall_c, wall_c, wall_c, wall_c, wall_c);
	mvwprintw(info_win, middle_y - 2, middle_x, INFO_MESG1);
	mvwprintw(info_win, middle_y - 1, middle_x, INFO_MESG2);
	mvwprintw(info_win, middle_y + 1, middle_x, INFO_MESG3);
	mvwprintw(info_win, middle_y + 2, middle_x, INFO_MESG4);
	mvwprintw(info_win, middle_y + 3, middle_x, INFO_MESG5);
	mvwprintw(info_win, max_y - 2, 0, ANY_MENU_MESG);
	wprint_line_board(info_win, max_y - 3, max_x, WALL);
	wrefresh(info_win);
	ch = getch();
	clear();
	if (ch)
		delwin(info_win);
}
