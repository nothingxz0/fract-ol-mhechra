/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:02:24 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/13 15:22:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_color(int iteration, int max_iterations, t_fractol *fractol)
{
    int r = (iteration * fractol->color_r) % 256;
    int g = (iteration * fractol->color_g) % 256;
    int b = (iteration * fractol->color_b) % 256;
    return create_trgb(0, r, g, b);
}

//int get_color(int iterations, int max_iterations)
//{
//    double t = (double)iterations / (double)max_iterations;
//    int r = (int)(9 * (1 - t) * t * t * t * 255);
//    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//    return create_trgb(0, r, g, b);
//}



// z = z ^ 2 + c
void	ft_magic(int x, int y, t_fractol *fractol)
{
	int			i;
	t_complex	z;
	t_complex	c;
	//t_scale		scale;
	
	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, 0, WIDTH, -2, 2) * fractol->zoom + fractol->move_x);
	c.y = (scale(y, 0, HEIGHT, 2, -2) * fractol->zoom + fractol->move_y);

	while (i < fractol->max_iter)
	{
		z = sum_number(square_number(z), c);
		if (hypot(z.x, z.y) > 2.0)
		{
			int color = create_trgb(0, 252, 190, 17) * i;
			my_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		i++;
	}
	int black ;
	black = create_trgb(0, 0, 0, 0);
	my_pixel_put(&fractol->image, x, y, black);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_magic(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->image.img, 0, 0);
}