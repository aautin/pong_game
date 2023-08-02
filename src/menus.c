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
		refresh();
		mvprintw(middle_y, middle_x, ENTER_MESG);
		mvprintw(middle_y + 1, middle_x, I_MESG);
		mvprintw(stsc.y - 2, 0, ANY_QUIT_MESG);
		wprint_wall_board(stsc.win, stsc.y, stsc.x);
		ch = getch();
		if (ch == '\n')
			start_game(stsc);
		else if (ch == 'i' || ch == 'I')
			information_menu(stsc);
		else
			break ;
	}
}

void	information_menu(t_screen st_sc)
{
	t_screen	info;
	t_file		fl;
	t_strpart	str;
	int			i;

	info.win = newwin(st_sc.y - 2, st_sc.x, 1, 0);
	info.x = st_sc.x;
	info.y = st_sc.y - 2;
	fl.size = file_size("designs/infos.txt");
	file_to_str("designs/infos.txt", &fl);
	i = 4;
	str.from = 0;
	while (fl.content[str.from])
	{
		str.to = str.from;
		while (fl.content[str.to] != '\n' && fl.content[str.to])
			str.to++;
		str_copy_print(&str, fl.content);
		mvwprintw(info.win, (info.y / 2) - i--, info.x / 2 - 30, "%s", str.str);
		str.from = str.to + 1;
		free(str.str);
	}
	wprint_wall_board(st_sc.win, st_sc.y, st_sc.x);
	wrefresh(info.win);
	getch();
	clear();
	delwin(info.win);
}
