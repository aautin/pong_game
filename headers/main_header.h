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


typedef struct s_file {
	char	*content;
	char	*name;
	int		size;
	int		descriptor;
	int		lines_nb;
}	t_file;

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

typedef struct s_strpart {
	int		from;
	int		to;
	char	*str;
}	t_strpart;

// menus.c
void	main_menu(t_screen stsc);
void	print_menu_middle(t_screen sc, char *fl_name, int *ch);

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
void	str_copy_print(t_strpart *str, char *src);

// file_treatment.c
int		file_size(char *fl_name);
void	file_to_str(char *fl_name, t_file *fl);
char	*file_name_to_its_v2(char *fl_name);

#endif
