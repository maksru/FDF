/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:38:46 by mrudyk            #+#    #+#             */
/*   Updated: 2017/11/23 20:38:58 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int nbr)
{
	int len;

	len = 1;
	if (nbr == -2147483648)
	{
		len++;
		nbr = nbr / 10;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
