/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:24 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 18:56:47 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_mandelbrot(int x, int y, t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	
	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, WIDTH, -2, 2) * fractol->zoom + fractol->move_x);
	c.y = (scale(y, HEIGHT, -2, 2) * fractol->zoom + fractol->move_y);

	while (i < fractol->max_iter)
	{
		tmp.x = (z.x * z.x) - (z.y * z.y);
		tmp.y = 2 * z.x * z.y;
		z.x = tmp.x + c.x;
		z.y = tmp.y + c.y;
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
		my_pixel_put(&fractol->image, x, y, get_color(i, fractol) * i);
}

void	ft_julia(int x, int y, t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	
	i = 0;
	c.x = fractol->julia_x;
	c.y = fractol->julia_y;
	z.x = (scale(x, WIDTH, -2, 2) * fractol->zoom + fractol->move_x);
	z.y = (scale(y, HEIGHT, -2, 2) * fractol->zoom + fractol->move_y);

	while (i < fractol->max_iter)
	{
		tmp.x = (z.x * z.x) - (z.y * z.y);
		tmp.y = 2 * z.x * z.y;
		z.x = tmp.x + c.x;
		z.y = tmp.y + c.y;
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
		my_pixel_put(&fractol->image, x, y, get_color(i, fractol) * i);
}

void	ft_burning_ship(int x, int y, t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	
	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, WIDTH, -2, 2) * fractol->zoom + fractol->move_x);
	c.y = (scale(y, HEIGHT, -2, 2) * fractol->zoom + fractol->move_y);

	while (i < fractol->max_iter)
	{
		z.x = fabs((double)z.x);
		z.y = fabs((double)z.y);
		tmp.x = (z.x * z.x) - (z.y * z.y);
		tmp.y = 2 * z.x * z.y;
		z.x = tmp.x + c.x;
		z.y = tmp.y + c.y;
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		my_pixel_put(&fractol->image, x, y, create_trgb(0, 0, 0, 0));
	else
		my_pixel_put(&fractol->image, x, y, get_color(i, fractol) * i);
}