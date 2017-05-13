/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:56:44 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/27 12:55:47 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_reset_burning(t_data **d)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i]->c_im = 0;
		d[i]->c_re = 0;
		d[i]->max_x = 1.6;
		d[i]->max_y = 1.8;
		d[i]->min_x = -2.8;
		d[i]->min_y = -1.8;
		ft_set_color(d[i]);
	}
}

void	ft_reset_man(t_data **d)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i]->c_im = 0;
		d[i]->c_re = 0;
		d[i]->min_x = -2.2;
		d[i]->min_y = -1.2;
		d[i]->max_x = 1;
		d[i]->max_y = 1.2;
		ft_set_color(d[i]);
	}
}

void	ft_reset_julia(t_data **d)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i]->c_im = 0.27015;
		d[i]->c_re = -0.7;
		d[i]->min_x = -1.5;
		d[i]->min_y = -1.2;
		d[i]->max_x = 1.5;
		d[i]->max_y = 1.2;
		ft_set_color(d[i]);
	}
}

void	ft_reset_newton(t_data **d)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i]->c_im = 0;
		d[i]->c_re = 0;
		d[i]->min_x = -1;
		d[i]->min_y = -1;
		d[i]->max_x = 1;
		d[i]->max_y = 1;
		ft_set_color(d[i]);
	}
}

void	ft_reset(t_data **fr)
{
	if (fr[0]->marker == M)
		ft_reset_man(fr);
	else if (fr[0]->marker == J)
		ft_reset_julia(fr);
	else if (fr[0]->marker == N)
		ft_reset_newton(fr);
	else if (fr[0]->marker == B)
		ft_reset_burning(fr);
	ft_create_threads(fr, fr[0]->marker);
}
