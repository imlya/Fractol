/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:11:43 by imatek            #+#    #+#             */
/*   Updated: 2024/09/09 14:10:40 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_message(void)
{
	ft_putendl_fd("Please enter ", 2);
	ft_putendl_fd("\t./fractol Mandelbrot \n\t\tor", 2);
	ft_putendl_fd("\t./fractol \"Burning bird\"\n\t\tor", 2);
	ft_putendl_fd("\t./fractol Julia <value1> <value2>", 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.name = av[1];
	if ((ac == 2 && (!ft_strcmp(av[1], "Mandelbrot")
				|| !ft_strcmp("Burning bird", fractol.name))) || (ac == 4
			&& !ft_strcmp(av[1], "Julia")))
	{
		if (!ft_strcmp(fractol.name, "Julia"))
		{
			fractol.real = ft_atod(av[2]);
			fractol.i = ft_atod(av[3]);
		}
		ft_init_mlx(&fractol);
		ft_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_error_message();
	return (0);
}
