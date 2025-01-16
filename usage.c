/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:46:43 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/15 20:12:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
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
	ft_printf("\033[1;33m3. Burning Ship\033[0m\n");
	ft_printf("   Usage: \033[1;37m./fractol burning_ship\033[0m\n");
	ft_printf("   → Explore the fiery nautical fractal\n\n");
	ft_printf("\033[1;34m✧ CONTROLS:\033[0m\n");
	ft_printf("──────────────────────────────────────\n");
	ft_printf("  Mouse Wheel : Zoom in/out\n");
	ft_printf("  ESC        : Exit program\n\n");
}