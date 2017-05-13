/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:46:12 by alohashc          #+#    #+#             */
/*   Updated: 2017/03/26 18:50:21 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*ft_carpet(void *data)
{
	t_data *d;

	d = *(t_data**)data;
	d->y = -1;
	while (++d->y < d->ht)
	{
		d->x = d->i;
		while (d->x < d->wd)
		{
			if (!((d->x / (int)pow(d->c_re, 0)) % (int)d->c_re == 1 &&
					(d->y / (int)pow(d->c_re, 0)) % (int)d->c_re == 1) &&
				!((d->x / (int)pow(d->c_re, 1)) % (int)d->c_re == 1 &&
					(d->y / (int)pow(d->c_re, 1)) % (int)d->c_re == 1) &&
				!((d->x / (int)pow(d->c_re, 2)) % (int)d->c_re == 1 &&
					(d->y / (int)pow(d->c_re, 2)) % (int)d->c_re == 1) &&
				!((d->x / (int)pow(d->c_re, 3)) % (int)d->c_re == 1 &&
					(d->y / (int)pow(d->c_re, 3)) % (int)d->c_re == 1) &&
				!((d->x / (int)pow(d->c_re, 4)) % (int)d->c_re == 1 &&
					(d->y / (int)pow(d->c_re, 4)) % (int)d->c_re == 1))
				draw_pixel(*d, d->x, d->y, d->color);
			d->x += 8;
		}
	}
	pthread_exit(NULL);
}

void	ft_create_data_serp(t_data **d, t_win w, int marker)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		d[i] = (t_data*)malloc(sizeof(t_data));
		d[i]->marker = marker;
		d[i]->c_im = 0;
		d[i]->c_re = 3;
		d[i]->ht = 800;
		d[i]->wd = 1000;
		d[i]->i = i;
		d[i]->mlx = w.mlx;
		d[i]->win = w.win;
		d[i]->img = w.img;
		d[i]->color = 16777215;
		d[i]->flag = 0;
	}
}

void	ft_create_carpet(void)
{
	t_data		**d;
	t_win		w;
	int			marker;

	marker = S;
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1000, 800, "Serpinski");
	w.img = mlx_new_image(w.mlx, 1000, 800);
	d = (t_data**)malloc(sizeof(t_data*) * 8);
	ft_create_data_serp(d, w, marker);
	ft_create_threads(d, marker);
}
