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

void	main_menu(t_screen st)
{
	int		ch;
	t_players	ps;

	while (1)
	{
		clear();
		refresh();
		print_menu_middle(st, "designs/start.txt");
		wprint_wall_board(st.win, st.y, st.x);
		ch = getch();
		if (ch == '\n')
		{
			start_game(st, &ps);
			clear();
			print_menu_middle(st, "designs/end.txt");
			mvwprintw(st.win, (st.y / 2) - 1, (st.x / 2) - 12, "%d", ps.score1);
			mvwprintw(st.win, (st.y / 2) - 1, (st.x / 2) + 22, "%d", ps.score2);
			ch = getch();
		}
		else if (ch == 'i' || ch == 'I')
		{
			clear();
			print_menu_middle(st, "designs/infos.txt");
			ch = getch();
			clear();
		}
		else
			break ;
	}
}

void	print_menu_middle(t_screen sc, char *fl_name)
{
	t_file		fl;
	t_file		fl2;
	t_strpart	str;

	file_to_str(fl_name, &fl);
	str.from = 0;
	fl.lines_nb = fl.lines_nb / 2;
	while (fl.content[str.from])
	{
		str.to = str.from;
		while (fl.content[str.to] != '\n' && fl.content[str.to])
			str.to++;
		str_copy_print(&str, fl.content);
		mvwprintw(sc.win, (sc.y / 2) - fl.lines_nb--, sc.x / 2 - 30, "%s", str.str);
		str.from = str.to + 1;
		free(str.str);
	}
	wprint_wall_board(sc.win, sc.y, sc.x);
	fl2.name = file_name_to_its_v2(fl_name);
	file_to_str(fl2.name, &fl2);
	mvwprintw(sc.win, sc.y - 2, 0, "%s", fl2.content);
	free_strs(fl2.name, fl.content, fl2.content, NULL, NULL);
	refresh();
}
