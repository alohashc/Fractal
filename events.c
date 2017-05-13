/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:52:08 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/26 18:56:06 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_mouse(int x, int y, t_data **d)
{
	double	re_factor;
	double	im_factor;
	int		i;

	i = -1;
	if (d[0]->flag == 1)
	{
		while (++i < 8)
		{
			re_factor = (d[i]->max_x - d[i]->min_x) / (1000 - 1);
			im_factor = (d[i]->max_y - d[i]->min_y) / (800 - 1);
			d[i]->c_re = d[i]->min_x + x * re_factor;
			d[i]->c_im = d[i]->max_y - y * im_factor;
		}
		ft_create_threads(d, d[0]->marker);
	}
	return (0);
}

int		ft_mouse_press(int button, int x, int y, t_data **d)
{
	if (button == 4)
	{
		ft_scale(d, x, y, 1.1);
		ft_create_threads(d, d[0]->marker);
	}
	else if (button == 5)
	{
		ft_scale(d, x, y, 0.9);
		ft_create_threads(d, d[0]->marker);
	}
	return (0);
}

void	ft_move(t_data **d, int keycode)
{
	int i;

	i = -1;
	if (keycode == 123 || keycode == 124)
		while (++i < 8)
		{
			d[i]->min_x -= keycode == 123 ? -0.2 : 0.2;
			d[i]->max_x -= keycode == 123 ? -0.2 : 0.2;
		}
	if (keycode == 125 || keycode == 126)
		while (++i < 8)
		{
			d[i]->min_y -= keycode == 125 ? 0.2 : -0.2;
			d[i]->max_y -= keycode == 125 ? 0.2 : -0.2;
		}
	ft_create_threads(d, d[0]->marker);
}

void	ft_color_palette(t_data **d, int keycode)
{
	int i;

	i = -1;
	if (keycode == 15)
	{
		while (++i < 8)
			d[i]->r += 1;
	}
	if (keycode == 5)
	{
		while (++i < 8)
			d[i]->g += 1;
	}
	if (keycode == 11)
	{
		while (++i < 8)
			d[i]->b += 1;
	}
	ft_create_threads(d, d[0]->marker);
}

int		ft_press_key(int keycode, t_data **d)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 14 && (*d)->flag == 0)
		(*d)->flag = 1;
	else if (keycode == 14 && (*d)->flag == 1)
		(*d)->flag = 0;
	else if (keycode == 49)
		ft_reset(d);
	else if (keycode == 123 || keycode == 124 ||
			keycode == 125 || keycode == 126)
		ft_move(d, keycode);
	else if (keycode == 15 || keycode == 5 || keycode == 11)
		ft_color_palette(d, keycode);
	return (0);
}
