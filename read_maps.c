/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:16:19 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:26:22 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_pointer(t_mlx *mlx_lib, int i, char *strsplit)
{
	mlx_lib->point[mlx_lib->map_y][i].pos_x = i;
	mlx_lib->point[mlx_lib->map_y][i].pos_y = mlx_lib->map_y;
	mlx_lib->point[mlx_lib->map_y][i].z = ft_atoi(strsplit);
	if (ft_strchr(strsplit, ','))
		mlx_lib->point[mlx_lib->map_y][i].color =
			ft_atoi_base(ft_strchr(strsplit, ',') + 1);
	else
		mlx_lib->point[mlx_lib->map_y][i].color = 0xFFFF00;
}

void	sum_x(t_mlx *mlx_lib, char *line)
{
	static int	x;
	char		**strsplit;
	int			i;

	i = 0;
	x = 0;
	strsplit = ft_strsplit(line, ' ');
	while (strsplit[i])
	{
		write_pointer(mlx_lib, i, strsplit[i]);
		i++;
	}
	if (i < x)
		x = i;
	else if (x == 0)
		x = i;
	mlx_lib->map_x = x;
	i = 0;
	while (strsplit[i])
	{
		free(strsplit[i]);
		i++;
	}
	free(strsplit);
}

void	read_file(t_mlx *mlx_lib, int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac < 2 || ac > 2)
		exit((int)(write(1, "Apply the source file!!!\n", 25)));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit((int)write(1, "ERROR\n", 6));
	mlx_lib->map_y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		sum_x(mlx_lib, line);
		mlx_lib->map_y++;
		free(line);
	}
	close(fd);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(write(1, "ERROR\n", 6));
}
