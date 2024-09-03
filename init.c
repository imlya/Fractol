#include "fractol.h"

static void	ft_init_data(t_fractol *data)
{
	data->escape_value = 4;
	data->iterate_max = 42;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 1.0;
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

//FAIRE UN VALGRIND AVEC X ET ESC