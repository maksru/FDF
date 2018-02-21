/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:44:56 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/17 17:44:58 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		output(void *out)
{
	out = NULL;
	exit(OK);
}

int		main(int ac, char **av)
{
	t_mlx *mlx_lib;

	mlx_lib = malloc(sizeof(t_mlx));
	if (!mlx_lib)
		return (END);
	read_file(mlx_lib, ac, av);
	int_mlx(mlx_lib);
	mlx_hook(mlx_lib->win, 2, 5, my_key_funct, mlx_lib);
	mlx_loop_hook(mlx_lib->mlx, ft_draw_all, mlx_lib);
	mlx_hook(mlx_lib->win, 17, 1L << 17, output, &mlx_lib);
	mlx_loop(mlx_lib->mlx);
	free(mlx_lib);
	return (OK);
}
