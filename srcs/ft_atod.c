/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:00 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/13 16:56:27 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

static int	check_off(unsigned long num, int neg, char str)
{
	if (num >= LONG_MAX / 10 && (num > LONG_MAX / 10 || (str - '0') > LONG_MAX
			% 10))
	{
		if (neg == 1)
			return (-1);
		else if (neg == -1)
			return (0);
	}
	return (1);
}

static double	get_decimal(double num, const char *str, int i)
{
	double	divider;

	divider = 10.0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num += (str[i] - 48) / divider;
		divider *= 10.0;
		i++;
	}
	return (num);
}

double	ft_atod(const char *str)
{
	int		i;
	int		neg;
	double	num;

	i = 0;
	neg = 1;
	num = 0.0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (check_off(num, neg, (char)str[i]) != 1)
			return (check_off(num, neg, (char)str[i]));
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (str[i++] == 46)
		num = get_decimal(num, str, i);
	return (num * neg);
}
