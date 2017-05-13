/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:57:36 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/27 14:45:35 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_string_put(t_data *d)
{
	mlx_string_put(d->mlx, d->win, 50, 50, 11674146, "MOVE:");
	mlx_string_put(d->mlx, d->win, 50, 70, 16777215, "arrows");
	mlx_string_put(d->mlx, d->win, 50, 90, 11674146, "ZOOM:");
	mlx_string_put(d->mlx, d->win, 50, 110, 16777215, "mouse scroll");
	mlx_string_put(d->mlx, d->win, 50, 130, 11674146, "CHANGE complex num:");
	mlx_string_put(d->mlx, d->win, 50, 150, 16777215, "E and move mouse");
	mlx_string_put(d->mlx, d->win, 50, 170, 11674146, "RESET:");
	mlx_string_put(d->mlx, d->win, 50, 190, 16777215, "space");
	mlx_string_put(d->mlx, d->win, 50, 210, 11674146, "COLOR:");
	mlx_string_put(d->mlx, d->win, 50, 230, 16777215, "R - Red");
	mlx_string_put(d->mlx, d->win, 50, 250, 16777215, "G - Green");
	mlx_string_put(d->mlx, d->win, 50, 270, 16777215, "B - Blue");
	mlx_string_put(d->mlx, d->win, 50, 290, 11674146, "EXIT:");
	mlx_string_put(d->mlx, d->win, 50, 310, 16777215, "esc");
}

double	ft_sum_kv(double a, double b)
{
	double res;

	res = a * a + b * b;
	return (res);
}

double	ft_raznost_kv(double a, double b)
{
	double res;

	res = a * a - b * b;
	return (res);
}

void	ft_scale(t_data **d, double x, double y, double mult)
{
	double	x_mult;
	double	y_mult;
	int		i;

	i = -1;
	x = d[0]->min_x + x * (d[0]->max_x - d[0]->min_x) / (1000 - 1);
	y = d[0]->min_y + y * (d[0]->max_y - d[0]->min_y) / (800 - 1);
	while (++i < 8)
	{
		x_mult = x * (1 - mult);
		y_mult = y * (1 - mult);
		d[i]->max_x = d[i]->max_x * mult + x_mult;
		d[i]->min_x = d[i]->min_x * mult + x_mult;
		d[i]->max_y = d[i]->max_y * mult + y_mult;
		d[i]->min_y = d[i]->min_y * mult + y_mult;
	}
}
