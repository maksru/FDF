/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispresent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:40:17 by mrudyk            #+#    #+#             */
/*   Updated: 2017/11/23 20:40:31 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ispresent(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
			s1++;
		s2++;
	}
	if (!*s1)
		return (1);
	else
		return (0);
}