/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:53:39 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/17 18:56:20 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, t_mlx *mlx_lib)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
	{
		mlx_lib->rise *= 1.1;
		mlx_lib->set *= 1.2;
	}
	if (keycode == 78 && mlx_lib->set > 0)
	{
		mlx_lib->set *= 0.8;
		mlx_lib->rise *= 0.9;
	}
	if (keycode == 83 || keycode == 18)
		mlx_lib->value_z++;
	if (keycode == 84 || keycode == 19)
		mlx_lib->value_z -= 5;
	if (keycode == 86 || keycode == 21)
		mlx_lib->value_x++;
	if (keycode == 87 || keycode == 23)
		mlx_lib->value_x -= 5;
	if (keycode == 89 || keycode == 26)
		mlx_lib->value_y++;
	my_key_pt2(keycode, mlx_lib);
	return (END);
}

void	my_key_pt2(int keycode, t_mlx *mlx_lib)
{
	if (keycode == 91 || keycode == 28)
		mlx_lib->value_y -= 5;
	if (keycode == 67)
		mlx_lib->rise *= 1.1;
	if (keycode == 75)
		mlx_lib->rise *= 0.9;
	if (keycode == 126)
		mlx_lib->off_y -= 3;
	if (keycode == 125)
		mlx_lib->off_y += 3;
	if (keycode == 123)
		mlx_lib->off_x -= 3;
	if (keycode == 124)
		mlx_lib->off_x += 3;
	if (keycode == 4)
		mlx_lib->help = (mlx_lib->help == 0) ? 1 : 0;
	if (keycode == 1)
		mlx_lib->animation = (mlx_lib->animation == 0) ? 1 : 0;
	ft_draw_all(mlx_lib);
}
