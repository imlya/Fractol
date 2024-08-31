#include "fractol.h"

int	ft_destroy(t_fractol *data)
{
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int ft_keyboard_hook(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
		ft_destroy(data);
	else if (keysym == XK_Left)
		data->shift_x += (0.5 * data->zoom);
	else if (keysym == XK_Right)
		data->shift_x -= (0.5 * data->zoom);
	else if (keysym == XK_Up)
		data->shift_y -= (0.5 * data->zoom);
	else if (keysym == XK_Down)
		data->shift_y += (0.5 * data->zoom);
	else if (keysym == XK_plus)
		data->iterate_max += 10;
	else if (keysym == XK_minus)
		data->iterate_max -= 10;
	ft_fractol(data);
	return (0);
}

int ft_mouse_hook(int button, t_fractol *data)
{
	if (button == Button5)
	{
		data->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		data->zoom *= 1.05;
	}
	ft_fractol(data);
	return (0);
}

int	ft_mouse_julia(int x, int y, t_fractol *data)
{
	if(!ft_strcmp(data->name, "Julia"))
	{
		data->julia_x = (ft_scale_map(x, -2, +2, 0, WIDTH) * data->zoom) + data->shift_x;
		data->julia_y = (ft_scale_map(y, +2, -2, 0, HEIGHT* data->zoom)) + data->shift_y;
		ft_fractol(data);
	}
	return (0);
}

static void	ft_events_mlx(t_fractol *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keyboard_hook, data);
	mlx_hook(data->window, ButtonPress, ButtonPressMask, ft_mouse_hook, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_julia, data);

}
