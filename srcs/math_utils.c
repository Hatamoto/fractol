/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:53:56 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/20 13:37:14 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Scale the unscaled value from the old range (pixel size) to the new range
 * (origin in middle,
 * fit fractal on screen). Doesn't account for non-square window size.
 * [0..799] ... [-2..+2]
 */
double	scale(double unscaled, double old_max, double new_min, double new_max)
{
	double	old_min;

	old_min = 0.0;
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}

// X and Y ranges are 4.0 (2 -(-2)).
void	calculate_offsets(t_fractal *f)
{
	double	range;

	range = 4.0;
	if (WIDTH > HEIGHT)
		f->offset_y = ((double)HEIGHT / (double)WIDTH - 1.0) * range / 2;
	else if (HEIGHT > WIDTH)
		f->offset_x = ((double)WIDTH / (double)HEIGHT - 1.0) * range / -2;
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	complex_square(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	complex_abs(t_complex a)
{
	t_complex	c;

	c.x = fabs(a.x);
	c.y = fabs(a.y);
	return (c);
}
