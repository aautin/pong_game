/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:46:26 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 22:19:17 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	main_menu(t_screen stsc)
{
	int		ch;
	int		middle_x;
	int		middle_y;

	middle_y = (stsc.y - 2) / 2;
	middle_x = (stsc.x - ft_strlen(ENTER_MESG)) / 2;
	while (1)
	{
		mvprintw(middle_y, middle_x, ENTER_MESG);
		mvprintw(middle_y + 1, middle_x, I_MESG);
		mvprintw(stsc.y - 2, 0, ANY_QUIT_MESG);
		wprint_wall_board(stdscr, stsc.y, stsc.x);
		ch = getch();
		if (ch == '\n')
			start_game(stsc);
		else if (ch == 'i' || ch == 'I')
			information_menu(stsc);
		else
			break ;
	}
}

void	information_menu(t_screen stsc)
{
	int		ch;
	int		middle_x;
	int		middle_y;
	WINDOW	*info_win;

	info_win = newwin(stsc.y, stsc.x, 0, 0);
	refresh();
	middle_y = (stsc.y - 2) / 2;
	middle_x = (stsc.x - ft_strlen(INFO_MESG1)) / 2;
	mvwprintw(info_win, middle_y - 2, middle_x, INFO_MESG1);
	mvwprintw(info_win, middle_y - 1, middle_x, INFO_MESG2);
	mvwprintw(info_win, middle_y + 1, middle_x, INFO_MESG3);
	mvwprintw(info_win, middle_y + 2, middle_x, INFO_MESG4);
	mvwprintw(info_win, middle_y + 3, middle_x, INFO_MESG5);
	mvwprintw(info_win, stsc.y - 2, 0, ANY_MENU_MESG);
	wprint_wall_board(info_win, stsc.y, stsc.x);
	wrefresh(info_win);
	ch = getch();
	clear();
	if (ch)
		delwin(info_win);
}
