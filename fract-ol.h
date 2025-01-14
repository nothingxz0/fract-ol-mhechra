/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:25:20 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/15 00:31:37 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define HEIGHT 1000
# define WIDTH 1000
# define THREAD_COUNT 40

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h> 
# include <fcntl.h> 
# include <math.h>
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <pthread.h>

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
	void	*mlx_connection;
	void	*mlx_window;
	t_img	image;
	int		color_r;
    int		color_g;
    int		color_b;
	int		max_iter;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;


// complex numbers arent complex
typedef struct s_complex
{
	long double x;
	long double y;
}		t_complex;


// Utils
int			ft_strcmp(char *s1, char *s2);
void		init_frac(t_fractol *fractol, char *name);
void		free_mlx(t_fractol *fractol);
void		render_fractol(t_fractol *fractol);
void		my_pixel_put(t_img *img, int x, int y, int color);
long double scale(long double value, long double oldmax, long double newmin, long double newmax);
t_complex	sum_number(t_complex z1, t_complex z2);
t_complex	square_number(t_complex z);
void		ft_mandelbrot(int x, int y, t_fractol *fractol);
int			get_color(int iteration, t_fractol *fractol);
int			create_trgb(int t, int r, int g, int b);
void		ft_julia(int x, int y, t_fractol *fractol);
void		ft_burning_ship(int x, int y, t_fractol *fractol);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		check_error(char *str1, char *str2, int *flag);
void		assign_julia(t_fractol *fractol, char *julia_x, char *julia_y);
double		ft_atod(char *nptr);
void		print_usage(void);
int			handler(int keycode, t_fractol * fractol);
int 		scrole_hook(int keycode, int x, int y, t_fractol *fractol);
int			exit_free(t_fractol *fractol);
void		move_colors(t_fractol *fractol);
void		reset(t_fractol *fractol);

#endif