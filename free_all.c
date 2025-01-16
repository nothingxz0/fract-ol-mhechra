/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:46:31 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/15 20:12:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_mlx(t_fractol *fractol)
{
	if (fractol->image.img)
		mlx_destroy_image(fractol->mlx_connection, fractol->image.img);
	if (fractol->mlx_window)
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	if (fractol->mlx_connection)
		mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
}