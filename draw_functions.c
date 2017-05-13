/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:51:11 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/26 18:51:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_pixel(t_data d, int x, int y, int c)
{
	int i;

	d.data = mlx_get_data_addr(d.img, &d.bpp, &d.size_l, &d.endian);
	if (x > 0 && x < 1000)
	{
		i = x * d.bpp / 8 + y * d.size_l;
		if (i < 800 * d.size_l && i >= 0)
		{
			d.data[i] = c;
			d.data[++i] = c >> 8;
			d.data[++i] = c >> 16;
		}
	}
}

void	ft_set_color(t_data *color)
{
	color->a = 0;
	color->r = 4;
	color->g = 2;
	color->b = 0;
}

int		ft_get_color(int i, t_data *wi)
{
	int		color;

	color = wi->a << 24 | wi->r << 16 |
			wi->g << 8 | wi->b << 0;
	i = i * color;
	return (i);
}
