/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:33 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/19 13:39:14 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	loophook_zoom(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_KP_ADD) || mlx_is_key_down(f->mlx,
			MLX_KEY_Z))
		zoom_in(f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_KP_SUBTRACT) || mlx_is_key_down(f->mlx,
			MLX_KEY_X))
		zoom_out(f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_1))
		set_active_color(f, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_2))
		set_active_color(f, 1);
	if (mlx_is_key_down(f->mlx, MLX_KEY_3))
		set_active_color(f, 2);
	if (mlx_is_key_down(f->mlx, MLX_KEY_4))
		set_active_color(f, 3);
	if (mlx_is_key_down(f->mlx, MLX_KEY_5))
		set_active_color(f, 4);
	if (mlx_is_key_down(f->mlx, MLX_KEY_6))
		set_active_color(f, 5);
	if (mlx_is_key_down(f->mlx, MLX_KEY_P))
		print_parameters(f);
	color_shift_hook(f);
}

static void	loophook_continued(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT) || mlx_is_key_down(f->mlx,
			MLX_KEY_A))
		f->offset_x -= 0.2 * f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(f->mlx,
			MLX_KEY_D))
		f->offset_x += 0.2 * f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_E))
		f->max_iterations += 10;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Q))
		f->max_iterations -= 10;
	if (mlx_is_key_down(f->mlx, MLX_KEY_R))
		f->esc_radius += 1.0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_F))
		f->esc_radius -= 1.0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_I) && f->type == JULIA)
		f->c.x += 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_K) && f->type == JULIA)
		f->c.x -= 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_O) && f->type == JULIA)
		f->c.y += 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_L) && f->type == JULIA)
		f->c.y -= 0.01;
}

void	loophook(void *vf)
{
	t_fractal	*f;

	f = (t_fractal *)vf;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		cleanexit(f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP) || mlx_is_key_down(f->mlx,
			MLX_KEY_W))
	{
		if (f->type == BURNINGSHIP)
			f->offset_y -= 0.2 * f->zoom;
		else
			f->offset_y += 0.2 * f->zoom;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN) || mlx_is_key_down(f->mlx,
			MLX_KEY_S))
	{
		if (f->type == BURNINGSHIP)
			f->offset_y += 0.2 * f->zoom;
		else
			f->offset_y -= 0.2 * f->zoom;
	}
	loophook_continued(f);
	loophook_zoom(f);
}

void	keyhook(mlx_key_data_t keydata, void *vf)
{
	t_fractal	*f;

	f = (t_fractal *)vf;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		if (f->smooth == 1)
			f->smooth = 0;
		else
			f->smooth = 1;
	}
}

void	scrollhook(double xdelta, double ydelta, void *vf)
{
	t_fractal	*f;

	f = vf;
	if (ydelta > 0)
		zoom_out(f);
	else if (ydelta < 0)
		zoom_in(f);
	if (xdelta < 0)
		;
}
