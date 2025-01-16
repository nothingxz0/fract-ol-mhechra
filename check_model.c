/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:26:09 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/15 20:12:46 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_model(t_fractol *fractol, int x, int y)
{
	if (!ft_strcmp(fractol->name, "mandelbrot"))
		ft_mandelbrot(x, y, fractol);
	else if(!ft_strcmp(fractol->name, "julia"))
		ft_julia(x, y, fractol);
	else if(!ft_strcmp(fractol->name, "burning ship"))
		ft_burning_ship(x, y, fractol);
}

typedef struct s_thread_data {
    t_fractol *fractol;
    int start_y;
    int end_y;
} t_thread_data;

void *render_thread(void *arg)
{
	t_thread_data *data = (t_thread_data *)arg;
	int x, y;	

	for (y = data->start_y; y < data->end_y; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
		    check_model(data->fractol, x, y);
		}
	}
	return NULL;
}

void render_fractol(t_fractol *fractol)
{
	pthread_t threads[THREAD_COUNT];
	t_thread_data thread_data[THREAD_COUNT];
	int chunk_size = HEIGHT / THREAD_COUNT;
	int i;	

	for (i = 0; i < THREAD_COUNT; i++)
	{
		thread_data[i].fractol = fractol;
		thread_data[i].start_y = i * chunk_size;
		thread_data[i].end_y = (i == THREAD_COUNT - 1) ? HEIGHT : (i + 1) * chunk_size;
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
	}	
	for (i = 0; i < THREAD_COUNT; i++)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, 
	                       fractol->image.img, 0, 0);
}