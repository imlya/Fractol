/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micmac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:11:52 by imatek            #+#    #+#             */
/*   Updated: 2024/09/06 12:13:49 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pixels(int x, int y, t_fractol *data)
{
	t_complex	c;
	int			i;
	int			color;
	int			dest;

	c.x = data->min_real + (x / (double)WIDTH) * (data->max_real
			- data->min_real) / data->zoom + data->center_x;
	c.y = data->min_imag + (y / (double)HEIGHT) * (data->max_imag
			- data->min_imag) / data->zoom + data->center_y;
	i = data->data_func(data, c.x, c.y);
	color = data->color_func(i, data);
	ft_mlx_pixel_put(&data, x, y, color);
}

// void	ft_pixels(int x, int y, t_fractol *data)
{
	t_complex	z;

	// t_complex	c;
	// int			i;
	// int			color;
	i = 0;
	z.x = (ft_scale_map(x, -2, +2, 0, WIDTH) * data->zoom) + data->center_x;
	z.y = (ft_scale_map(y, +2, -2, 0, HEIGHT) * data->zoom) + data->center_y;
	ft_mandelbrot_vs_julia(&z, &c, data);
	while (i < data->iterate_max)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_scale_map(i, BLACK, WHITE, 0, data->iterate_max);
			// ft_mlx_pixel_put(&data, x, y, color);
			return ;
		}
		++i;
	}
	ft_mlx_pixel_put(&data, x, y, PASTEL_PURPLE);
}

double	ft_scale_map(double num, double new_min, double old_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min)
		+ new_min);
}

c.x = data->min_real + (x / (double)WIDTH) * (data->max_real - data->min_real)
	/ data->zoom + data->center_x;