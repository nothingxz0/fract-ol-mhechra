/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:32:09 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/13 15:25:58 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	print_usage(void)
{
	ft_printf("\033[1;36m┌─────────────────────────────────────┐\n");
	ft_printf("│        🎨 FRACTOL VISUALIZER        │\n");
	ft_printf("└─────────────────────────────────────┘\033[0m\n\n");
	ft_printf("\033[1;31m❌ Error: Invalid arguments\033[0m\n\n");
	ft_printf("\033[1;35m✧ AVAILABLE FRACTALS:\033[0m\n");
	ft_printf("──────────────────────────────────────\n\n");
	ft_printf("\033[1;33m1. Mandelbrot Set\033[0m\n");
	ft_printf("   Usage: \033[1;37m./fractol mandelbrot\033[0m\n");
	ft_printf("   → Explore the classic fractal set\n\n");
	ft_printf("\033[1;33m2. Julia Set\033[0m\n");
	ft_printf("   Usage: \033[1;37m./fractol julia <real> <imag>\033[0m\n");
	ft_printf("   Parameters:\n");
	ft_printf("   - real      : Real part [-2.0 to 2.0]\n");
	ft_printf("   - imag      : Imaginary part [-2.0 to 2.0]\n");
	ft_printf("   Example: \033[1;32m./fractol julia 0.285 0.01\033[0m\n\n");
	ft_printf("\033[1;34m✧ CONTROLS:\033[0m\n");
	ft_printf("──────────────────────────────────────\n");
	ft_printf("  Mouse Wheel : Zoom in/out\n");
	ft_printf("  ESC        : Exit program\n\n");
}

static int	check_mandelbrot(int ac, char *str)
{
	return (ft_strcmp(str, "mandelbrot") == 0 && ac == 2);
}

static int	check_julia(int ac, char *str)
{
	return (ft_strcmp(str, "julia") == 0 && ac == 4);
}

int scrole_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 5)
		fractol->zoom *= 1.02;
	else if (keycode == 4)
		fractol->zoom *= 0.95;
	render_fractol(fractol);
	return (0);
}

int	handler(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)param;
	if (keycode == 65307)
	{
		ft_printf ("exit ...");
		free_mlx(fractol);
		exit (1);
	}
	if (keycode == 114)
        fractol->color_r += 1;
	else if (keycode == 61)
		fractol->max_iter += 100;
    else if (keycode == 103)
        fractol->color_g += 1;
    else if (keycode == 98)
        fractol->color_b += 1;
	else if (keycode == 122)
    {
        fractol->color_r = 245;
        fractol->color_g = 245;
        fractol->color_b = 245;
    }
	else if (keycode == 65362)
		fractol->move_y += 0.5;// up 65362
	else if (keycode == 65364)
		fractol->move_y -= 0.5;// down == 65364
	else if (keycode == 65363)
		fractol->move_x += 0.5;// right 65363
	else if (keycode == 65361)
		fractol->move_x -= 0.5;// left == 65361
	render_fractol(fractol);
	return 0;
}

int	main(int ac, char **av)
{
	t_fractol fractol;

	if (ac < 2 || (!check_mandelbrot(ac, av[1])
		&& !check_julia(ac, av[1])))
		return (print_usage(), 1);
	init_frac(&fractol, av[1]);
	render_fractol(&fractol);
	mlx_mouse_hook(fractol.mlx_window, scrole_hook, &fractol);
	mlx_hook(fractol.mlx_window, 2, 1L<<0, handler, &fractol);
	mlx_loop(fractol.mlx_connection);
	return (0);
}
