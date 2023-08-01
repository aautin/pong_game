/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:50 by yahan             #+#    #+#             */
/*   Updated: 2023/08/01 22:15:09 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

# define WALL "="
# define BAR "|"
# define BALL "o"
# define BAR_LEN 4
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

typedef struct s_screen {
	WINDOW		*win;
	int			x;
	int			y;
}	t_screen;

// menus.c
void	main_menu(t_screen stsc);
void	information_menu(t_screen stsc);

// game.c
void	start_game(t_screen stsc);
void	init_game(t_screen gscr, t_ball *ball, t_player *p1, t_player *p2);
void	update_window(t_screen gscr, t_ball ball, t_player p1, t_player p2);
void	wprint_bar(WINDOW *win, t_player player);
void	wprint_ball(WINDOW *win, t_ball ball);

// score.c
void	update_score(t_player player);

// utils.c
int		ft_strlen(char *str);
void	wprint_wall_board(WINDOW *win, int max_y, int max_x);

#endif
