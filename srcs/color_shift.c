/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:51:55 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/19 19:08:07 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_active_color(t_fractal *f, int i)
{
	if (i >= 0 && i < f->colorcount)
		f->active_color = i;
}

static void	shift_color_down(t_fractal *f, int channel)
{
	int	rgb[3];

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	if (f->active_color >= 0 && f->active_color < f->colorcount)
	{
		if (channel == 4)
		{
			f->colors[f->active_color] = f->colors[f->active_color] >> 1;
			f->colors[f->active_color] = f->colors[f->active_color] & 0x7F7F7F;
			return ;
		}
		else
		{
			rgb[0] = get_r(f->colors[f->active_color]);
			rgb[1] = get_g(f->colors[f->active_color]);
			rgb[2] = get_b(f->colors[f->active_color]);
			rgb[channel] -= 10;
			if (rgb[channel] < 0)
				rgb[channel] = 0;
			f->colors[f->active_color] = get_rgba(rgb[0], rgb[1], rgb[2], 255);
		}
	}
}

static void	shift_color_up(t_fractal *f, int channel)
{
	int	rgb[3];

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	if (channel == 4)
	{
		if (f->active_color >= 0 && f->active_color < f->colorcount)
		{
			f->colors[f->active_color] = f->colors[f->active_color] << 1;
			f->colors[f->active_color] = f->colors[f->active_color] | 0x808080;
			return ;
		}
		else
		{
			rgb[0] = get_r(f->colors[f->active_color]);
			rgb[1] = get_g(f->colors[f->active_color]);
			rgb[2] = get_b(f->colors[f->active_color]);
			rgb[channel] += 10;
			if (rgb[channel] > 255)
				rgb[channel] = 255;
			f->colors[f->active_color] = get_rgba(rgb[0], rgb[1], rgb[2], 255);
		}
		return ;
	}
}

void	color_shift_hook(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_V))
		shift_color_up(f, 4);
	if (mlx_is_key_down(f->mlx, MLX_KEY_B))
		shift_color_down(f, 4);
	if (mlx_is_key_down(f->mlx, MLX_KEY_T))
		shift_color_up(f, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_G))
		shift_color_down(f, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_Y))
		shift_color_up(f, 1);
	if (mlx_is_key_down(f->mlx, MLX_KEY_H))
		shift_color_down(f, 1);
	if (mlx_is_key_down(f->mlx, MLX_KEY_U))
		shift_color_up(f, 2);
	if (mlx_is_key_down(f->mlx, MLX_KEY_J))
		shift_color_down(f, 2);
}

void	set_default_palette(t_fractal *f)
{
	if (f->colorcount == 0)
	{
		if (f->type == MANDELBROT)
		{
			f->colors[0] = 0x1632F0FF;
			f->colors[1] = 0x0CD2DCFF;
			f->colors[2] = 0x00FFBEFF;
			f->colorcount = 3;
		}
		else if (f->type == JULIA)
		{
			f->colors[0] = 0x002200FF;
			f->colors[1] = 0x7DF9FFFF;
			f->colors[2] = 0x7DF9FFFF;
			f->colorcount = 3;
		}
		else if (f->type == BURNINGSHIP)
		{
			f->colors[0] = 0x005779FF;
			f->colors[1] = 0xF3220CFF;
			f->colors[2] = 0xFEFE00FF;
			f->colorcount = 4;
		}
	}
}
