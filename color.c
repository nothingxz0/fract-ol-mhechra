/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:27:15 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/16 10:42:38 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//int	get_color(int iteration, t_fractol *fractol)
//{
//	static int	i;
//	int			r;
//	int			g;
//	int			b;

//	i = 1;
//	r = (iteration * fractol->color_r) % 256;
//	g = (iteration * fractol->color_g) % 256;
//	b = (iteration * fractol->color_b) % 256;
//	return (create_trgb(0, r, g, b));
//}

int	get_color(double smooth_iter, int max_iter, t_fractol *fractol)
{
	int	r;
	int	g;
	int	b;

	r = fractol->r * (9 * (1 - smooth_iter / max_iter)
			* pow(smooth_iter / max_iter, 3) * 255);
	g = fractol->g * (15 * pow(1 - smooth_iter / max_iter, 2)
			* pow(smooth_iter / max_iter, 2) * 255);
	b = fractol->b * (8.5 * pow(1 - smooth_iter / max_iter, 3)
			* smooth_iter / max_iter * 255);
	return (create_trgb(0, r, g, b));
}

int	burning_ship_color(double smooth_iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * pow(smooth_iter / max_iter, 0.5));
	g = (int)(200 * pow(smooth_iter / max_iter, 1.2));
	b = 0;
	return (create_trgb(0, r, g, b));
}
