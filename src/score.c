/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by aautin            #+#    #+#             */
/*   Updated: 2023/08/03 16:17:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

void	update_score(t_players players, t_screen *sc_scr)
{
	char	score;
	t_file	best_rally;

	mvwprintw(sc_scr->win, 0, 0,"Score :   -  ");
	score = players.score1 + 48;
	mvwprintw(sc_scr->win, 0, 8,"%c", score);
	score = players.score2 + 48;
	mvwprintw(sc_scr->win, 0, 12,"%c", score);
	best_rally.size = file_size("biggest_rally");
	mvwprintw(sc_scr->win, 0, sc_scr->x - 25 - best_rally.size,"Longest rally :   ");
	file_to_str("biggest_rally", &best_rally);
	mvwprintw(sc_scr->win, 0, sc_scr->x - best_rally.size - 9, "%s", best_rally.content);
	mvwprintw(sc_scr->win, 0, sc_scr->x - 10,"(  /  /  )");
	free(best_rally.content);
	while (getch() == ERR)
	wrefresh(sc_scr->win);
}
