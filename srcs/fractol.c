/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:34:38 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/20 12:40:37 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	init_new_mlx(t_fractal *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fractol - mburakow", true);
	if (!(f->mlx))
		errexit(mlx_strerror(mlx_errno), f);
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->image))
		errexit(mlx_strerror(mlx_errno), f);
}

static void	get_fractal_type(t_fractal *f, char **argv)
{
	if (ft_strncmp(argv[1], "mandel", 7) == 0)
		f->type = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		f->type = JULIA;
		f->c.x = ft_atod(argv[2]);
		f->c.y = ft_atod(argv[3]);
	}
	else if (ft_strncmp(argv[1], "ship", 5) == 0)
		f->type = BURNINGSHIP;
	else
		msgexit();
}

static void	init_new_f_struct(t_fractal *f, char **argv)
{
	f->x = 0;
	f->y = 0;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = 0.0;
	f->c.y = 0.0;
	if (WIDTH > HEIGHT)
		f->max_dimension = WIDTH;
	else
		f->max_dimension = HEIGHT;
	get_fractal_type(f, argv);
	set_default_palette(f);
	f->zoom = 1.0;
	f->offset_x = 0;
	f->offset_y = 0;
	calculate_offsets(f);
	f->max_iterations = 42;
	f->esc_radius = 4.0;
	f->active_color = 0;
	f->smooth = 1;
	init_new_mlx(f);
}

// Should add option to determine max iterations, maybe resolution too.
static void	check_param(int argc, char **argv, t_fractal *f)
{
	if (argc < 2)
		msgexit();
	if (argc >= 2)
	{
		if (!(ft_strncmp(argv[1], "julia", 6)))
		{
			if (argc == 5)
				get_color_palette(argc, argv, f);
			else if (argc == 4)
				set_default_palette(f);
			else
				msgexit();
		}
		else if (argc == 3)
			get_color_palette(argc, argv, f);
		else if (argc == 2)
			set_default_palette(f);
		else
			msgexit();
	}
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	check_param(argc, argv, &f);
	init_new_f_struct(&f, argv);
	draw_fractal(&f);
	mlx_scroll_hook(f.mlx, &scrollhook, &f);
	mlx_loop_hook(f.mlx, &loophook, &f);
	mlx_key_hook(f.mlx, &keyhook, &f);
	mlx_loop_hook(f.mlx, &drawhook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
