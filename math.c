#include "fractol.h"

t_complex ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex sum;

	sum.x = z1.x + z2.x;
    sum.y = z1.y + z2.y;
	return (sum);
}

t_complex ft_square_complex(t_complex z)
{
	t_complex square;

	square.x = (z.x * z.x) - (z.y * z.y);
    square.y = 2 * z.x * z.y;
	return (square);
}
