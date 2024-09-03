int	mandelbrot_func(t_fractol *fract, double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (zr * zr + zi * zi < 4 && iter < fract->max_iterations)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

static void	ft_pixels(int x, int y, t_fractol *data)
{
	t_complex z;
   	t_complex c;
	int	i;
	int color;

	i = 0;
    z.x = (ft_scale_map(x, -2, +2, 0, WIDTH) * data->zoom) + data->shift_x;
	z.y = (ft_scale_map(y, +2, -2, 0, HEIGHT) * data->zoom) + data->shift_y;
	ft_mandelbrot_vs_julia(&z, &c, data);
	while(i < data->iterate_max)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_scale_map(i, BLACK, WHITE, 0, data->iterate_max);
			ft_mlx_pixel_put(&data, x, y, color);
			return ;
		}
		++i;
	}
	ft_mlx_pixel_put(&data, x, y, PASTEL_PURPLE);
}

static void	ft_pixels(int x, int y, t_fractol *data)
{
	t_complex z;
    t_complex c;
    double temp;
	int color;
	int i;

    z.x = 0;
    z.y = 0;
    c.x = (x / zoom) + data->x_min;
	c.y = (y / zoom) + data->y_min;
			temp = z.x;
        	z.x = (z.x * z.x) - (z.y * z.y) + c.x;
        	z.y = (2 * temp * z.y) + c.y;
}
