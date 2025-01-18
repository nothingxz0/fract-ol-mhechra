/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:24 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/16 23:39:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(int x, int y, t_fractol *fractol)
{
	int (i);
	t_complex (c);
	t_complex (z);
	t_complex (tmp);
	double (smooth);
	(1) && (i = -1, z.x = 0, z.y = 0, tmp.x = 0, tmp.y = 0);
	c.x = (scale(x, WIDTH, fractol->x_min, fractol->x_max)
			* fractol->zoom + fractol->move_x);
	c.y = (scale(y, HEIGHT, fractol->y_min, fractol->y_max)
			* fractol->zoom + fractol->move_y);
	while (++i < fractol->max_iter)
	{
		(1) && (tmp.x = (z.x * z.x) - (z.y * z.y), tmp.y = 2 * z.y * z.x,
			z.x = tmp.x + c.x, z.y = tmp.y + c.y);
		if ((sqrt(z.x * z.x) + sqrt(z.y * z.y)) > 4.0)
			break ;
	}
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
	{
		smooth = i + 1 - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2.0);
		my_pixel_put(&fractol->image, x, y,
			get_color(smooth, fractol->max_iter, fractol));
	}
}

void	ft_julia(int x, int y, t_fractol *fractol)
{
	int (i);
	double (smooth);
	t_complex (tmp);
	t_complex (c);
	t_complex (z);
	(1) && (i = 0, (c.x = fractol->julia_x), (c.y = fractol->julia_y));
	z.x = (scale(x, WIDTH, fractol->x_min, fractol->x_max)
			* fractol->zoom + fractol->move_x);
	z.y = (scale(y, HEIGHT, fractol->y_min, fractol->y_max)
			* fractol->zoom + fractol->move_y);
	while (i < fractol->max_iter)
	{
		tmp.x = (z.x * z.x) - (z.y * z.y);
		tmp.y = 2 * z.x * z.y;
		(1) && (z.x = tmp.x + c.x, z.y = tmp.y + c.y);
		if ((sqrt(z.x * z.x) + sqrt(z.y * z.y)) > 4.0)
			break ;
		i++;
	}
	smooth = i + 1 - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2.0);
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
		my_pixel_put(&fractol->image, x, y,
			get_color(smooth, fractol->max_iter, fractol));
}

void	ft_burning_ship(int x, int y, t_fractol *fractol)
{
	int (i);
	double (smooth);
	t_complex (c);
	t_complex (z);
	t_complex (tmp);
	(1) && (i = 0, z.x = 0, z.y = 0);
	c.x = (scale(x, WIDTH, fractol->x_min, fractol->x_max)
			* fractol->zoom + fractol->move_x);
	c.y = (scale(y, HEIGHT, fractol->y_min, fractol->y_max)
			* fractol->zoom + fractol->move_y);
	while (i < fractol->max_iter)
	{
		(1) && (z.x = fabs((double)z.x), z.y = fabs((double)z.y));
		(1) && (tmp.x = (z.x * z.x) - (z.y * z.y), tmp.y = 2 * z.y * z.x,
			z.x = tmp.x + c.x, z.y = tmp.y + c.y);
		if ((sqrt(z.x * z.x) + sqrt(z.y * z.y)) > 4.0)
			break ;
		i++;
	}
	smooth = i + 1 - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2.0);
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
		my_pixel_put(&fractol->image, x, y,
			burning_ship_color(smooth, fractol->max_iter));
}
