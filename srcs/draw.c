/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:24:02 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/20 12:40:42 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drawhook(void *vf)
{
	t_fractal	*f;

	f = vf;
	draw_fractal(f);
}

int	draw_fractal(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < WIDTH)
	{
		while (f->y < HEIGHT)
		{
			if (f->type == MANDELBROT)
				draw_mandelbrot(f);
			else if (f->type == JULIA)
				draw_julia(f);
			else if (f->type == BURNINGSHIP)
				draw_burning_ship(f);
			else
				msgexit();
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	if (mlx_image_to_window(f->mlx, f->image, 0, 0) == -1)
		errexit(mlx_strerror(mlx_errno), f);
	return (0);
}

/* For each pixel, we calculate the real and imaginary part
 * of the complex number.
 * The formula for this is f(Z) = Z^2 + C, where Z is the complex number
 * (previous result, startpoint 0, 0) and C is the pixel's coordinate.
 * We iterate this formula until the absolute value of Z is greater than 2
 * or the maximum number of iterations is reached.
 * If the absolute value of Z is greater than 2, we color the pixel
 * based on the number of iterations it took to reach this value.
 * If the maximum number of iterations is reached, we color the pixel black.
 * The color of the pixel is determined by the number of iterations it took
 * to reach the absolute value of Z greater than 2.
 * Zoom is set because Mandelbrot values diverge to infinity, so we
 * need to zoom in to see the fractal.
 * if i++ increment is used inside a condition, it is increased regardless
 * of whether condition evaluates to true or false!
 */
void	draw_mandelbrot(t_fractal *f)
{
	int		i;
	int32_t	color;

	i = 0;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = (scale(f->x, f->max_dimension, -2, +2) * f->zoom) + f->offset_x;
	f->c.y = (scale(f->y, f->max_dimension, +2, -2) * f->zoom) + f->offset_y;
	while (i < f->max_iterations)
	{
		f->z = complex_add(complex_square(f->z), f->c);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc_radius)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		color = 0x000000FF;
	else
		color = get_smooth_color(f, i);
	my_put_pixel(f->image, f->x, f->y, color);
}

// cool effect: if ((i == f->max_iterations) || f->z.x > 3.0 || f->z.y > 3.0))
void	draw_julia(t_fractal *f)
{
	int		i;
	int32_t	color;

	f->z.x = (scale(f->x, f->max_dimension, -2, +2) * f->zoom) + f->offset_x;
	f->z.y = (scale(f->y, f->max_dimension, +2, -2) * f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iterations)
	{
		f->z = complex_add(complex_square(f->z), f->c);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc_radius)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		color = 0x000000FF;
	else
		color = get_smooth_color(f, i);
	my_put_pixel(f->image, f->x, f->y, color);
}

// f->z = complex_add(complex_abs(complex_square(f->z)), f->c); exploding ship
void	draw_burning_ship(t_fractal *f)
{
	int		i;
	int32_t	color;

	i = 0;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = (scale(f->x, f->max_dimension, -2, +2) * f->zoom) + f->offset_x;
	f->c.y = (scale(f->y, f->max_dimension, -2, +2) * f->zoom) + f->offset_y;
	while (i < f->max_iterations)
	{
		f->z = complex_add(complex_square(complex_abs(f->z)), f->c);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) >= f->esc_radius)
			break ;
		i++;
	}
	if (i == f->max_iterations)
	{
		color = 0x000000FF;
	}
	else
		color = get_smooth_color(f, i);
	my_put_pixel(f->image, f->x, f->y, color);
}
