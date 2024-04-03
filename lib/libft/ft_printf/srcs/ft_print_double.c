/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:08:59 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/18 17:11:36 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints only about 10 decimals
static int	print_dec(double dnum)
{
	int	dec;
	int ret;

	ret = 0;
	while (dnum > 0.00000000001)
	{
		dnum *= 10;
		dec = (int)dnum;
		ret += ft_print_char('0' + dec);
		dnum -= dec;
	}
	return (ret);
}

int	check_small(double dnum)
{
	if (dnum >= 1 || dnum <= -1)
		return 0;
	else
		return 1;
}

int	ft_print_double_rec(double dnum, int z)
{
	double	ret;

	ret = 0.0;
	if (dnum < 0)
	{
		ret += ft_print_char('-');
		dnum *= -1;
		ret += ft_print_double_rec(dnum, z);
	}
	else if (dnum < 1)
	{
		if (z)
			ret += ft_print_char('0');
		ret += ft_print_char('.');
		ret += print_dec(dnum);
	}
	else if (dnum > 9)
	{
		ret += ft_print_double_rec((int)dnum / 10, z);
		ret += ft_print_double_rec((int)dnum % 10, z);
	}
	else
		ret += ft_print_char((int)dnum + 48);
	if (dnum >= 1)
		z = 1;
	return (ret);
}

int	ft_print_double(double dnum)
{
	int z;
	int ret;

	z = check_small(dnum);
	ret = ft_print_double_rec(dnum, z);
	return (ret);
}
