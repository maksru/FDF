/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:43:38 by mrudyk            #+#    #+#             */
/*   Updated: 2018/02/20 16:09:30 by mrudyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# define WIDTH 1600
# define HEIGHT 1200
# define ERROR -1
# define OK 1
# define END 0
# define BLUE 0
# define GREEN 1
# define RED 2
# define HC HEIGHT/2
# define WC WIDTH/2
# define PI_NUMBER 3.14159265359
# define SINUS(value) sin(value * PI_NUMBER / 180)
# define COSINUS(value) cos(value * PI_NUMBER / 180)

typedef	struct		s_point
{
	int				pos_x;
	int				pos_y;
	int				z;
	int				new_pos_x;
	int				new_pos_y;
	int				new_pos_z;
	int				color;
}					t_point;

typedef	struct		s_cord
{
	int				x_1;
	int				y_1;
	int				x_2;
	int				y_2;
	int				color_1;
	int				color_2;
}					t_cord;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;

	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error_2;

	int				off_x;
	int				off_y;

	int				map_x;
	int				map_y;

	int				value_x;
	int				value_y;
	int				value_z;
	char			*data;
	int				sl;
	int				bp;
	int				animation;
	int				help;
	float			set;
	double			rise;
	t_point			point[2000][2000];
}					t_mlx;

int					ft_atoi_base(char *str);
void				read_file(t_mlx *mlx_lib, int ac, char **av);
void				sum_x(t_mlx *mlx_lib, char *line);
void				write_pointer(t_mlx *mlx_lib, int i, char *strsplit);
void				int_mlx(t_mlx *mlx_lib);
int					output(void *out);
void				ft_drawing_line(t_cord cord, t_mlx *mlx_lib);
void				ft_drawing_lines_x(t_mlx *mlx_lib);
void				ft_drawing_lines_y(t_mlx *mlx_lib);
void				ft_set_middle(t_mlx *mlx_lib);
void				my_put_pixel(int x, int y, int color, t_mlx *mlx_lib);
void				ft_spin_axis_y(t_mlx *mlx_lib);
void				ft_spin_axis_x(t_mlx *mlx_lib);
void				ft_spin_axis_z(t_mlx *mlx_lib);
void				ft_size_figure(t_mlx *mlx_lib);
void				ft_scope(t_mlx *mlx_lib);
void				my_key_pt2(int keycode, t_mlx *mlx_lib);
int					my_key_funct(int keycode, t_mlx *mlx_lib);
int					ft_draw_all(t_mlx *mlx_lib);
void				ft_menu_help(t_mlx *mlx_lib);

#endif
