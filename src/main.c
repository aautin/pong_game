/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:41:01 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 21:57:25 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int	main(void)
{
	t_screen	std_scr;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	std_scr.win = stdscr; 
	getmaxyx(stdscr, std_scr.y, std_scr.x);
	main_menu(std_scr);
	endwin();
}
