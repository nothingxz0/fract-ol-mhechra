/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:51:52 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/16 10:39:55 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_cursor(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	mouse_x;
	double	mouse_y;
	double	new_width;
	double	new_height;

	new_height = (fractol->y_max - fractol->y_min) * zoom_factor;
	new_width = (fractol->x_max - fractol->x_min) * zoom_factor;
	mouse_y = (y / (double)HEIGHT) * (fractol->y_max - fractol->y_min)
		+ fractol->y_min;
	mouse_x = (x / (double)WIDTH) * (fractol->x_max - fractol->x_min)
		+ fractol->x_min;
	fractol->x_min = mouse_x - (x / (double)WIDTH) * new_width;
	fractol->x_max = fractol->x_min + new_width;
	fractol->y_min = mouse_y - (y / (double)HEIGHT) * new_height;
	fractol->y_max = fractol->y_min + new_height;
}

int	scrole_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 5)
		zoom_cursor(fractol, x, y, 1.08);
	else if (keycode == 4)
		zoom_cursor(fractol, x, y, 0.92);
	render_fractol(fractol);
	return (0);
}

int	handler(int keycode, t_fractol *fractol)
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
