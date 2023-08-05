/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:30:50 by yahan             #+#    #+#             */
/*   Updated: 2023/08/05 22:18:32 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include "structs_header.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

# define WALL "="
# define BAR "|"
# define BALL "o"
# define BAR_LEN 4
# define DELAY 20000

// menus.c
void	main_menu(t_screen stsc);
void	print_menu_middle(t_screen sc, char *fl_name);
void	update_score(t_players players, t_screen *sc_scr);

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
int		compl_or_add(t_screen gscr, t_screen *scscr, t_ball *b, t_players *ps);

// score.c
void	update_score(t_players players, t_screen *sc_scr);

// utils.c
int		ft_strlen(char *str);
void	wprint_wall_board(WINDOW *win, int max_y, int max_x);
void	str_copy_print(t_strpart *str, char *src);
void	nodelay_switch(WINDOW *w1, WINDOW *w2, WINDOW *w3, int sw);
void	free_strs(char *str1, char *str2, char *str3, char *str4, char *str5);

// file_treatment.c
int		file_size(char *fl_name);
void	file_to_str(char *fl_name, t_file *fl);
char	*file_name_to_its_v2(char *fl_name);

// convert_types.c
char	*ft_itoa(int	number);
int		ft_atoi(char *number);

// random.c
int		rand_int(int max); // to be removed
float	rand_float(int max);
float	rand_negative(void);

#endif
