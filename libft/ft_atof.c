/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:47:56 by imatek            #+#    #+#             */
/*   Updated: 2024/08/15 13:39:03 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *nptr)
{
	int		i;
	double	res;
	double	fraction;
	int		sign;

	i = 0;
	res = 0.0;
	fraction = 0.1;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '.')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res + ((nptr[i] - 48) * fraction);
		fraction /= 10;
	}
	return (res * sign);
}
