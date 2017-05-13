/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:42:59 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/26 18:45:21 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_iter_new(t_data *d)
{
	int		i;
	double	tmp;
	double	d_im;
	double	d_re;

	i = 0;
	tmp = 1.0;
	while (i < d->max_iter && tmp > 0.000001)
	{
		d->o_re = d->n_re;
		d->o_im = d->n_im;
		tmp = (ft_sum_kv(d->n_re, d->n_im) * ft_sum_kv(d->n_re, d->n_im));
		d->n_re = 2 * d->n_re * tmp + ft_raznost_kv(d->n_re, d->n_im);
		d->n_im = (2 * d->n_im * (tmp - d->o_re));
		d->n_re = d->n_re / (3 * tmp) + d->c_re;
		d->n_im = d->n_im / (3 * tmp) + d->c_im;
		d_im = d->n_im - d->o_im;
		d_re = d->n_re - d->o_re;
		tmp = d_re * d_re + d_im * d_im;
		i++;
	}
	i = ft_get_color(i, d);
	return (i);
}

void	*ft_newton(void *data)
{
	t_data	*d;
	int		i;

	d = *(t_data**)data;
	ft_step(d);
	d->y = -1;
	d->pi = d->min_y;
	while (++d->y < d->ht)
	{
		d->x = d->i;
		d->pr = d->min_x;
		i = -1;
		while (++i < d->i)
			d->pr += d->step_x;
		while (d->x < d->wd)
		{
			d->n_re = d->pr + d->c_re;
			d->n_im = d->pi + d->c_im;
			draw_pixel(*d, d->x, d->y, ft_iter_new(d));
			d->pr = d->pr + d->step_x * (double)8;
			d->x += 8;
		}
		d->pi += d->step_y;
	}
	pthread_exit(NULL);
}

void	ft_create_data_new(t_data **d, t_win w, int marker)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i] = (t_data*)malloc(sizeof(t_data));
		d[i]->marker = marker;
		d[i]->c_im = 0;
		d[i]->c_re = 0;
		d[i]->i = i;
		d[i]->ht = 800;
		d[i]->wd = 1000;
		d[i]->max_iter = 300;
		d[i]->mlx = w.mlx;
		d[i]->win = w.win;
		d[i]->img = w.img;
		d[i]->flag = 0;
		d[i]->max_x = 1;
		d[i]->max_y = 1;
		d[i]->min_x = -1;
		d[i]->min_y = -1;
		ft_set_color(d[i]);
	}
}

void	ft_create_newton(void)
{
	t_data	**d;
	t_win	w;
	int		marker;

	marker = N;
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1000, 800, "Newton");
	w.img = mlx_new_image(w.mlx, 1000, 800);
	d = (t_data **)malloc(sizeof(t_data *) * 8);
	ft_create_data_new(d, w, marker);
	ft_create_threads(d, marker);
}
