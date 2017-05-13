/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:40:47 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/26 18:42:34 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_iter_bur(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_iter)
	{
		d->n_re = d->o_re * d->o_re - d->o_im * d->o_im + d->pr;
		d->n_im = 2 * fabs(d->o_re * d->o_im) + d->pi;
		d->o_re = d->n_re;
		d->o_im = d->n_im;
		if ((d->n_re * d->n_re + d->n_im * d->n_im) > 4)
			break ;
		i++;
	}
	i = ft_get_color(i, d);
	return (i);
}

void	*ft_burning(void *data)
{
	t_data	*d;
	int		i;

	d = *(t_data**)data;
	ft_step(d);
	d->y = -1;
	d->pi = d->min_y;
	while (++d->y < d->ht)
	{
		d->pr = d->min_x;
		d->x = d->i;
		i = -1;
		while (++i < d->i)
			d->pr += d->step_x;
		while (d->x < d->wd)
		{
			d->o_re = d->pr + d->c_re;
			d->o_im = d->pi + d->c_im;
			draw_pixel(*d, d->x, d->y, ft_iter_bur(d));
			d->pr = d->pr + d->step_x * (double)8;
			d->x = d->x + 8;
		}
		d->pi += d->step_y;
	}
	pthread_exit(NULL);
}

void	ft_create_data_bur(t_data **d, t_win w, int marker)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		d[i] = (t_data*)malloc(sizeof(t_data));
		d[i]->marker = marker;
		d[i]->c_im = 0;
		d[i]->c_re = 0;
		d[i]->max_x = 1.6;
		d[i]->max_y = 1.8;
		d[i]->min_x = -2.8;
		d[i]->min_y = -1.8;
		d[i]->ht = 800;
		d[i]->wd = 1000;
		d[i]->i = i;
		d[i]->max_iter = 300;
		d[i]->mlx = w.mlx;
		d[i]->win = w.win;
		d[i]->img = w.img;
		d[i]->flag = 0;
		ft_set_color(d[i]);
	}
}

void	ft_create_burning(void)
{
	t_data	**d;
	t_win	w;
	int		marker;

	marker = B;
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1000, 800, "Burningship");
	w.img = mlx_new_image(w.mlx, 1000, 800);
	d = (t_data **)malloc(sizeof(t_data *) * 8);
	ft_create_data_bur(d, w, marker);
	ft_create_threads(d, marker);
}
