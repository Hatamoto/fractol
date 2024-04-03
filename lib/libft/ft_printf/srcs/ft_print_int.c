/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:27:55 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/18 11:11:36 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int dec)
{
	int	ret;

	ret = 0;
	if (dec == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		ft_print_int(147483648);
		ret = 11;
	}
	else if (dec < 0)
	{
		ret += ft_print_char('-');
		dec *= -1;
		ret += ft_print_int(dec);
	}
	else if (dec > 9)
	{
		ret += ft_print_int(dec / 10);
		ret += ft_print_int(dec % 10);
	}
	else
		ret += ft_print_char(dec + 48);
	return (ret);
}
