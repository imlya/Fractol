/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:47:56 by imatek            #+#    #+#             */
/*   Updated: 2024/09/09 13:24:12 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	int		len;
	double	res;
	double	fraction;

	len = 0;
	res = (double)ft_atoi(str);
	while (*str >= '0' && *str <= '9' && *str != '.')
		str++;
	if (*str == '.')
		str++;
	fraction = (double)ft_atoi(str);
	len = ft_strlen(str);
	while (len > 0)
	{
		fraction /= 10;
		len--;
	}
	if (res >= 0)
		return (res + fraction);
	else
		return (res + (-fraction));
}

// #include <stdio.h>

// int main()
// {
// 	printf("%f\n", ft_atof("1.5"));
// 	printf("%f\n", atof("1.5"));
// }
