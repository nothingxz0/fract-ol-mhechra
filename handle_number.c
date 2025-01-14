/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:46:53 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 18:13:00 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	check_error(char *str1, char *str2, int *flag)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == '.' && str1[i + 1] == '.')
			*flag = -1;
		if ((str1[i] < '0' || str1[i] > '9') && str1[i] != '.'
			&& str1[i] != '-' && str1[i] != '+')
			*flag = -1;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (str2[i] == '.' && str2[i + 1] == '.')
			*flag = -1;
		if ((str2[i] < '0' || str2[i] > '9') && str2[i] != '.'
			&& str2[i] != '-' && str2[i] != '+')
			*flag = -1;
		i++;
	}
}

void	assign_julia(t_fractol *fractol, char *julia_x, char *julia_y)
{
	int		flag;
	double	julia_x_double;
	double	julia_y_double;

	flag = 1;
	check_error(julia_x, julia_y, &flag);
	if (flag == -1)
	{
		free_mlx(fractol);
		print_usage();
		exit(1);
	}
	julia_x_double = ft_atod(julia_x);
	julia_y_double = ft_atod(julia_y);
	fractol->julia_x = julia_x_double;
	fractol->julia_y = julia_y_double;
}