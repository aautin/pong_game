/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:50 by yahan             #+#    #+#             */
/*   Updated: 2023/07/29 15:43:31 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_GAME_H
# define PONG_GAME_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

typedef struct s_ball {
	char	c;
	int		x;
	int		y;
}	t_ball;

typedef struct s_player {
	char	c;
	int		score;
	int		x;
	int		y;
}	t_player;

void	print_wall(void); // not sure about the input yet
void	print_bar(t_player player);
void	print_ball(t_ball ball);
void	update_score(t_player player);

#endif