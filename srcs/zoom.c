/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:20 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/19 19:02:41 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_offset_x_factor(t_fractal *f)
{
	int32_t	mx;
	int32_t	my;
	double	moffset_x;

	mlx_get_mouse_pos(f->mlx, &mx, &my);
	if (my < 0 || my > HEIGHT || mx < 0 || mx > WIDTH)
		return (0.0);
	moffset_x = scale(mx, f->max_dimension, -2, +2) * f->zoom;
	return (moffset_x);
}

double	get_offset_y_factor(t_fractal *f)
{
	int32_t	mx;
	int32_t	my;
	double	moffset_y;

	mlx_get_mouse_pos(f->mlx, &mx, &my);
	if (my < 0 || my > HEIGHT || mx < 0 || mx > WIDTH)
		return (0.0);
	moffset_y = scale(my, f->max_dimension, +2, -2) * f->zoom;
	if (f->type == BURNINGSHIP)
		moffset_y *= -1;
	return (moffset_y);
}

void	zoom_in(t_fractal *f)
{
	double	offset_x_factor;
	double	offset_y_factor;

	offset_x_factor = get_offset_x_factor(f);
	offset_y_factor = get_offset_y_factor(f);
	if (offset_x_factor != 0 && offset_y_factor != 0)
	{
		f->offset_x += offset_x_factor;
		f->offset_y += offset_y_factor;
	}
	f->zoom *= 0.95;
	offset_x_factor = get_offset_x_factor(f);
	offset_y_factor = get_offset_y_factor(f);
	if (offset_x_factor != 0 && offset_y_factor != 0)
	{
		f->offset_x -= offset_x_factor;
		f->offset_y -= offset_y_factor;
	}
}

void	zoom_out(t_fractal *f)
{
	double	offset_x_factor;
	double	offset_y_factor;

	offset_x_factor = get_offset_x_factor(f);
	offset_y_factor = get_offset_y_factor(f);
	if (offset_x_factor != 0 && offset_y_factor != 0)
	{
		f->offset_x += offset_x_factor;
		f->offset_y += offset_y_factor;
	}
	f->zoom *= 1.05;
	offset_x_factor = get_offset_x_factor(f);
	offset_y_factor = get_offset_y_factor(f);
	if (offset_x_factor != 0 && offset_y_factor != 0)
	{
		f->offset_x -= offset_x_factor;
		f->offset_y -= offset_y_factor;
	}
}
