/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <ezagof@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:04:55 by aautin            #+#    #+#             */
/*   Updated: 2023/08/03 16:17:10 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main_header.h"

int		ft_atoi(char *number)
{
	int		i;
	int		nb;

	i = 0;
	while ('0' > number[i] || number[i] > '9')
		i++;
	nb = 0;
	while ('0' <= number[i] && number[i] <= '9')
	{
		nb = (nb * 10) + (number[i] - 48);
		i++;
	}
	return (nb);
}

char	*ft_itoa(int number)
{
	int		i;
	int		size;
	char	*str;
	int		temp;

	temp = number;
	size = 0;
	if (number == 0)
		size++;
	while(number)
	{
		number = number / 10;
		size++;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	i = 0;
	while(i < size)
	{
		str[size - i - 1] = (temp % 10) + 48;
		temp = temp / 10;
		i++;
	}
	return (str);
}

void	get_date(t_date *date)
{
	time_t	now;
	struct tm *info_time;

	time(&now);
	info_time = localtime(&now);
	date->year = info_time->tm_year + 1900;
	date->month = info_time->tm_mon + 1;
	date->day = info_time->tm_mday;
}