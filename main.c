/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:11:43 by imatek            #+#    #+#             */
/*   Updated: 2024/09/06 13:32:05 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error_message(void)
{
	ft_putstr_fd("Please enter \n\t\" ./fractol Mandelbrot\" or \n\t\" ./fractol Julia <value1> <value2>\"\n",
			2);
	exit(EXIT_FAILURE);
	// write(2, "Invalid parameters\n\nAvailable fractals and right formats :\n\n", 61);
	// write(2, "\"Mandelbrot\"\n", 14);
	// write(2, "\"Julia\" real_nb complex_nb\n", 28);
	// write(2, "\"Burning bird\"\n", 16);
	// write(2, "\"Burning bird julia\" real_nb complex_nb\n", 41);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "Mandelbrot")) || (ac == 4
			&& (!ft_strcmp(av[1], "Julia") || !ft_strcmp(fractol.name, "AUTRE"))))
	{
		fractol.name = av[1];
		if (!ft_strcmp(fractol.name, "Julia") || !ft_strcmp(fractol.name, "AUTRE"))
		{
			fractol.real = ft_atof(av[2]);
			fractol.i = ft_atof(av[3]);
		}
		ft_init_mlx(&fractol);
		ft_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_error_message();
	return (0);
}
