/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:45:19 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:16:21 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_spin_axis_x(t_mlx *mlx_lib)
{
	int		x;
	int		y;
	int		ty;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			ty = mlx_lib->point[x][y].new_pos_y;
			mlx_lib->point[x][y].new_pos_y = round(ty *
				COSINUS(mlx_lib->value_x) - mlx_lib->point[x][y].z *
				mlx_lib->rise * SINUS(mlx_lib->value_x));
			mlx_lib->point[x][y].new_pos_z = round(-ty *
				SINUS(mlx_lib->value_x) - mlx_lib->point[x][y].z *
				mlx_lib->rise * COSINUS(mlx_lib->value_x));
			y++;
		}
		x++;
	}
}

void	ft_spin_axis_y(t_mlx *mlx_lib)
{
	int		x;
	int		y;
	int		px;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			px = mlx_lib->point[x][y].new_pos_x;
			mlx_lib->point[x][y].new_pos_x =
				round(px * COSINUS(mlx_lib->value_y) +
				mlx_lib->point[x][y].new_pos_z * SINUS(mlx_lib->value_y));
			mlx_lib->point[x][y].new_pos_z =
				round(-px * SINUS(mlx_lib->value_y) +
				mlx_lib->point[x][y].new_pos_z * COSINUS(mlx_lib->value_y));
			y++;
		}
		x++;
	}
}

void	ft_spin_axis_z(t_mlx *mlx_lib)
{
	int		x;
	int		y;
	int		px;
	int		py;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			px = mlx_lib->point[x][y].new_pos_x;
			py = mlx_lib->point[x][y].new_pos_y;
			mlx_lib->point[x][y].new_pos_x =
				round(px * COSINUS(mlx_lib->value_z) - py *
				SINUS(mlx_lib->value_z));
			mlx_lib->point[x][y].new_pos_y =
				round(px * SINUS(mlx_lib->value_z) + py *
				COSINUS(mlx_lib->value_z));
			y++;
		}
		x++;
	}
}

void	ft_scope(t_mlx *mlx_lib)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			mlx_lib->point[x][y].new_pos_x =
				mlx_lib->point[x][y].pos_x * mlx_lib->set;
			mlx_lib->point[x][y].new_pos_y =
				mlx_lib->point[x][y].pos_y * mlx_lib->set;
			y++;
		}
		x++;
	}
}

void	ft_size_figure(t_mlx *mlx_lib)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			mlx_lib->point[x][y].new_pos_x -=
				((mlx_lib->map_x * mlx_lib->set) / 2);
			mlx_lib->point[x][y].new_pos_y -=
				((mlx_lib->map_y * mlx_lib->set) / 2);
			y++;
		}
		x++;
	}
}
