/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:18:29 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/12 18:23:45 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_complex	sum_number(t_complex z1, t_complex z2)
{
	t_complex	total;

	total.x = z1.x + z2.x;
	total.y = z1.y + z2.y;
	return (total);
}

t_complex	square_number(t_complex z)
{
	t_complex	total;

	total.x = (z.x * z.x) - (z.y * z.y);
	total.y = 2 * z.y * z.x;
	return (total);
}