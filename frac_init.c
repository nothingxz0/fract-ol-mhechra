/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:57:44 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/13 22:45:50 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	handle_malloc(void)
{
	perror("Error the this foking malloc\n");
	exit(EXIT_FAILURE);
}

static void	init_data(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	fractol->color_r = 7;
    fractol->color_g = 3;
    fractol->color_b = 5;
	fractol->max_iter = 50;
	fractol->move_x = 0;
	fractol->move_y = 0;
}

void	init_frac(t_fractol *fractol, char *name)
{
	fractol->name = name;
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		handle_malloc();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
										WIDTH, HEIGHT,
										fractol->name);
	fractol->image.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	fractol->image.addr = mlx_get_data_addr(fractol->image.img,
											&fractol->image.bits_per_pixel,
											&fractol->image.line_len,
											&fractol->image.endian);
	init_data(fractol);
}
