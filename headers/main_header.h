/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:50 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 00:16:12 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_GAME_H
# define PONG_GAME_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

# define WALL "="
# define BAR "|"
# define BALL "o"
// # define WALL '='
// # define BAR '|'
// # define BALL 'o'
# define ENTER_MESG "Press ENTER to start the game"
# define I_MESG "Press I for the informations menu"
# define ANY_QUIT_MESG "Any other key entry will cause you to quit the game..."
# define ANY_MENU_MESG "Press any key to go back to the menu..."
# define INFO_MESG1 "The single gamemode is a 1v1 between two players.\n"
# define INFO_MESG2 "Your goal ? Score 3 points before your opponent.\n\n"
# define INFO_MESG3 "Controls :\n"
# define INFO_MESG4 "	Left-player  --> Q to move up and A to move down\n"
# define INFO_MESG5 "	Right-player --> O to move-up and L to move-down\n"

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

// menus.c
void	main_menu(int max_y, int max_x);
void	information_menu(int max_y, int max_x);

// game.c
void	start_game(int max_y, int max_x);
void	print_bar(t_player player);
void	print_ball(t_ball ball);

// score.c
void	update_score(t_player player);

// utils.c
int		ft_strlen(char *str);
void	wprint_line_board(WINDOW *win, int y, int max_x, char *str);

#endif