#include "fractol.h"

static void	ft_init_data(t_fractol *data)
{
	data->iterate_max = 50;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->zoom = 1.0;
	// data->min_x = -2;
	// data->max_x = 2;
	// data->min_y = 2;
	// data->max_y = -2;
}

void	ft_init_mlx(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(1);
	}
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->window)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_window failed", 2);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_image failed", 2);
	}
	data->pixels = mlx_get_data_addr(data->image, &data->bpp, &data->line_len,
			&data->endian);
	ft_events_mlx(data);
	ft_init_data(data);
}

// FAIRE UN VALGRIND AVEC X ET ESC