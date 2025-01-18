/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:40:32 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/17 21:29:13 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *nptr, int *flag)
{
	int		sign;
	int		i;
	long	integer_part;
	double	frac_part;
	double	pow;

	(1) && (i = 0, sign = 1, frac_part = 0, integer_part = 0, pow = 1);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i] == '-')
			sign *= -1;
	i++;
	if (!nptr[i])
		*flag = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '.')
		integer_part = integer_part * 10 + (nptr[i++] - 48);
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		pow /= 10;
		frac_part = frac_part + (nptr[i++] - 48) * pow;
	}
	return ((integer_part + frac_part) * sign);
}
