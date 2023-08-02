/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:50 by yahan             #+#    #+#             */
/*   Updated: 2023/08/02 23:56:28 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <stdio.h>																		// << to remove

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

# define WALL "="
# define BAR "|"
# define BALL "o"
# define BAR_LEN 4
# define DELAY 30000
# define ENTER_MESG "Press ENTER to start the game"
# define I_MESG "Press I for the informations menu"
# define ANY_QUIT_MESG "Any other key entry will cause you to quit the game..."
# define ANY_MENU_MESG "Press any key to go back to the menu..."
# define INFO_MESG1 "The single gamemode is a 1v1 between two players.\n"
# define INFO_MESG2 "Your goal ? Score 3 points before your opponent.\n\n"
# define INFO_MESG3 "Controls :\n"
# define INFO_MESG4 "	Left-player  --> Q to move up and A to move down\n"
# define INFO_MESG5 "	Right-player --> O to move-up and L to move-down\n"

typedef struct s_file {
	char	*content;
	int		size;
	int		descriptor;
}	t_file;

typedef struct s_ball {
	char	c;
	int		x;
	int		y;
	int		vx;
	int		vy;
}	t_ball;

typedef struct s_players {
	char	c;
	int		score1;
	int		x1;
	int		y1;
	int		score2;
	int		x2;
	int		y2;
}	t_players;

typedef struct s_screen {
	WINDOW		*win;
	int			x;
	int			y;
}	t_screen;

typedef struct s_strpart {
	int		from;
	int		to;
	char	*str;
}	t_strpart;

// menus.c
void	main_menu(t_screen stsc);
void	information_menu(t_screen stsc);

// game.c
void	start_game(t_screen stsc);
void	init_screens(t_screen *gscr, t_screen *scscr, t_screen *stsc);
void	init_game(t_screen gscr, t_screen scscr, t_ball *ball, t_players *ps);
void	update_window(t_screen gscr, t_ball ball, t_players players);

// ball.c
void	wprint_ball(WINDOW *win, t_ball ball);
void	move_ball(t_ball *b, t_players *ps, t_screen game_scr);

// player.c
void	wprint_bar(WINDOW *win, t_players players);
void	move_players(int ch, t_players *players, t_screen gscr);

// score.c
void	update_score(t_players players);

// utils.c
int		ft_strlen(char *str);
void	wprint_wall_board(WINDOW *win, int max_y, int max_x);
void	str_copy_print(t_strpart *str, char *src);

// file_treatment.c
void	file_size(char *fl_name, t_file *fl);
void	file_to_str(char *fl_name, t_file *fl);

#endif
