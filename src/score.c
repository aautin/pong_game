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

void	update_date(t_date *date)
{
	get_date(date);
	
}

void	update_rally_file(int game_score)
{
	t_file	rally;
	char	*g_score;
	int		score_size;

	g_score = ft_itoa(game_score);
	score_size = 0;
	if (game_score == 0)
		score_size++;
	while (game_score)
	{
		game_score = game_score / 10;
		score_size++;
	}
	rally.descriptor = open("biggest_rally", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (rally.descriptor != -1)
	{
		write(rally.descriptor, g_score, score_size);
	}
}

void	update_best_rally(t_file rally, int game_score, t_date *date)
{
	int		best_score;

	best_score = ft_atoi(rally.content);
	if (best_score < game_score)
	{
		update_rally_file(game_score);
		update_date(date);
	}
}

void	update_score(t_players players, t_screen *sc_scr, int returns_nb)
{
	char	score;
	t_file	rally;
	t_date	date;

	mvwprintw(sc_scr->win, 0, 0,"Score :   -  ");
	score = players.score1 + 48;
	mvwprintw(sc_scr->win, 0, 8,"%c", score);
	score = players.score2 + 48;
	mvwprintw(sc_scr->win, 0, 12,"%c", score);
	rally.size = file_size("biggest_rally");
	mvwprintw(sc_scr->win, 0, sc_scr->x - 26 - rally.size,"Longest rally :   ");
	file_to_str("biggest_rally", &rally);
	update_best_rally(rally, returns_nb, &date);
	mvwprintw(sc_scr->win, 0, sc_scr->x - rally.size - 10, "%s", rally.content);
	mvwprintw(sc_scr->win, 0, sc_scr->x - 11," (  /  /  )");
	free(rally.content);
	while (getch() == ERR)
	wrefresh(sc_scr->win);
}
