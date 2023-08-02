/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_treatment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahan <yahanhsiao@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:42:01 by aautin            #+#    #+#             */
/*   Updated: 2023/08/01 21:20:27 by yahan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int		file_size(char *fl_name)
{
	t_file		fl;

	fl.size = 1;
	fl.descriptor = open(fl_name, O_RDONLY);
	if (fl.descriptor == -1)
		return (0);
	fl.content = (char *)malloc(sizeof(char));
	while (read(fl.descriptor, fl.content, 1))
		fl.size++;
	close(fl.descriptor);
	free(fl.content);
	return (fl.size);
}

void	file_to_str(char *fl_name, t_file *fl)
{
	fl->descriptor = open(fl_name, O_RDONLY);
	if (fl->descriptor == -1)
		return ;
	fl->content = (char *)malloc(fl->size * sizeof(char));
	read(fl->descriptor, fl->content, fl->size);
	close(fl->descriptor);
}