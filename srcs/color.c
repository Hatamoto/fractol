/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:45 by mburakow          #+#    #+#             */
/*   Updated: 2024/03/19 14:29:47 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	add_color_value(char **start, char **ptr, t_fractal *f, int *rgb)
{
	if (**ptr == '\0')
		rgb[2] = 1;
	**ptr = '\0';
	f->color[rgb[0]] = ft_atoi(*start);
	if (++rgb[0] == 3)
	{
		f->colors[rgb[1]++] = get_rgba(f->color[0], f->color[1], f->color[2],
				255);
		f->colorcount = rgb[1];
		rgb[0] = 0;
	}
	*start = *ptr + 1;
	*ptr = *start;
}

// Parameter format: colors=255,255,255:25,25,112:204,85,0  maximum is 6 colors
// separated by ':'.
void	get_color_palette(int argc, char **argv, t_fractal *f)
{
	int		rgb[3];
	char	*start;
	char	*ptr;

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	ptr = NULL;
	if (!(ft_strncmp(argv[argc - 1], "color=", 6)))
	{
		start = ft_strchr(argv[argc - 1], '=') + 1;
		ptr = start;
		while (*start != '\0' && rgb[1] < 7)
		{
			ptr++;
			if (*ptr == ',' || *ptr == ':' || *ptr == '\0')
				add_color_value(&start, &ptr, f, rgb);
			if (rgb[2] == 1)
				break ;
		}
	}
	else
		msgexit();
}

static int	get_mid_color(int color1, int color2, double ratio)
{
	int	r;
	int	g;
	int	b;

	if (get_r(color1) > get_r(color2))
		r = (int)(get_r(color1) - ((get_r(color1) - get_r(color2)) * ratio));
	else
		r = (int)(get_r(color1) + ((get_r(color2) - get_r(color1)) * ratio));
	if (get_g(color1) > get_g(color2))
		g = (int)(get_g(color1) - ((get_g(color1) - get_g(color2)) * ratio));
	else
		g = (int)(get_g(color1) + ((get_g(color2) - get_g(color1)) * ratio));
	if (get_b(color1) > get_b(color2))
		b = (int)(get_b(color1) - ((get_b(color1) - get_b(color2)) * ratio));
	else
		b = (int)(get_b(color1) + ((get_b(color2) - get_b(color1)) * ratio));
	return (get_rgba(r, g, b, 255));
}

static int	get_color_ratio(t_fractal *f, int i, double sm_it, double carea)
{
	int	color;

	color = 0x000000;
	while (i <= f->colorcount && f->colorcount > 0 && f->smooth == 1)
	{
		if (sm_it < carea * i)
		{
			sm_it = (sm_it - (carea * (i - 1)));
			return (get_mid_color(f->colors[i - 1], f->colors[i], sm_it));
		}
		else if (sm_it > carea * (i) && sm_it < carea * (i + 1))
		{
			sm_it = (sm_it - (carea * (i))) / carea;
			return (get_mid_color(f->colors[i], f->colors[i + 1], sm_it));
		}
		else if (sm_it > carea * (f->colorcount - 1) && sm_it < carea
			* (f->colorcount))
		{
			sm_it = (sm_it - (carea * (f->colorcount - 1))) / carea;
			return (get_mid_color(f->colors[f->colorcount - 1],
					f->colors[f->colorcount], sm_it));
		}
		i++;
	}
	return (color);
}

// Smooth coloring algorithm.
// Ratio can sometimes go under the treshold for previous color.
int	get_smooth_color(t_fractal *f, int iterations)
{
	double	sm_it;
	int		i;
	double	carea;
	int		color;

	sm_it = (double)iterations - log(log(sqrt(f->z.x * f->z.x + f->z.y
					* f->z.y))) / log(2.0);
	carea = f->max_iterations / f->colorcount;
	i = 0;
	if (sm_it < 0.0)
		color = f->colors[0];
	else
		color = get_color_ratio(f, i, sm_it, carea);
	return (color);
}
