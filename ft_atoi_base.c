/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:34:21 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:10:43 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_base(char *str)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	if (str[0] == '0' && str[1] == 'x')
		i = 2;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			number = (number * 16) + (str[i] - 87);
		else if (str[i] >= 'A' && str[i] <= 'F')
			number = (number * 16) + (str[i] - 55);
		else if (str[i] >= '0' && str[i] <= '9')
			number = (number * 16) + (str[i] - 48);
		else
		{
			write(1, "Error color\n", 12);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (number);
}
