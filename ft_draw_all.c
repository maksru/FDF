/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:13:04 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:31:58 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_mlx(t_mlx *mlx_lib)
{
	int		end;

	mlx_lib->mlx = mlx_init();
	mlx_lib->win = mlx_new_window(mlx_lib->mlx, WIDTH, HEIGHT, "FDF");
	mlx_lib->img = mlx_new_image(mlx_lib->mlx, WIDTH, HEIGHT);
	mlx_lib->data = mlx_get_data_addr(mlx_lib->img, &(mlx_lib->bp),
			&(mlx_lib->sl), &(end));
	mlx_lib->set = 70;
	mlx_lib->value_x = 25;
	mlx_lib->value_y = 40;
	mlx_lib->value_z = 0;
	mlx_lib->off_x = 0;
	mlx_lib->off_y = 0;
	mlx_lib->rise = 1;
	mlx_lib->animation = 0;
	mlx_lib->help = 0;
}

int		ft_draw_all(t_mlx *mlx_lib)
{
	ft_scope(mlx_lib);
	ft_size_figure(mlx_lib);
	ft_spin_axis_x(mlx_lib);
	ft_spin_axis_y(mlx_lib);
	ft_spin_axis_z(mlx_lib);
	ft_set_middle(mlx_lib);
	ft_drawing_lines_x(mlx_lib);
	ft_drawing_lines_y(mlx_lib);
	if (mlx_lib->map_x == 1 && mlx_lib->map_y == 1)
		my_put_pixel(WC + mlx_lib->off_x,
				HC + mlx_lib->off_y, mlx_lib->point[0][0].color, mlx_lib);
	mlx_put_image_to_window(mlx_lib->mlx, mlx_lib->win, mlx_lib->img, 3, 3);
	mlx_destroy_image(mlx_lib->mlx, mlx_lib->img);
	mlx_lib->img = mlx_new_image(mlx_lib->mlx, WIDTH, HEIGHT);
	ft_menu_help(mlx_lib);
	if (mlx_lib->animation == 1)
		mlx_lib->value_y += 1;
	return (END);
}
