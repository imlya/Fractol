#include "fractol.h"

t_complex	ft_sum_complex(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.x = z.x + c.x;
	sum.y = z.y + c.y;
	return (sum);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return (square);
}
