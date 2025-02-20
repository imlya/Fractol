/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:11:34 by imatek            #+#    #+#             */
/*   Updated: 2024/09/11 11:42:39 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0x800080
# define ORANGE 0xFFA500
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF

# define PASTEL_PINK 0xFFB6C1
# define PASTEL_BLUE 0xB0E0E6
# define PASTEL_GREEN 0x77FF77
# define PASTEL_YELLOW 0xFFFFE0
# define PASTEL_PURPLE 0xD8B2D1
# define PASTEL_ORANGE 0xFFC4A1
# define PASTEL_TEAL 0xA0D6D3
# define PASTEL_PEACH 0xFFDAB9
# define PASTEL_MINT 0x98FF98
# define PASTEL_LAVENDER 0xE6E6FA

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*window;
	void	*image;
	char	*pixels;
	int		bpp;
	int		line_len;
	int		endian;
	int		iterate_max;
	double	center_x;
	double	center_y;
	double	zoom;
	double	real;
	double	i;
}			t_fractol;

////				INIT				////
void		ft_init_data(t_fractol *data);
void		ft_init_mlx(t_fractol *data);
////				FRACTOL                ////
double		ft_scale_map(double num, double new_min, double new_max,
				double old_max);
void		ft_pixels(int x, int y, t_fractol *data);
void		ft_fractol(t_fractol *data);
////				EVENTS				////
int			ft_destroy(t_fractol *data);
int			ft_keyboard_hook(int keysym, t_fractol *data);
int			ft_mouse_hook(int button, int x, int y, t_fractol *data);
int			ft_mouse_julia(int x, int y, t_fractol *data);
void		ft_events_mlx(t_fractol *data);
////				MATH				////
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z, t_fractol *fractal);
void		ft_error_message(void);
#endif
