/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:27:15 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 15:17:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int iteration, t_fractol *fractol)
{
	static int	i;

	i = 1;
	int r = (iteration * fractol->color_r) % 256;
	int g = (iteration * fractol->color_g) % 256;
	int b = (iteration * fractol->color_b) % 256;
	return create_trgb(0, r, g, b);
}