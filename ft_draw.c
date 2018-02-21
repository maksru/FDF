/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:44:01 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:12:39 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_put_pixel(int x, int y, int col, t_mlx *mlx_lib)
{
	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		mlx_lib->data[(x * (mlx_lib->bp / 8)) +
			(y * mlx_lib->sl) + BLUE] = col & 0x0000FF;
		mlx_lib->data[(x * (mlx_lib->bp / 8)) +
			(y * mlx_lib->sl) + GREEN] = (col >> 8) & 0x00FF;
		mlx_lib->data[(x * (mlx_lib->bp / 8)) +
			(y * mlx_lib->sl) + RED] = col >> 16;
	}
}

void	ft_draw_line(t_mlx *mlx_lib, t_cord cord)
{
	mlx_lib->delta_x = abs(cord.x_2 - cord.x_1);
	mlx_lib->delta_y = abs(cord.y_2 - cord.y_1);
	mlx_lib->sign_x = cord.x_1 < cord.x_2 ? 1 : -1;
	mlx_lib->sign_y = cord.y_1 < cord.y_2 ? 1 : -1;
	mlx_lib->error = mlx_lib->delta_x - mlx_lib->delta_y;
	my_put_pixel(cord.x_2, cord.y_2, 0x40E0D0, mlx_lib);
	while (cord.x_1 != cord.x_2 || cord.y_1 != cord.y_2)
	{
		my_put_pixel(cord.x_1, cord.y_1, cord.color_1, mlx_lib);
		mlx_lib->error_2 = mlx_lib->error * 2;
		if (mlx_lib->error_2 > -mlx_lib->delta_y)
		{
			mlx_lib->error -= mlx_lib->delta_y;
			cord.x_1 += mlx_lib->sign_x;
		}
		if (mlx_lib->error_2 < mlx_lib->delta_x)
		{
			mlx_lib->error += mlx_lib->delta_x;
			cord.y_1 += mlx_lib->sign_y;
		}
	}
}

void	ft_set_middle(t_mlx *mlx_lib)
{
	int x;
	int y;

	x = 0;
	while (x < mlx_lib->map_y)
	{
		y = 0;
		while (y < mlx_lib->map_x)
		{
			mlx_lib->point[x][y].new_pos_x += WC + mlx_lib->off_x;
			mlx_lib->point[x][y].new_pos_y += HC + mlx_lib->off_y;
			y++;
		}
		x++;
	}
}

void	ft_drawing_lines_x(t_mlx *mlx_lib)
{
	int		w;
	int		h;
	t_cord	cord;

	h = 0;
	while (h < mlx_lib->map_y)
	{
		w = 0;
		while (w < mlx_lib->map_x)
		{
			cord.x_1 = mlx_lib->point[h][w].new_pos_x;
			cord.y_1 = mlx_lib->point[h][w].new_pos_y;
			cord.color_1 = mlx_lib->point[h][w].color;
			if (w + 1 < mlx_lib->map_x)
			{
				cord.x_2 = mlx_lib->point[h][w + 1].new_pos_x;
				cord.y_2 = mlx_lib->point[h][w + 1].new_pos_y;
				cord.color_2 = mlx_lib->point[h][w + 1].color;
				ft_draw_line(mlx_lib, cord);
			}
			w++;
		}
		h++;
	}
}

void	ft_drawing_lines_y(t_mlx *mlx_lib)
{
	int		w;
	int		h;
	t_cord	cord;

	h = 0;
	while (h < mlx_lib->map_y)
	{
		w = 0;
		while (w < mlx_lib->map_x)
		{
			cord.x_1 = mlx_lib->point[h][w].new_pos_x;
			cord.y_1 = mlx_lib->point[h][w].new_pos_y;
			cord.color_1 = mlx_lib->point[h][w].color;
			if (h + 1 < mlx_lib->map_y)
			{
				cord.x_2 = mlx_lib->point[h + 1][w].new_pos_x;
				cord.y_2 = mlx_lib->point[h + 1][w].new_pos_y;
				cord.color_2 = mlx_lib->point[h + 1][w].color;
				ft_draw_line(mlx_lib, cord);
			}
			w++;
		}
		h++;
	}
}
