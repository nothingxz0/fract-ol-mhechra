/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:25:20 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/13 14:40:17 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define HEIGHT 800
# define WIDTH 800

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h> 
# include <fcntl.h> 
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

// image infos
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

//	grafical shit for mlx
typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window
	t_img	image; // this will have image data XD;
	int		color_r;
    int		color_g;
    int		color_b;
	int		max_iter;
	double	move_x;
	double	move_y;
	double	zoom;
}	t_fractol;


// complex numbers arent complex
typedef struct s_complex
{
	long double x;
	long double y;
}		t_complex;

//norm bruh
typedef struct s_scale
{
	long double	value;
	long double	oldmin;
	long double	oldmax;
	long double	newmin;
	long double	newmax;
}		t_scale;


// Utils
int		ft_strcmp(char *s1, char *s2);
void	init_frac(t_fractol *fractol, char *name);
void	free_mlx(t_fractol *fractol);
void	render_fractol(t_fractol *fractol);
void	my_pixel_put(t_img *img, int x, int y, int color);
long double scale(long double value, long double oldmin, long double oldmax, long double newmin, long double newmax);
t_complex	sum_number(t_complex z1, t_complex z2);
t_complex	square_number(t_complex z);
#endif