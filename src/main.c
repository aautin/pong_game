/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:41:01 by yahan             #+#    #+#             */
/*   Updated: 2023/07/29 15:43:15 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong_game.h"

int	main(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	// main loop
	while (1)
	{
		printw("Press any key to quit\n");
		if (getch())
			break ;
	}
	endwin();
}
