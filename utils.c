/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:11:55 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 21:45:35 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*addr;
	
	offset = (y * img->line_len + x * (img->bits_per_pixel / 8));
	addr = img->addr + offset;
	*(unsigned int *)addr = color;	
}

void	move_colors(t_fractol *fractol)
{
	fractol->color_r += 1;
	fractol->color_g += 1;
	fractol->color_b += 1;
}

void	reset(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->max_iter = 50;
}