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

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "Mandelbrot")) || (ac == 4
			&& !ft_strcmp(av[1], "Julia")))
	{
		fractol.name = av[1];
		if (ac == 4 && !ft_strcmp(fractol.name, "Julia"))
		{
			fractol.julia_x = ft_atof(av[2]);
			fractol.julia_y = ft_atof(av[3]);
		}
		ft_init_mlx(&fractol);
		ft_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter \n\t\" ./fractol Mandelbrot\" or \n\t\" ./fractol Julia <value1> <value2>\"\n",
			2);
		exit(EXIT_FAILURE);
	}
	// return (0);
}
