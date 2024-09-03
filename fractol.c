#include "fractol.h"

double ft_scale_map(double num, double new_min, double old_min, double new_max, double old_max)
{
    return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}

void	ft_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + ((y * data->line_len) + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}

void	ft_mandelbrot_vs_julia(t_complex *z, t_complex *c, t_fractol *data)
{
	if (!ft_strcmp(data->name, "Julia"))
	{
		c->x = data->julia_x;
		c->y = data->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_pixels(int x, int y, t_fractol *data)
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

void ft_fractol(t_fractol *data)
{
	int x;
	int y;

	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixels(x, y, data);
        	x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image,
		0, 0);
}
