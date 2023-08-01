/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:41:01 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 14:35:19 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong_game.h"

int	main(void)
{
	int	max_y;
	int	max_x;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, max_y, max_x);
	main_menu(max_y, max_x);
	endwin();
}
