/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:38:53 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/20 12:39:48 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "ft_printf.h"
# include "libft.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_rgbcolor
{
	int			r;
	int			g;
	int			b;
}				t_rgbcolor;

typedef enum e_ftype
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}				t_ftype;

// x, y are the pixel coordinates
// type is the fractal type
// zx, zy are the starting point or moving complex number
// cx, cy are the constant complex number
// zoom is the zoom level
typedef struct s_fractal
{
	int			x;
	int			y;
	t_ftype		type;
	t_complex	z;
	t_complex	c;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iterations;
	int			max_dimension;
	double		esc_radius;
	int			colors[7];
	int			color[3];
	int			colorcount;
	int			active_color;
	int			smooth;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_fractal;

void			cleanexit(t_fractal *f);
void			msgexit(void);
void			errexit(const char *error, t_fractal *f);
void			loophook(void *f);
void			scrollhook(double xdelta, double ydelta, void *vf);
void			keyhook(mlx_key_data_t keydata, void *vf);
void			drawhook(void *vf);
double			ft_atod(const char *str);
double			scale(double unscaled, double old_max, double new_min,
					double new_max);
void			calculate_offsets(t_fractal *fs);
double			get_offset_x_factor(t_fractal *f);
double			get_offset_y_factor(t_fractal *f);
void			zoom_in(t_fractal *f);
void			zoom_out(t_fractal *f);
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_square(t_complex a);
t_complex		complex_abs(t_complex a);
int				draw_fractal(t_fractal *f);
void			draw_mandelbrot(t_fractal *f);
void			draw_julia(t_fractal *f);
void			draw_burning_ship(t_fractal *f);
void			my_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
					uint32_t color);
int				get_r(int rgba);
int				get_g(int rgba);
int				get_b(int rgba);
int				get_a(int rgba);
int				get_rgba(int r, int g, int b, int a);
int				get_smooth_color(t_fractal *f, int i);
void			get_color_palette(int argc, char **argv, t_fractal *f);
void			set_default_palette(t_fractal *f);
void			set_active_color(t_fractal *f, int i);
void			color_shift_hook(t_fractal *f);
void			print_parameters(t_fractal *f);

#endif