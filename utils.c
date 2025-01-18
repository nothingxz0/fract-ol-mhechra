/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:11:55 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/17 16:36:55 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	addr = img->addr;
	offset = (y * img->line_len + x * (img->bits_per_pixel / 8));
	addr = img->addr + offset;
	*(unsigned int *)addr = color;
}

static void	reset_init(int *i, t_fractol *fractol)
{
	fractol->r = 1;
	fractol->g = 1;
	fractol->b = 1;
	*i = 0;
}

void	move_colors(t_fractol *fractol)
{
	static int	i;

	if (i == 0)
	{
		fractol->r = 0;
		fractol->g = 1;
		fractol->b = 1;
		i++;
	}
	else if (i == 1)
	{
		fractol->r = 1;
		fractol->g = 0;
		fractol->b = 1;
		i++;
	}
	else if (i == 2)
	{
		fractol->r = 1;
		fractol->g = 1;
		fractol->b = 0;
		i++;
	}
	else if (i == 3)
		reset_init(&i, fractol);
}

void	reset(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->max_iter = 50;
	fractol->x_min = -2;
	fractol->x_max = 2;
	fractol->y_min = -2;
	fractol->y_max = 2;
}
