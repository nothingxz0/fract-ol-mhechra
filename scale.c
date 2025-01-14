/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:58:29 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/13 23:07:38 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

long double scale(long double value, long double oldmax, long double newmin, long double newmax)
{
	long double	scaled_value;

	scaled_value = ((newmax - newmin) * (value - 0)) / (oldmax - 0) + newmin;
	return (scaled_value);
}
