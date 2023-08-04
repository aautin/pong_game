/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:42:01 by yahan             #+#    #+#             */
/*   Updated: 2023/08/03 15:10:25 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	wprint_wall_board(WINDOW *win, int max_y, int max_x)
{
	int		i;

	i = -1;
	while (++i < max_x)
	{
		mvwprintw(win, 0, i, "%s", WALL);
		mvwprintw(win, max_y - 3, i, "%s", WALL);
		mvwprintw(win, max_y - 1, i, "%s", WALL);
	}
}

void	str_copy_print(t_strpart *str, char *src)
{
	int		i;

	str->str = (char *)malloc((str->to - str->from + 1) * sizeof(char));
	i = 0;
	while (str->from + i <= str->to)
	{
		str->str[i] = src[str->from + i];
		i++;
	}
	str->str[str->to - str->from] = '\0';
}


void	nodelay_switch(WINDOW *w1, WINDOW *w2, WINDOW *w3, int sw)
{
	if (sw == 1)
	{
		nodelay(w1, TRUE);
		nodelay(w2, TRUE);
		nodelay(w3, TRUE);
	}
	else if (sw == 0)
	{
		nodelay(w1, FALSE);
		nodelay(w2, FALSE);
		nodelay(w3, FALSE);
	}
}

void	free_strs(char *str1, char *str2, char *str3, char *str4, char *str5)
{
	// simple function used to free 0 to 5 strings.
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	if (str3 != NULL)
		free(str3);
	if (str4 != NULL)
		free(str4);
	if (str5 != NULL)
		free(str5);
}