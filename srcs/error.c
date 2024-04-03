/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:32:07 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/18 16:02:15 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

// REMOVE THIS!

void	cleanexit(t_fractal *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->image);
	mlx_terminate(f->mlx);
	exit(0);
}

void	msgexit(void)
{
	ft_putendl_fd("Enter name of fractal: julia, mandel or ship.", 1);
	exit(0);
}

void	errexit(const char *error, t_fractal *f)
{
	mlx_close_window(f->mlx);
	mlx_delete_image(f->mlx, f->image);
	mlx_terminate(f->mlx);
	ft_putendl_fd(error, 2);
	exit(1);
}

void	print_parameters(t_fractal *f)
{
	int	i;

	if (f->type == MANDELBROT)
		ft_printf("Type: mandel\n");
	else if (f->type == JULIA)
	{
		ft_printf("Type: julia\n");
		ft_printf("c.x: ");
		ft_printf("%f\n", f->c.x);
		ft_printf("c.y: ");
		ft_printf("%f\n", f->c.y);
	}
	else if (f->type == BURNINGSHIP)
		ft_printf("Type: ship\n");
	ft_printf("Max_iter: %d\n", f->max_iterations);
	i = 0;
	while (i < f->colorcount)
	{
		ft_printf("Color %d hex  : %X\n", i, f->colors[i]);
		ft_printf("Color %d red  : %d\n", i, get_r(f->colors[i]));
		ft_printf("Color %d green: %d\n", i, get_g(f->colors[i]));
		ft_printf("Color %d blue : %d\n", i, get_b(f->colors[i]));
		i++;
	}
}
