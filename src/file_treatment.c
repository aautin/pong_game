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
	int		i;

	fl->descriptor = open(fl_name, O_RDONLY);
	if (fl->descriptor == -1)
		return ;
	fl->size = file_size(fl_name);
	fl->content = (char *)malloc(fl->size * sizeof(char));
	read(fl->descriptor, fl->content, fl->size);
	i = 0;
	fl->lines_nb = 0;
	while (fl->content[i])
	{
		if (fl->content[i] == '\n')
			fl->lines_nb++;
		i++;
	}
	close(fl->descriptor);
}

char	*file_name_to_its_v2(char *fl_name)
{
	int		i;
	char *str;

	i = 0;
	while (fl_name[i])
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	str[i + 1] = '\0';
	while (fl_name[i] != '.')
	{
		str[i] = fl_name[i - 1];
		i--;
	}
	str[i--] = '2';
	while(fl_name[i])
	{
		str[i] = fl_name[i];
		i--;
	}
	return (str);
}
