#include "fractol.h"

int main(int ac, char **av)
{
    t_fractol fractol;

    if (ac == 2 && !ft_strcmp(av[1], "Mandelbrot") || ac == 4 && !ft_strcmp(av[1], "Julia"))
    {
        fractol.name = av[1];
        fractol->julia_x = ft_atof(av[2]);
		fractol->julia_y = ft_atof(av[3]);
        ft_init_mlx(&fractol);
        ft_fractol(&fractol);
	    mlx_loop(fractol.mlx);
    }
    else
    {
        ft_putstr_fd("Please enter \n\t\" ./fractol Mandelbrot\" or \n\t\" ./fractol Julia <value1> <value2>\"\n",
			2);
		exit (EXIT_FAILURE);
    }
}
