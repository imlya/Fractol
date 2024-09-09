/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:11:47 by imatek            #+#    #+#             */
/*   Updated: 2024/09/09 11:53:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_sum_complex(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.x = z.x + c.x;
	sum.y = z.y + c.y;
	return (sum);
}

double	ft_abs(double nb)
{
	if (nb < 0.0)
		nb *= -1;
	return (nb);
}

t_complex	ft_square_complex(t_complex z, t_fractol *fractal)
{
	t_complex	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	if (!ft_strcmp("Burning bird", fractal->name))
		square.y = (-2) * (z.x) * ft_abs(z.y);
	else
		square.y = 2 * z.x * z.y;
	return (square);
}
