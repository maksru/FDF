/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:44:11 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/17 18:46:36 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu_help(t_mlx *mlx_lib)
{
	if (mlx_lib->help == 0)
	{
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 0, 0x004DFF,
						"S - start | stop animation");
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 15, 0xFFFF00,
						"H - open | close help");
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 30, 0x004DFF,
						"Rotation: x -'4', '5' y - '7' '8' z - '1' '2'");
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 45, 0xFFFF00,
						"Change size + and - on numpad");
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 60, 0x004DFF,
						"Change bulk / and * on numpad");
		mlx_string_put(mlx_lib->mlx, mlx_lib->win, 10, 75, 0xFFFF00,
						"Arrows - change posotion");
	}
}
