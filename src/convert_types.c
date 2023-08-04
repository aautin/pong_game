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

	size = 0;
	while(number)
	{
		number = number / 10;
		size++;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	i = 0;
	while(i >= 0)
	{
		str[i] = number;
		i++;
	}
	return (str);
	// to be continued...
}