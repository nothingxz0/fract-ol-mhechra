/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:52 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 21:45:54 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int scrole_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 5)
		fractol->zoom *= 1.05;
	else if (keycode == 4)
		fractol->zoom *= 0.90;
	render_fractol(fractol);
	return (0);
}

int	handler(int keycode, t_fractol * fractol)
{
	if (keycode == 65307)
		exit_free(fractol);
	else if (keycode == 61)
		fractol->max_iter += 10;
	else if (keycode == 45)
	{
		if (fractol->max_iter > 10)
			fractol->max_iter -= 10;
	}
	else if (keycode == 122)
		move_colors(fractol);
	else if (keycode == 114)
		reset(fractol);
	else if (keycode == 65362)
		fractol->move_y -= (0.5) * fractol->zoom;
	else if (keycode == 65364)
		fractol->move_y += (0.5) * fractol->zoom;
	else if (keycode == 65363)
		fractol->move_x += (0.5) * fractol->zoom;
	else if (keycode == 65361)
		fractol->move_x -= (0.5) * fractol->zoom;
	render_fractol(fractol);
	return (0);
}

int	exit_free(t_fractol *fractol)
{

	ft_printf ("exit ...");
	mlx_destroy_image(fractol->mlx_connection, fractol->image.img);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit (1);
	return (0);
}