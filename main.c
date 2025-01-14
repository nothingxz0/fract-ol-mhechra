/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:32:09 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/14 21:29:04 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static int	check_double(int ac, char *str)
{
	
	return (ft_strcmp(str, "mandelbrot") == 0 && ac == 2
			|| ft_strcmp(str, "burning ship") == 0);
}

static int	check_julia(int ac, char *str)
{
	return (ft_strcmp(str, "julia") == 0 && ac == 4);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	
	if (ac < 2 || (!check_double(ac, av[1])
		&& !check_julia(ac, av[1])))
		return (print_usage(), 1);
	init_frac(&fractol, av[1]);
	if (!ft_strcmp(av[1], "julia"))
		assign_julia(&fractol, av[2], av[3]);
	render_fractol(&fractol);
	mlx_hook(fractol.mlx_window, 4, 1L<<2, scrole_hook, &fractol);
	mlx_hook(fractol.mlx_window, 2, 1L<<0, handler, &fractol);
	mlx_hook(fractol.mlx_window, 17, 1L<<17, exit_free, &fractol);
	mlx_loop(fractol.mlx_connection);
	return (0);
}
